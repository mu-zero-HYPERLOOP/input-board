#include "canzero.h"
input_board_state __oe_state;
sdc_status __oe_sdc_status;
float __oe_position;
float __oe_velocity;
float __oe_acceleration;
uint16_t __oe_linear_encoder_count;
float __oe_track_length;
float __oe_bat24_voltage;
error_level __oe_error_level_bat24_under_voltage;
error_level_config __oe_error_level_config_bat24_under_voltage;
error_level __oe_error_level_bat24_over_voltage;
error_level_config __oe_error_level_config_bat24_over_voltage;
float __oe_bat24_current;
error_level __oe_error_level_bat24_over_current;
error_level_config __oe_error_level_config_bat24_over_current;
float __oe_link24_voltage;
error_level __oe_error_level_link24_under_voltage;
error_level_config __oe_error_level_config_link24_under_voltage;
error_level __oe_error_level_link24_over_voltage;
error_level_config __oe_error_level_config_link24_over_voltage;
float __oe_link24_current;
error_level __oe_error_level_link24_over_current;
error_level_config __oe_error_level_config_link24_over_current;
float __oe_link45_voltage;
bool_t __oe_link45_expect_online;
error_level __oe_error_level_link45_under_voltage;
error_level_config __oe_error_level_config_link45_under_voltage;
error_level __oe_error_level_link45_over_voltage;
error_level_config __oe_error_level_config_link45_over_voltage;
float __oe_link45_current;
error_level __oe_error_level_link45_over_current;
error_level_config __oe_error_level_config_link45_over_current;
float __oe_cooling_cycle_pressure;
error_level __oe_error_level_cooling_cycle_under_pressure;
error_level_config __oe_error_level_config_cooling_cycle_under_pressure;
error_level __oe_error_level_cooling_cycle_over_pressure;
error_level_config __oe_error_level_config_cooling_cycle_over_pressure;
float __oe_mcu_temperature;
error_level __oe_error_level_mcu_temperature;
error_level_config __oe_error_level_config_mcu_temperature;
float __oe_cooling_cycle_temperature;
error_level __oe_error_level_cooling_cycle_temperature;
error_level_config __oe_error_level_config_cooling_temperature;
float __oe_bat24_temperature;
error_level __oe_error_level_bat24_temperature;
error_level_config __oe_error_level_config_bat24_temperature;
float __oe_supercap_temperature;
error_level __oe_error_level_supercap_temperature;
error_level_config __oe_error_level_config_supercap_temperature;
float __oe_buck_temperature;
error_level __oe_error_level_buck_temperature;
error_level_config __oe_error_level_config_buck_temperature;
float __oe_ebox_temperature;
error_level __oe_error_level_ebox_temperature;
error_level_config __oe_error_level_config_ebox_temperature;
float __oe_ambient_temperature;
error_level __oe_error_level_ambient_temperature;
error_level_config __oe_error_level_config_ambient_temperature;
error_flag __oe_assertion_fault;

typedef enum {
  HEARTBEAT_JOB_TAG = 0,
  GET_RESP_FRAGMENTATION_JOB_TAG = 1,
  STREAM_INTERVAL_JOB_TAG = 2,
} job_tag;
typedef struct {
  uint32_t *buffer;
  uint8_t offset;
  uint8_t size;
  uint8_t od_index;
  uint8_t server_id;
} get_resp_fragmentation_job;
typedef struct {
  uint32_t command_resp_msg_id;
  uint8_t bus_id;
} command_resp_timeout_job;
typedef struct {
  uint32_t last_schedule; 
  uint32_t stream_id;
} stream_interval_job;
typedef struct {
  uint32_t climax;
  uint32_t position;
  job_tag tag;
  union {
    get_resp_fragmentation_job get_fragmentation_job;
    stream_interval_job stream_job;
  } job;
} job_t;
union job_pool_allocator_entry {
  job_t job;
  union job_pool_allocator_entry *next;
};
typedef struct {
  union job_pool_allocator_entry job[64];
  union job_pool_allocator_entry *freelist;
} job_pool_allocator;
static job_pool_allocator job_allocator;
static void job_pool_allocator_init() {
  for (uint8_t i = 1; i < 64; i++) {
    job_allocator.job[i - 1].next = job_allocator.job + i;
  }
  job_allocator.job[64 - 1].next = NULL;
  job_allocator.freelist = job_allocator.job;
}
static job_t *job_pool_allocator_alloc() {
  if (job_allocator.freelist != NULL) {
    job_t *job = &job_allocator.freelist->job;
    job_allocator.freelist = job_allocator.freelist->next;
    return job;
  } else {
    return NULL;
  }
}
static void job_pool_allocator_free(job_t *job) {
  union job_pool_allocator_entry *entry = (union job_pool_allocator_entry *)job;
  entry->next = job_allocator.freelist;
  job_allocator.freelist = entry;
}
#define SCHEDULE_HEAP_SIZE 256
typedef struct {
  job_t *heap[SCHEDULE_HEAP_SIZE]; // job**
  uint32_t size;
} job_scheduler_t;
static job_scheduler_t scheduler;
static void scheduler_promote_job(job_t *job) {
  int index = job->position;
  if (index == 0) {
    return;
  }
  int parent = (job->position - 1) / 2;
  while (scheduler.heap[parent]->climax > scheduler.heap[index]->climax) {
    job_t *tmp = scheduler.heap[parent];
    scheduler.heap[parent] = scheduler.heap[index];
    scheduler.heap[index] = tmp;
    scheduler.heap[parent]->position = parent;
    scheduler.heap[index]->position = index;
    index = parent;
    parent = (index - 1) / 2;
  }
  if (index == 0) {
    canzero_request_update(job->climax);
  }
}
static void scheduler_schedule(job_t *job) {
  if (scheduler.size >= SCHEDULE_HEAP_SIZE) {
    return;
  }
  job->position = scheduler.size;
  scheduler.heap[scheduler.size] = job;
  scheduler.size += 1;
  scheduler_promote_job(job);
}
static int scheduler_continue(job_t **job, uint32_t time) {
  *job = scheduler.heap[0];
  return scheduler.heap[0]->climax <= time;
}
static void scheduler_reschedule(uint32_t climax) {
  job_t *job = scheduler.heap[0];
  job->climax = climax;
  int index = 0;
  int hsize = scheduler.size / 2;
  while (index < hsize) {
    int left = index * 2 + 1;
    int right = left + 1;
    int min;
    if (right < scheduler.size &&
        scheduler.heap[left]->climax >= scheduler.heap[right]->climax) {
      min = right;
    } else {
    min = left;
    }
    if (climax <= scheduler.heap[min]->climax) {
      break;
    }
    scheduler.heap[index] = scheduler.heap[min];
    scheduler.heap[index]->position = index;
    index = min;
  }
  scheduler.heap[index] = job;
  scheduler.heap[index]->position = index;
}
static void scheduler_unschedule() {
  scheduler.heap[0] = scheduler.heap[scheduler.size - 1];
  scheduler.heap[0]->position = 0;
  scheduler.size -= 1;
  scheduler_reschedule(scheduler.heap[0]->climax);
}
static const uint32_t get_resp_fragmentation_interval = 10;
static void schedule_get_resp_fragmentation_job(uint32_t *fragmentation_buffer, uint8_t size, uint8_t od_index, uint8_t server_id) {
  job_t *fragmentation_job = job_pool_allocator_alloc();
  fragmentation_job->climax = canzero_get_time() + get_resp_fragmentation_interval;
  fragmentation_job->tag = GET_RESP_FRAGMENTATION_JOB_TAG;
  fragmentation_job->job.get_fragmentation_job.buffer = fragmentation_buffer;
  fragmentation_job->job.get_fragmentation_job.offset = 1;
  fragmentation_job->job.get_fragmentation_job.size = size;
  fragmentation_job->job.get_fragmentation_job.od_index = od_index;
  fragmentation_job->job.get_fragmentation_job.server_id = server_id;
  scheduler_schedule(fragmentation_job);
}
static job_t heartbeat_job;
static const uint32_t heartbeat_interval = 100;
static void schedule_heartbeat_job() {
  heartbeat_job.climax = canzero_get_time() + heartbeat_interval;
  heartbeat_job.tag = HEARTBEAT_JOB_TAG;
  scheduler_schedule(&heartbeat_job);
}
static job_t state_interval_job;
static const uint32_t state_interval = 0;
static void schedule_state_interval_job(){
  uint32_t time = canzero_get_time();
  state_interval_job.climax = time + state_interval;
  state_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  state_interval_job.job.stream_job.stream_id = 0;
  state_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&state_interval_job);
}
static job_t position_estimation_interval_job;
static const uint32_t position_estimation_interval = 50;
static void schedule_position_estimation_interval_job(){
  uint32_t time = canzero_get_time();
  position_estimation_interval_job.climax = time + position_estimation_interval;
  position_estimation_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  position_estimation_interval_job.job.stream_job.stream_id = 1;
  position_estimation_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&position_estimation_interval_job);
}
static job_t bat24_interval_job;
static const uint32_t bat24_interval = 100;
static void schedule_bat24_interval_job(){
  uint32_t time = canzero_get_time();
  bat24_interval_job.climax = time + bat24_interval;
  bat24_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  bat24_interval_job.job.stream_job.stream_id = 2;
  bat24_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&bat24_interval_job);
}
static job_t link24_interval_job;
static const uint32_t link24_interval = 100;
static void schedule_link24_interval_job(){
  uint32_t time = canzero_get_time();
  link24_interval_job.climax = time + link24_interval;
  link24_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  link24_interval_job.job.stream_job.stream_id = 3;
  link24_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&link24_interval_job);
}
static job_t link45_interval_job;
static const uint32_t link45_interval = 100;
static void schedule_link45_interval_job(){
  uint32_t time = canzero_get_time();
  link45_interval_job.climax = time + link45_interval;
  link45_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  link45_interval_job.job.stream_job.stream_id = 4;
  link45_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&link45_interval_job);
}
static job_t cooling_interval_job;
static const uint32_t cooling_interval = 500;
static void schedule_cooling_interval_job(){
  uint32_t time = canzero_get_time();
  cooling_interval_job.climax = time + cooling_interval;
  cooling_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  cooling_interval_job.job.stream_job.stream_id = 5;
  cooling_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&cooling_interval_job);
}
static job_t temperatures_interval_job;
static const uint32_t temperatures_interval = 500;
static void schedule_temperatures_interval_job(){
  uint32_t time = canzero_get_time();
  temperatures_interval_job.climax = time + temperatures_interval;
  temperatures_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  temperatures_interval_job.job.stream_job.stream_id = 6;
  temperatures_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&temperatures_interval_job);
}
static job_t errors_interval_job;
static const uint32_t errors_interval = 0;
static void schedule_errors_interval_job(){
  uint32_t time = canzero_get_time();
  errors_interval_job.climax = time + errors_interval;
  errors_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  errors_interval_job.job.stream_job.stream_id = 7;
  errors_interval_job.job.stream_job.last_schedule = time;
  scheduler_schedule(&errors_interval_job);
}

static void schedule_jobs(uint32_t time) {
  for (uint8_t i = 0; i < 100; ++i) {
    canzero_enter_critical();
    job_t *job;
    if (!scheduler_continue(&job, time)) {
      canzero_exit_critical();
      return;
    }
    switch (job->tag) {
    case STREAM_INTERVAL_JOB_TAG: {
      switch (job->job.stream_job.stream_id) {
      case 0: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 500);
        canzero_exit_critical();
        canzero_message_input_board_stream_state stream_message;
        stream_message.m_state = __oe_state;
        stream_message.m_sdc_status = __oe_sdc_status;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_state(&stream_message, &stream_frame);
        canzero_can1_send(&stream_frame);
        break;
      }
      case 1: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 50);
        canzero_exit_critical();
        canzero_message_input_board_stream_position_estimation stream_message;
        stream_message.m_position = __oe_position;
        stream_message.m_velocity = __oe_velocity;
        stream_message.m_acceleration = __oe_acceleration;
        stream_message.m_linear_encoder_count = __oe_linear_encoder_count;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_position_estimation(&stream_message, &stream_frame);
        canzero_can0_send(&stream_frame);
        break;
      }
      case 2: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 100);
        canzero_exit_critical();
        canzero_message_input_board_stream_bat24 stream_message;
        stream_message.m_bat24_voltage = __oe_bat24_voltage;
        stream_message.m_bat24_current = __oe_bat24_current;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_bat24(&stream_message, &stream_frame);
        canzero_can1_send(&stream_frame);
        break;
      }
      case 3: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 100);
        canzero_exit_critical();
        canzero_message_input_board_stream_link24 stream_message;
        stream_message.m_link24_voltage = __oe_link24_voltage;
        stream_message.m_link24_current = __oe_link24_current;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_link24(&stream_message, &stream_frame);
        canzero_can0_send(&stream_frame);
        break;
      }
      case 4: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 100);
        canzero_exit_critical();
        canzero_message_input_board_stream_link45 stream_message;
        stream_message.m_link45_voltage = __oe_link45_voltage;
        stream_message.m_link45_current = __oe_link45_current;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_link45(&stream_message, &stream_frame);
        canzero_can1_send(&stream_frame);
        break;
      }
      case 5: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 500);
        canzero_exit_critical();
        canzero_message_input_board_stream_cooling stream_message;
        stream_message.m_cooling_cycle_pressure = __oe_cooling_cycle_pressure;
        stream_message.m_cooling_cycle_temperature = __oe_cooling_cycle_temperature;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_cooling(&stream_message, &stream_frame);
        canzero_can0_send(&stream_frame);
        break;
      }
      case 6: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 500);
        canzero_exit_critical();
        canzero_message_input_board_stream_temperatures stream_message;
        stream_message.m_mcu_temperature = __oe_mcu_temperature;
        stream_message.m_bat24_temperature = __oe_bat24_temperature;
        stream_message.m_supercap_temperature = __oe_supercap_temperature;
        stream_message.m_buck_temperature = __oe_buck_temperature;
        stream_message.m_ebox_temperature = __oe_ebox_temperature;
        stream_message.m_ambient_temperature = __oe_ambient_temperature;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_temperatures(&stream_message, &stream_frame);
        canzero_can1_send(&stream_frame);
        break;
      }
      case 7: {
        job->job.stream_job.last_schedule = time;
        scheduler_reschedule(time + 1000);
        canzero_exit_critical();
        canzero_message_input_board_stream_errors stream_message;
        stream_message.m_error_level_bat24_under_voltage = __oe_error_level_bat24_under_voltage;
        stream_message.m_error_level_bat24_over_voltage = __oe_error_level_bat24_over_voltage;
        stream_message.m_error_level_bat24_over_current = __oe_error_level_bat24_over_current;
        stream_message.m_error_level_link24_under_voltage = __oe_error_level_link24_under_voltage;
        stream_message.m_error_level_link24_over_voltage = __oe_error_level_link24_over_voltage;
        stream_message.m_error_level_link24_over_current = __oe_error_level_link24_over_current;
        stream_message.m_error_level_link45_under_voltage = __oe_error_level_link45_under_voltage;
        stream_message.m_error_level_link45_over_voltage = __oe_error_level_link45_over_voltage;
        stream_message.m_error_level_link45_over_current = __oe_error_level_link45_over_current;
        stream_message.m_error_level_cooling_cycle_under_pressure = __oe_error_level_cooling_cycle_under_pressure;
        stream_message.m_error_level_cooling_cycle_over_pressure = __oe_error_level_cooling_cycle_over_pressure;
        stream_message.m_error_level_mcu_temperature = __oe_error_level_mcu_temperature;
        stream_message.m_error_level_cooling_cycle_temperature = __oe_error_level_cooling_cycle_temperature;
        stream_message.m_error_level_bat24_temperature = __oe_error_level_bat24_temperature;
        stream_message.m_error_level_supercap_temperature = __oe_error_level_supercap_temperature;
        stream_message.m_error_level_buck_temperature = __oe_error_level_buck_temperature;
        stream_message.m_error_level_ebox_temperature = __oe_error_level_ebox_temperature;
        stream_message.m_error_level_ambient_temperature = __oe_error_level_ambient_temperature;
        stream_message.m_assertion_fault = __oe_assertion_fault;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_errors(&stream_message, &stream_frame);
        canzero_can1_send(&stream_frame);
        break;
      }
      default:
        canzero_exit_critical();
        break;
      }
      break;
    }
    case HEARTBEAT_JOB_TAG: {
      scheduler_reschedule(time + heartbeat_interval);
      canzero_exit_critical();
      canzero_message_heartbeat heartbeat;
      heartbeat.m_node_id = node_id_input_board;
      canzero_frame heartbeat_frame;
      canzero_serialize_canzero_message_heartbeat(&heartbeat, &heartbeat_frame);
      canzero_can0_send(&heartbeat_frame);
      break;
    }
    case GET_RESP_FRAGMENTATION_JOB_TAG: {
      get_resp_fragmentation_job *fragmentation_job = &job->job.get_fragmentation_job;
      canzero_message_get_resp fragmentation_response;
      fragmentation_response.m_header.m_sof = 0;
      fragmentation_response.m_header.m_toggle = fragmentation_job->offset % 2;
      fragmentation_response.m_header.m_od_index = fragmentation_job->od_index;
      fragmentation_response.m_header.m_client_id = 0x1;
      fragmentation_response.m_header.m_server_id = fragmentation_job->server_id;
      fragmentation_response.m_data = fragmentation_job->buffer[fragmentation_job->offset];
      fragmentation_job->offset += 1;
      if (fragmentation_job->offset == fragmentation_job->size) {
        fragmentation_response.m_header.m_eof = 1;
        scheduler_unschedule();
      } else {
        fragmentation_response.m_header.m_eof = 0;
        scheduler_reschedule(time + get_resp_fragmentation_interval);
      }
      canzero_exit_critical();
      canzero_frame fragmentation_frame;
      canzero_serialize_canzero_message_get_resp(&fragmentation_response, &fragmentation_frame);
      canzero_can0_send(&fragmentation_frame);
      break;
    }
    default:
      canzero_exit_critical();
      break;
    }
  }
}
static uint32_t scheduler_next_job_timeout(){
  return scheduler.heap[0]->climax;
}
static uint32_t __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[7];
static uint32_t __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[7];
static uint32_t __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[7];
static uint32_t __oe_error_level_config_link24_under_voltage_rx_fragmentation_buffer[7];
static uint32_t __oe_error_level_config_link24_over_voltage_rx_fragmentation_buffer[7];
static uint32_t __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[7];
static uint32_t __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[7];
static uint32_t __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[7];
static uint32_t __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[7];
static uint32_t __oe_error_level_config_cooling_cycle_under_pressure_rx_fragmentation_buffer[7];
static uint32_t __oe_error_level_config_cooling_cycle_over_pressure_rx_fragmentation_buffer[7];
static uint32_t __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[7];
static uint32_t __oe_error_level_config_cooling_temperature_rx_fragmentation_buffer[7];
static uint32_t __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[7];
static uint32_t __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[7];
static uint32_t __oe_error_level_config_buck_temperature_rx_fragmentation_buffer[7];
static uint32_t __oe_error_level_config_ebox_temperature_rx_fragmentation_buffer[7];
static uint32_t __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[7];
static void canzero_handle_get_req(canzero_frame* frame) {
  canzero_message_get_req msg;
  canzero_deserialize_canzero_message_get_req(frame, &msg);
  if (msg.m_header.m_server_id != 1) {
    return;
  }
  canzero_message_get_resp resp;
  switch (msg.m_header.m_od_index) {
  case 0: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_state) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 1: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_sdc_status) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 2: {
    resp.m_data |= ((uint32_t)((__oe_position - (-0)) / 0.0007629510948348211)) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 3: {
    resp.m_data |= ((uint32_t)((__oe_velocity - (-10)) / 0.00030518043793392844)) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 4: {
    resp.m_data |= ((uint32_t)((__oe_acceleration - (-5)) / 0.00008392462043183032)) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 5: {
    resp.m_data |= ((uint32_t)(__oe_linear_encoder_count & (0xFFFF >> (16 - 16)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 6: {
    resp.m_data |= ((uint32_t)((__oe_track_length - (0)) / 0.000000011641532185403987)) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 7: {
    resp.m_data |= ((uint32_t)((__oe_bat24_voltage - (0)) / 0.000000011641532185403987)) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 8: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_bat24_under_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 9: {
__oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[0] = (__oe_error_level_config_bat24_under_voltage.m_ignore_info & (0xFF >> (8 - 1)));
    __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_under_voltage.m_info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_under_voltage.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[0] = (__oe_error_level_config_bat24_under_voltage.m_ignore_warning & (0xFF >> (8 - 1)));
    __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_under_voltage.m_warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_under_voltage.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[0] = (__oe_error_level_config_bat24_under_voltage.m_ignore_error & (0xFF >> (8 - 1)));
    __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_under_voltage.m_error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_under_voltage.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.m_data = __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer, 7, 9, msg.m_header.m_server_id);
    break;
  }
  case 10: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_bat24_over_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 11: {
__oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[0] = (__oe_error_level_config_bat24_over_voltage.m_ignore_info & (0xFF >> (8 - 1)));
    __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_over_voltage.m_info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_over_voltage.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[0] = (__oe_error_level_config_bat24_over_voltage.m_ignore_warning & (0xFF >> (8 - 1)));
    __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_over_voltage.m_warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_over_voltage.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[0] = (__oe_error_level_config_bat24_over_voltage.m_ignore_error & (0xFF >> (8 - 1)));
    __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_over_voltage.m_error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_over_voltage.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.m_data = __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer, 7, 11, msg.m_header.m_server_id);
    break;
  }
  case 12: {
    resp.m_data |= ((uint32_t)((__oe_bat24_current - (-30)) / 0.000000013969838622484784)) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 13: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_bat24_over_current) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 14: {
__oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[0] = (__oe_error_level_config_bat24_over_current.m_ignore_info & (0xFF >> (8 - 1)));
    __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_over_current.m_info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_over_current.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[0] = (__oe_error_level_config_bat24_over_current.m_ignore_warning & (0xFF >> (8 - 1)));
    __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_over_current.m_warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_over_current.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[0] = (__oe_error_level_config_bat24_over_current.m_ignore_error & (0xFF >> (8 - 1)));
    __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_over_current.m_error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_over_current.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.m_data = __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_bat24_over_current_rx_fragmentation_buffer, 7, 14, msg.m_header.m_server_id);
    break;
  }
  case 15: {
    resp.m_data |= ((uint32_t)((__oe_link24_voltage - (0)) / 0.000000011641532185403987)) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 16: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_link24_under_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 17: {
__oe_error_level_config_link24_under_voltage_rx_fragmentation_buffer[0] = (__oe_error_level_config_link24_under_voltage.m_ignore_info & (0xFF >> (8 - 1)));
    __oe_error_level_config_link24_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_under_voltage.m_info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_under_voltage.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_link24_under_voltage_rx_fragmentation_buffer[0] = (__oe_error_level_config_link24_under_voltage.m_ignore_warning & (0xFF >> (8 - 1)));
    __oe_error_level_config_link24_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_under_voltage.m_warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_under_voltage.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_link24_under_voltage_rx_fragmentation_buffer[0] = (__oe_error_level_config_link24_under_voltage.m_ignore_error & (0xFF >> (8 - 1)));
    __oe_error_level_config_link24_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_under_voltage.m_error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_under_voltage.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.m_data = __oe_error_level_config_link24_under_voltage_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_link24_under_voltage_rx_fragmentation_buffer, 7, 17, msg.m_header.m_server_id);
    break;
  }
  case 18: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_link24_over_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 19: {
__oe_error_level_config_link24_over_voltage_rx_fragmentation_buffer[0] = (__oe_error_level_config_link24_over_voltage.m_ignore_info & (0xFF >> (8 - 1)));
    __oe_error_level_config_link24_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_over_voltage.m_info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_over_voltage.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_link24_over_voltage_rx_fragmentation_buffer[0] = (__oe_error_level_config_link24_over_voltage.m_ignore_warning & (0xFF >> (8 - 1)));
    __oe_error_level_config_link24_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_over_voltage.m_warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_over_voltage.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_link24_over_voltage_rx_fragmentation_buffer[0] = (__oe_error_level_config_link24_over_voltage.m_ignore_error & (0xFF >> (8 - 1)));
    __oe_error_level_config_link24_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_over_voltage.m_error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_over_voltage.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.m_data = __oe_error_level_config_link24_over_voltage_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_link24_over_voltage_rx_fragmentation_buffer, 7, 19, msg.m_header.m_server_id);
    break;
  }
  case 20: {
    resp.m_data |= ((uint32_t)((__oe_link24_current - (-30)) / 0.000000013969838622484784)) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 21: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_link24_over_current) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 22: {
__oe_error_level_config_link24_over_current_rx_fragmentation_buffer[0] = (__oe_error_level_config_link24_over_current.m_ignore_info & (0xFF >> (8 - 1)));
    __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_over_current.m_info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_over_current.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_link24_over_current_rx_fragmentation_buffer[0] = (__oe_error_level_config_link24_over_current.m_ignore_warning & (0xFF >> (8 - 1)));
    __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_over_current.m_warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_over_current.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_link24_over_current_rx_fragmentation_buffer[0] = (__oe_error_level_config_link24_over_current.m_ignore_error & (0xFF >> (8 - 1)));
    __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_over_current.m_error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_over_current.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.m_data = __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_link24_over_current_rx_fragmentation_buffer, 7, 22, msg.m_header.m_server_id);
    break;
  }
  case 23: {
    resp.m_data |= ((uint32_t)((__oe_link45_voltage - (0)) / 0.00000023283064370807974)) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 24: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_link45_expect_online) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 25: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_link45_under_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 26: {
__oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[0] = (__oe_error_level_config_link45_under_voltage.m_ignore_info & (0xFF >> (8 - 1)));
    __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_under_voltage.m_info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_under_voltage.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[0] = (__oe_error_level_config_link45_under_voltage.m_ignore_warning & (0xFF >> (8 - 1)));
    __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_under_voltage.m_warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_under_voltage.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[0] = (__oe_error_level_config_link45_under_voltage.m_ignore_error & (0xFF >> (8 - 1)));
    __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_under_voltage.m_error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_under_voltage.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.m_data = __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer, 7, 26, msg.m_header.m_server_id);
    break;
  }
  case 27: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_link45_over_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 28: {
__oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[0] = (__oe_error_level_config_link45_over_voltage.m_ignore_info & (0xFF >> (8 - 1)));
    __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_over_voltage.m_info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_over_voltage.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[0] = (__oe_error_level_config_link45_over_voltage.m_ignore_warning & (0xFF >> (8 - 1)));
    __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_over_voltage.m_warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_over_voltage.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[0] = (__oe_error_level_config_link45_over_voltage.m_ignore_error & (0xFF >> (8 - 1)));
    __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_over_voltage.m_error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_over_voltage.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.m_data = __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer, 7, 28, msg.m_header.m_server_id);
    break;
  }
  case 29: {
    resp.m_data |= ((uint32_t)((__oe_link45_current - (-1000)) / 0.0000004656612874161595)) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 30: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_link45_over_current) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 31: {
__oe_error_level_config_link45_over_current_rx_fragmentation_buffer[0] = (__oe_error_level_config_link45_over_current.m_ignore_info & (0xFF >> (8 - 1)));
    __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_over_current.m_info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_over_current.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_link45_over_current_rx_fragmentation_buffer[0] = (__oe_error_level_config_link45_over_current.m_ignore_warning & (0xFF >> (8 - 1)));
    __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_over_current.m_warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_over_current.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_link45_over_current_rx_fragmentation_buffer[0] = (__oe_error_level_config_link45_over_current.m_ignore_error & (0xFF >> (8 - 1)));
    __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_over_current.m_error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_over_current.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.m_data = __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_link45_over_current_rx_fragmentation_buffer, 7, 31, msg.m_header.m_server_id);
    break;
  }
  case 32: {
    resp.m_data |= ((uint32_t)((__oe_cooling_cycle_pressure - (-1)) / 0.0392156862745098)) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 33: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_cooling_cycle_under_pressure) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 34: {
__oe_error_level_config_cooling_cycle_under_pressure_rx_fragmentation_buffer[0] = (__oe_error_level_config_cooling_cycle_under_pressure.m_ignore_info & (0xFF >> (8 - 1)));
    __oe_error_level_config_cooling_cycle_under_pressure_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_cycle_under_pressure.m_info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_cooling_cycle_under_pressure_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_cycle_under_pressure.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_cooling_cycle_under_pressure_rx_fragmentation_buffer[0] = (__oe_error_level_config_cooling_cycle_under_pressure.m_ignore_warning & (0xFF >> (8 - 1)));
    __oe_error_level_config_cooling_cycle_under_pressure_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_cycle_under_pressure.m_warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_cooling_cycle_under_pressure_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_cycle_under_pressure.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_cooling_cycle_under_pressure_rx_fragmentation_buffer[0] = (__oe_error_level_config_cooling_cycle_under_pressure.m_ignore_error & (0xFF >> (8 - 1)));
    __oe_error_level_config_cooling_cycle_under_pressure_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_cycle_under_pressure.m_error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_cooling_cycle_under_pressure_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_cycle_under_pressure.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.m_data = __oe_error_level_config_cooling_cycle_under_pressure_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_cooling_cycle_under_pressure_rx_fragmentation_buffer, 7, 34, msg.m_header.m_server_id);
    break;
  }
  case 35: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_cooling_cycle_over_pressure) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 36: {
__oe_error_level_config_cooling_cycle_over_pressure_rx_fragmentation_buffer[0] = (__oe_error_level_config_cooling_cycle_over_pressure.m_ignore_info & (0xFF >> (8 - 1)));
    __oe_error_level_config_cooling_cycle_over_pressure_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_cycle_over_pressure.m_info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_cooling_cycle_over_pressure_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_cycle_over_pressure.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_cooling_cycle_over_pressure_rx_fragmentation_buffer[0] = (__oe_error_level_config_cooling_cycle_over_pressure.m_ignore_warning & (0xFF >> (8 - 1)));
    __oe_error_level_config_cooling_cycle_over_pressure_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_cycle_over_pressure.m_warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_cooling_cycle_over_pressure_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_cycle_over_pressure.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_cooling_cycle_over_pressure_rx_fragmentation_buffer[0] = (__oe_error_level_config_cooling_cycle_over_pressure.m_ignore_error & (0xFF >> (8 - 1)));
    __oe_error_level_config_cooling_cycle_over_pressure_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_cycle_over_pressure.m_error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_cooling_cycle_over_pressure_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_cycle_over_pressure.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.m_data = __oe_error_level_config_cooling_cycle_over_pressure_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_cooling_cycle_over_pressure_rx_fragmentation_buffer, 7, 36, msg.m_header.m_server_id);
    break;
  }
  case 37: {
    resp.m_data |= ((uint32_t)((__oe_mcu_temperature - (-1)) / 0.592156862745098)) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 38: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_mcu_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 39: {
__oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[0] = (__oe_error_level_config_mcu_temperature.m_ignore_info & (0xFF >> (8 - 1)));
    __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_mcu_temperature.m_info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_mcu_temperature.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[0] = (__oe_error_level_config_mcu_temperature.m_ignore_warning & (0xFF >> (8 - 1)));
    __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_mcu_temperature.m_warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_mcu_temperature.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[0] = (__oe_error_level_config_mcu_temperature.m_ignore_error & (0xFF >> (8 - 1)));
    __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_mcu_temperature.m_error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_mcu_temperature.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.m_data = __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_mcu_temperature_rx_fragmentation_buffer, 7, 39, msg.m_header.m_server_id);
    break;
  }
  case 40: {
    resp.m_data |= ((uint32_t)((__oe_cooling_cycle_temperature - (-1)) / 0.592156862745098)) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 41: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_cooling_cycle_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 42: {
__oe_error_level_config_cooling_temperature_rx_fragmentation_buffer[0] = (__oe_error_level_config_cooling_temperature.m_ignore_info & (0xFF >> (8 - 1)));
    __oe_error_level_config_cooling_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_temperature.m_info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_cooling_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_temperature.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_cooling_temperature_rx_fragmentation_buffer[0] = (__oe_error_level_config_cooling_temperature.m_ignore_warning & (0xFF >> (8 - 1)));
    __oe_error_level_config_cooling_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_temperature.m_warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_cooling_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_temperature.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_cooling_temperature_rx_fragmentation_buffer[0] = (__oe_error_level_config_cooling_temperature.m_ignore_error & (0xFF >> (8 - 1)));
    __oe_error_level_config_cooling_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_temperature.m_error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_cooling_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_temperature.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.m_data = __oe_error_level_config_cooling_temperature_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_cooling_temperature_rx_fragmentation_buffer, 7, 42, msg.m_header.m_server_id);
    break;
  }
  case 43: {
    resp.m_data |= ((uint32_t)((__oe_bat24_temperature - (-1)) / 0.592156862745098)) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 44: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_bat24_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 45: {
__oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[0] = (__oe_error_level_config_bat24_temperature.m_ignore_info & (0xFF >> (8 - 1)));
    __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_temperature.m_info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_temperature.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[0] = (__oe_error_level_config_bat24_temperature.m_ignore_warning & (0xFF >> (8 - 1)));
    __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_temperature.m_warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_temperature.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[0] = (__oe_error_level_config_bat24_temperature.m_ignore_error & (0xFF >> (8 - 1)));
    __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_temperature.m_error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_temperature.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.m_data = __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_bat24_temperature_rx_fragmentation_buffer, 7, 45, msg.m_header.m_server_id);
    break;
  }
  case 46: {
    resp.m_data |= ((uint32_t)((__oe_supercap_temperature - (-1)) / 0.592156862745098)) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 47: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_supercap_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 48: {
__oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[0] = (__oe_error_level_config_supercap_temperature.m_ignore_info & (0xFF >> (8 - 1)));
    __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_supercap_temperature.m_info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_supercap_temperature.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[0] = (__oe_error_level_config_supercap_temperature.m_ignore_warning & (0xFF >> (8 - 1)));
    __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_supercap_temperature.m_warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_supercap_temperature.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[0] = (__oe_error_level_config_supercap_temperature.m_ignore_error & (0xFF >> (8 - 1)));
    __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_supercap_temperature.m_error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_supercap_temperature.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.m_data = __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_supercap_temperature_rx_fragmentation_buffer, 7, 48, msg.m_header.m_server_id);
    break;
  }
  case 49: {
    resp.m_data |= ((uint32_t)((__oe_buck_temperature - (-1)) / 0.592156862745098)) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 50: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_buck_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 51: {
__oe_error_level_config_buck_temperature_rx_fragmentation_buffer[0] = (__oe_error_level_config_buck_temperature.m_ignore_info & (0xFF >> (8 - 1)));
    __oe_error_level_config_buck_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_buck_temperature.m_info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_buck_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_buck_temperature.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_buck_temperature_rx_fragmentation_buffer[0] = (__oe_error_level_config_buck_temperature.m_ignore_warning & (0xFF >> (8 - 1)));
    __oe_error_level_config_buck_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_buck_temperature.m_warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_buck_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_buck_temperature.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_buck_temperature_rx_fragmentation_buffer[0] = (__oe_error_level_config_buck_temperature.m_ignore_error & (0xFF >> (8 - 1)));
    __oe_error_level_config_buck_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_buck_temperature.m_error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_buck_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_buck_temperature.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.m_data = __oe_error_level_config_buck_temperature_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_buck_temperature_rx_fragmentation_buffer, 7, 51, msg.m_header.m_server_id);
    break;
  }
  case 52: {
    resp.m_data |= ((uint32_t)((__oe_ebox_temperature - (-1)) / 0.592156862745098)) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 53: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_ebox_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 54: {
__oe_error_level_config_ebox_temperature_rx_fragmentation_buffer[0] = (__oe_error_level_config_ebox_temperature.m_ignore_info & (0xFF >> (8 - 1)));
    __oe_error_level_config_ebox_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_ebox_temperature.m_info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_ebox_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_ebox_temperature.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_ebox_temperature_rx_fragmentation_buffer[0] = (__oe_error_level_config_ebox_temperature.m_ignore_warning & (0xFF >> (8 - 1)));
    __oe_error_level_config_ebox_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_ebox_temperature.m_warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_ebox_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_ebox_temperature.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_ebox_temperature_rx_fragmentation_buffer[0] = (__oe_error_level_config_ebox_temperature.m_ignore_error & (0xFF >> (8 - 1)));
    __oe_error_level_config_ebox_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_ebox_temperature.m_error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_ebox_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_ebox_temperature.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.m_data = __oe_error_level_config_ebox_temperature_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_ebox_temperature_rx_fragmentation_buffer, 7, 54, msg.m_header.m_server_id);
    break;
  }
  case 55: {
    resp.m_data |= ((uint32_t)((__oe_ambient_temperature - (-1)) / 0.592156862745098)) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 56: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_error_level_ambient_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  case 57: {
__oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[0] = (__oe_error_level_config_ambient_temperature.m_ignore_info & (0xFF >> (8 - 1)));
    __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_ambient_temperature.m_info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_ambient_temperature.m_info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[0] = (__oe_error_level_config_ambient_temperature.m_ignore_warning & (0xFF >> (8 - 1)));
    __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_ambient_temperature.m_warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_ambient_temperature.m_warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
__oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[0] = (__oe_error_level_config_ambient_temperature.m_ignore_error & (0xFF >> (8 - 1)));
    __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_ambient_temperature.m_error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_ambient_temperature.m_error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.m_data = __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[0];
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 0;
    resp.m_header.m_toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_ambient_temperature_rx_fragmentation_buffer, 7, 57, msg.m_header.m_server_id);
    break;
  }
  case 58: {
    resp.m_data |= ((uint32_t)(((uint8_t)__oe_assertion_fault) & (0xFF >> (8 - 1)))) << 0;
    resp.m_header.m_sof = 1;
    resp.m_header.m_eof = 1;
    resp.m_header.m_toggle = 0;
    break;
  }
  }
  resp.m_header.m_od_index = msg.m_header.m_od_index;
  resp.m_header.m_client_id = msg.m_header.m_client_id;
  resp.m_header.m_server_id = msg.m_header.m_server_id;
  canzero_frame resp_frame;
  canzero_serialize_canzero_message_get_resp(&resp, &resp_frame);
  canzero_can0_send(&resp_frame);
}
static uint32_t error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[7];
static uint32_t error_level_config_bat24_under_voltage_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[7];
static uint32_t error_level_config_bat24_over_voltage_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[7];
static uint32_t error_level_config_bat24_over_current_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_link24_under_voltage_tmp_tx_fragmentation_buffer[7];
static uint32_t error_level_config_link24_under_voltage_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_link24_over_voltage_tmp_tx_fragmentation_buffer[7];
static uint32_t error_level_config_link24_over_voltage_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[7];
static uint32_t error_level_config_link24_over_current_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[7];
static uint32_t error_level_config_link45_under_voltage_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[7];
static uint32_t error_level_config_link45_over_voltage_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[7];
static uint32_t error_level_config_link45_over_current_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_buffer[7];
static uint32_t error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_buffer[7];
static uint32_t error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[7];
static uint32_t error_level_config_mcu_temperature_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_cooling_temperature_tmp_tx_fragmentation_buffer[7];
static uint32_t error_level_config_cooling_temperature_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[7];
static uint32_t error_level_config_bat24_temperature_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[7];
static uint32_t error_level_config_supercap_temperature_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_buck_temperature_tmp_tx_fragmentation_buffer[7];
static uint32_t error_level_config_buck_temperature_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_ebox_temperature_tmp_tx_fragmentation_buffer[7];
static uint32_t error_level_config_ebox_temperature_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[7];
static uint32_t error_level_config_ambient_temperature_tmp_tx_fragmentation_offset = 0;
static void canzero_handle_set_req(canzero_frame* frame) {
  canzero_message_set_req msg;
  canzero_deserialize_canzero_message_set_req(frame, &msg);
  if (msg.m_header.m_server_id != 1) {
    return;
  }
  canzero_message_set_resp resp;
  switch (msg.m_header.m_od_index) {
  case 0 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    input_board_state state_tmp;
    state_tmp = (input_board_state)((msg.m_data & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_state(state_tmp);
    break;
  }
  case 1 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    sdc_status sdc_status_tmp;
    sdc_status_tmp = (sdc_status)((msg.m_data & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_sdc_status(sdc_status_tmp);
    break;
  }
  case 2 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float position_tmp;
    position_tmp = (float)((msg.m_data & (0xFFFFFFFF >> (32 - 16))) * 0.0007629510948348211 + -0);
    canzero_set_position(position_tmp);
    break;
  }
  case 3 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float velocity_tmp;
    velocity_tmp = (float)((msg.m_data & (0xFFFFFFFF >> (32 - 16))) * 0.00030518043793392844 + -10);
    canzero_set_velocity(velocity_tmp);
    break;
  }
  case 4 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float acceleration_tmp;
    acceleration_tmp = (float)((msg.m_data & (0xFFFFFFFF >> (32 - 16))) * 0.00008392462043183032 + -5);
    canzero_set_acceleration(acceleration_tmp);
    break;
  }
  case 5 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    uint16_t linear_encoder_count_tmp;
    linear_encoder_count_tmp = (uint16_t)(msg.m_data & (0xFFFFFFFF >> (32 - 16)));
    canzero_set_linear_encoder_count(linear_encoder_count_tmp);
    break;
  }
  case 6 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float track_length_tmp;
    track_length_tmp = (float)((msg.m_data & (0xFFFFFFFF >> (32 - 32))) * 0.000000011641532185403987 + 0);
    canzero_set_track_length(track_length_tmp);
    break;
  }
  case 7 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float bat24_voltage_tmp;
    bat24_voltage_tmp = (float)((msg.m_data & (0xFFFFFFFF >> (32 - 32))) * 0.000000011641532185403987 + 0);
    canzero_set_bat24_voltage(bat24_voltage_tmp);
    break;
  }
  case 8 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_bat24_under_voltage_tmp;
    error_level_bat24_under_voltage_tmp = (error_level)((msg.m_data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_bat24_under_voltage(error_level_bat24_under_voltage_tmp);
    break;
  }
  case 9 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle == 0 || msg.m_header.m_eof != 0) {
        return;
      }
      error_level_config_bat24_under_voltage_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_bat24_under_voltage_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_bat24_under_voltage_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[error_level_config_bat24_under_voltage_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_bat24_under_voltage_tmp;
    error_level_config_bat24_under_voltage_tmp.m_ignore_info = ((bool_t)(error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_bat24_under_voltage_tmp.m_info_thresh = ((error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_bat24_under_voltage_tmp.m_info_timeout = ((error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_under_voltage_tmp.m_ignore_warning = ((bool_t)(error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_bat24_under_voltage_tmp.m_warning_thresh = ((error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_bat24_under_voltage_tmp.m_warning_timeout = ((error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_under_voltage_tmp.m_ignore_error = ((bool_t)(error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_bat24_under_voltage_tmp.m_error_thresh = ((error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_bat24_under_voltage_tmp.m_error_timeout = ((error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_bat24_under_voltage(error_level_config_bat24_under_voltage_tmp);
    break;
  }
  case 10 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_bat24_over_voltage_tmp;
    error_level_bat24_over_voltage_tmp = (error_level)((msg.m_data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_bat24_over_voltage(error_level_bat24_over_voltage_tmp);
    break;
  }
  case 11 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle == 0 || msg.m_header.m_eof != 0) {
        return;
      }
      error_level_config_bat24_over_voltage_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_bat24_over_voltage_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_bat24_over_voltage_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[error_level_config_bat24_over_voltage_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_bat24_over_voltage_tmp;
    error_level_config_bat24_over_voltage_tmp.m_ignore_info = ((bool_t)(error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_bat24_over_voltage_tmp.m_info_thresh = ((error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_bat24_over_voltage_tmp.m_info_timeout = ((error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_over_voltage_tmp.m_ignore_warning = ((bool_t)(error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_bat24_over_voltage_tmp.m_warning_thresh = ((error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_bat24_over_voltage_tmp.m_warning_timeout = ((error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_over_voltage_tmp.m_ignore_error = ((bool_t)(error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_bat24_over_voltage_tmp.m_error_thresh = ((error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_bat24_over_voltage_tmp.m_error_timeout = ((error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_bat24_over_voltage(error_level_config_bat24_over_voltage_tmp);
    break;
  }
  case 12 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float bat24_current_tmp;
    bat24_current_tmp = (float)((msg.m_data & (0xFFFFFFFF >> (32 - 32))) * 0.000000013969838622484784 + -30);
    canzero_set_bat24_current(bat24_current_tmp);
    break;
  }
  case 13 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_bat24_over_current_tmp;
    error_level_bat24_over_current_tmp = (error_level)((msg.m_data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_bat24_over_current(error_level_bat24_over_current_tmp);
    break;
  }
  case 14 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle == 0 || msg.m_header.m_eof != 0) {
        return;
      }
      error_level_config_bat24_over_current_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_bat24_over_current_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_bat24_over_current_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[error_level_config_bat24_over_current_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_bat24_over_current_tmp;
    error_level_config_bat24_over_current_tmp.m_ignore_info = ((bool_t)(error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_bat24_over_current_tmp.m_info_thresh = ((error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_bat24_over_current_tmp.m_info_timeout = ((error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_over_current_tmp.m_ignore_warning = ((bool_t)(error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_bat24_over_current_tmp.m_warning_thresh = ((error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_bat24_over_current_tmp.m_warning_timeout = ((error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_over_current_tmp.m_ignore_error = ((bool_t)(error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_bat24_over_current_tmp.m_error_thresh = ((error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_bat24_over_current_tmp.m_error_timeout = ((error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_bat24_over_current(error_level_config_bat24_over_current_tmp);
    break;
  }
  case 15 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float link24_voltage_tmp;
    link24_voltage_tmp = (float)((msg.m_data & (0xFFFFFFFF >> (32 - 32))) * 0.000000011641532185403987 + 0);
    canzero_set_link24_voltage(link24_voltage_tmp);
    break;
  }
  case 16 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_link24_under_voltage_tmp;
    error_level_link24_under_voltage_tmp = (error_level)((msg.m_data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_link24_under_voltage(error_level_link24_under_voltage_tmp);
    break;
  }
  case 17 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle == 0 || msg.m_header.m_eof != 0) {
        return;
      }
      error_level_config_link24_under_voltage_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_link24_under_voltage_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_link24_under_voltage_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_link24_under_voltage_tmp_tx_fragmentation_buffer[error_level_config_link24_under_voltage_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_link24_under_voltage_tmp;
    error_level_config_link24_under_voltage_tmp.m_ignore_info = ((bool_t)(error_level_config_link24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_link24_under_voltage_tmp.m_info_thresh = ((error_level_config_link24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link24_under_voltage_tmp.m_info_timeout = ((error_level_config_link24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link24_under_voltage_tmp.m_ignore_warning = ((bool_t)(error_level_config_link24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_link24_under_voltage_tmp.m_warning_thresh = ((error_level_config_link24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link24_under_voltage_tmp.m_warning_timeout = ((error_level_config_link24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link24_under_voltage_tmp.m_ignore_error = ((bool_t)(error_level_config_link24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_link24_under_voltage_tmp.m_error_thresh = ((error_level_config_link24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link24_under_voltage_tmp.m_error_timeout = ((error_level_config_link24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_link24_under_voltage(error_level_config_link24_under_voltage_tmp);
    break;
  }
  case 18 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_link24_over_voltage_tmp;
    error_level_link24_over_voltage_tmp = (error_level)((msg.m_data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_link24_over_voltage(error_level_link24_over_voltage_tmp);
    break;
  }
  case 19 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle == 0 || msg.m_header.m_eof != 0) {
        return;
      }
      error_level_config_link24_over_voltage_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_link24_over_voltage_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_link24_over_voltage_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_link24_over_voltage_tmp_tx_fragmentation_buffer[error_level_config_link24_over_voltage_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_link24_over_voltage_tmp;
    error_level_config_link24_over_voltage_tmp.m_ignore_info = ((bool_t)(error_level_config_link24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_link24_over_voltage_tmp.m_info_thresh = ((error_level_config_link24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link24_over_voltage_tmp.m_info_timeout = ((error_level_config_link24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link24_over_voltage_tmp.m_ignore_warning = ((bool_t)(error_level_config_link24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_link24_over_voltage_tmp.m_warning_thresh = ((error_level_config_link24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link24_over_voltage_tmp.m_warning_timeout = ((error_level_config_link24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link24_over_voltage_tmp.m_ignore_error = ((bool_t)(error_level_config_link24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_link24_over_voltage_tmp.m_error_thresh = ((error_level_config_link24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link24_over_voltage_tmp.m_error_timeout = ((error_level_config_link24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_link24_over_voltage(error_level_config_link24_over_voltage_tmp);
    break;
  }
  case 20 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float link24_current_tmp;
    link24_current_tmp = (float)((msg.m_data & (0xFFFFFFFF >> (32 - 32))) * 0.000000013969838622484784 + -30);
    canzero_set_link24_current(link24_current_tmp);
    break;
  }
  case 21 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_link24_over_current_tmp;
    error_level_link24_over_current_tmp = (error_level)((msg.m_data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_link24_over_current(error_level_link24_over_current_tmp);
    break;
  }
  case 22 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle == 0 || msg.m_header.m_eof != 0) {
        return;
      }
      error_level_config_link24_over_current_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_link24_over_current_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_link24_over_current_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[error_level_config_link24_over_current_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_link24_over_current_tmp;
    error_level_config_link24_over_current_tmp.m_ignore_info = ((bool_t)(error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_link24_over_current_tmp.m_info_thresh = ((error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link24_over_current_tmp.m_info_timeout = ((error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link24_over_current_tmp.m_ignore_warning = ((bool_t)(error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_link24_over_current_tmp.m_warning_thresh = ((error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link24_over_current_tmp.m_warning_timeout = ((error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link24_over_current_tmp.m_ignore_error = ((bool_t)(error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_link24_over_current_tmp.m_error_thresh = ((error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link24_over_current_tmp.m_error_timeout = ((error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_link24_over_current(error_level_config_link24_over_current_tmp);
    break;
  }
  case 23 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float link45_voltage_tmp;
    link45_voltage_tmp = (float)((msg.m_data & (0xFFFFFFFF >> (32 - 32))) * 0.00000023283064370807974 + 0);
    canzero_set_link45_voltage(link45_voltage_tmp);
    break;
  }
  case 24 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    bool_t link45_expect_online_tmp;
    link45_expect_online_tmp = (bool_t)((msg.m_data & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_link45_expect_online(link45_expect_online_tmp);
    break;
  }
  case 25 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_link45_under_voltage_tmp;
    error_level_link45_under_voltage_tmp = (error_level)((msg.m_data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_link45_under_voltage(error_level_link45_under_voltage_tmp);
    break;
  }
  case 26 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle == 0 || msg.m_header.m_eof != 0) {
        return;
      }
      error_level_config_link45_under_voltage_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_link45_under_voltage_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_link45_under_voltage_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[error_level_config_link45_under_voltage_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_link45_under_voltage_tmp;
    error_level_config_link45_under_voltage_tmp.m_ignore_info = ((bool_t)(error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_link45_under_voltage_tmp.m_info_thresh = ((error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link45_under_voltage_tmp.m_info_timeout = ((error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link45_under_voltage_tmp.m_ignore_warning = ((bool_t)(error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_link45_under_voltage_tmp.m_warning_thresh = ((error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link45_under_voltage_tmp.m_warning_timeout = ((error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link45_under_voltage_tmp.m_ignore_error = ((bool_t)(error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_link45_under_voltage_tmp.m_error_thresh = ((error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link45_under_voltage_tmp.m_error_timeout = ((error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_link45_under_voltage(error_level_config_link45_under_voltage_tmp);
    break;
  }
  case 27 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_link45_over_voltage_tmp;
    error_level_link45_over_voltage_tmp = (error_level)((msg.m_data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_link45_over_voltage(error_level_link45_over_voltage_tmp);
    break;
  }
  case 28 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle == 0 || msg.m_header.m_eof != 0) {
        return;
      }
      error_level_config_link45_over_voltage_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_link45_over_voltage_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_link45_over_voltage_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[error_level_config_link45_over_voltage_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_link45_over_voltage_tmp;
    error_level_config_link45_over_voltage_tmp.m_ignore_info = ((bool_t)(error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_link45_over_voltage_tmp.m_info_thresh = ((error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link45_over_voltage_tmp.m_info_timeout = ((error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link45_over_voltage_tmp.m_ignore_warning = ((bool_t)(error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_link45_over_voltage_tmp.m_warning_thresh = ((error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link45_over_voltage_tmp.m_warning_timeout = ((error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link45_over_voltage_tmp.m_ignore_error = ((bool_t)(error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_link45_over_voltage_tmp.m_error_thresh = ((error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link45_over_voltage_tmp.m_error_timeout = ((error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_link45_over_voltage(error_level_config_link45_over_voltage_tmp);
    break;
  }
  case 29 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float link45_current_tmp;
    link45_current_tmp = (float)((msg.m_data & (0xFFFFFFFF >> (32 - 32))) * 0.0000004656612874161595 + -1000);
    canzero_set_link45_current(link45_current_tmp);
    break;
  }
  case 30 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_link45_over_current_tmp;
    error_level_link45_over_current_tmp = (error_level)((msg.m_data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_link45_over_current(error_level_link45_over_current_tmp);
    break;
  }
  case 31 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle == 0 || msg.m_header.m_eof != 0) {
        return;
      }
      error_level_config_link45_over_current_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_link45_over_current_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_link45_over_current_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[error_level_config_link45_over_current_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_link45_over_current_tmp;
    error_level_config_link45_over_current_tmp.m_ignore_info = ((bool_t)(error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_link45_over_current_tmp.m_info_thresh = ((error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link45_over_current_tmp.m_info_timeout = ((error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link45_over_current_tmp.m_ignore_warning = ((bool_t)(error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_link45_over_current_tmp.m_warning_thresh = ((error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link45_over_current_tmp.m_warning_timeout = ((error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link45_over_current_tmp.m_ignore_error = ((bool_t)(error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_link45_over_current_tmp.m_error_thresh = ((error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link45_over_current_tmp.m_error_timeout = ((error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_link45_over_current(error_level_config_link45_over_current_tmp);
    break;
  }
  case 32 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float cooling_cycle_pressure_tmp;
    cooling_cycle_pressure_tmp = (float)((msg.m_data & (0xFFFFFFFF >> (32 - 8))) * 0.0392156862745098 + -1);
    canzero_set_cooling_cycle_pressure(cooling_cycle_pressure_tmp);
    break;
  }
  case 33 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_cooling_cycle_under_pressure_tmp;
    error_level_cooling_cycle_under_pressure_tmp = (error_level)((msg.m_data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_cooling_cycle_under_pressure(error_level_cooling_cycle_under_pressure_tmp);
    break;
  }
  case 34 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle == 0 || msg.m_header.m_eof != 0) {
        return;
      }
      error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_buffer[error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_cooling_cycle_under_pressure_tmp;
    error_level_config_cooling_cycle_under_pressure_tmp.m_ignore_info = ((bool_t)(error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_cooling_cycle_under_pressure_tmp.m_info_thresh = ((error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_cooling_cycle_under_pressure_tmp.m_info_timeout = ((error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_cooling_cycle_under_pressure_tmp.m_ignore_warning = ((bool_t)(error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_cooling_cycle_under_pressure_tmp.m_warning_thresh = ((error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_cooling_cycle_under_pressure_tmp.m_warning_timeout = ((error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_cooling_cycle_under_pressure_tmp.m_ignore_error = ((bool_t)(error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_cooling_cycle_under_pressure_tmp.m_error_thresh = ((error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_cooling_cycle_under_pressure_tmp.m_error_timeout = ((error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_cooling_cycle_under_pressure(error_level_config_cooling_cycle_under_pressure_tmp);
    break;
  }
  case 35 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_cooling_cycle_over_pressure_tmp;
    error_level_cooling_cycle_over_pressure_tmp = (error_level)((msg.m_data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_cooling_cycle_over_pressure(error_level_cooling_cycle_over_pressure_tmp);
    break;
  }
  case 36 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle == 0 || msg.m_header.m_eof != 0) {
        return;
      }
      error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_buffer[error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_cooling_cycle_over_pressure_tmp;
    error_level_config_cooling_cycle_over_pressure_tmp.m_ignore_info = ((bool_t)(error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_cooling_cycle_over_pressure_tmp.m_info_thresh = ((error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_cooling_cycle_over_pressure_tmp.m_info_timeout = ((error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_cooling_cycle_over_pressure_tmp.m_ignore_warning = ((bool_t)(error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_cooling_cycle_over_pressure_tmp.m_warning_thresh = ((error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_cooling_cycle_over_pressure_tmp.m_warning_timeout = ((error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_cooling_cycle_over_pressure_tmp.m_ignore_error = ((bool_t)(error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_cooling_cycle_over_pressure_tmp.m_error_thresh = ((error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_cooling_cycle_over_pressure_tmp.m_error_timeout = ((error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_cooling_cycle_over_pressure(error_level_config_cooling_cycle_over_pressure_tmp);
    break;
  }
  case 37 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float mcu_temperature_tmp;
    mcu_temperature_tmp = (float)((msg.m_data & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_mcu_temperature(mcu_temperature_tmp);
    break;
  }
  case 38 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_mcu_temperature_tmp;
    error_level_mcu_temperature_tmp = (error_level)((msg.m_data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_mcu_temperature(error_level_mcu_temperature_tmp);
    break;
  }
  case 39 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle == 0 || msg.m_header.m_eof != 0) {
        return;
      }
      error_level_config_mcu_temperature_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_mcu_temperature_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_mcu_temperature_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[error_level_config_mcu_temperature_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_mcu_temperature_tmp;
    error_level_config_mcu_temperature_tmp.m_ignore_info = ((bool_t)(error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_mcu_temperature_tmp.m_info_thresh = ((error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_mcu_temperature_tmp.m_info_timeout = ((error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_mcu_temperature_tmp.m_ignore_warning = ((bool_t)(error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_mcu_temperature_tmp.m_warning_thresh = ((error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_mcu_temperature_tmp.m_warning_timeout = ((error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_mcu_temperature_tmp.m_ignore_error = ((bool_t)(error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_mcu_temperature_tmp.m_error_thresh = ((error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_mcu_temperature_tmp.m_error_timeout = ((error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_mcu_temperature(error_level_config_mcu_temperature_tmp);
    break;
  }
  case 40 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float cooling_cycle_temperature_tmp;
    cooling_cycle_temperature_tmp = (float)((msg.m_data & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_cooling_cycle_temperature(cooling_cycle_temperature_tmp);
    break;
  }
  case 41 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_cooling_cycle_temperature_tmp;
    error_level_cooling_cycle_temperature_tmp = (error_level)((msg.m_data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_cooling_cycle_temperature(error_level_cooling_cycle_temperature_tmp);
    break;
  }
  case 42 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle == 0 || msg.m_header.m_eof != 0) {
        return;
      }
      error_level_config_cooling_temperature_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_cooling_temperature_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_cooling_temperature_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_cooling_temperature_tmp_tx_fragmentation_buffer[error_level_config_cooling_temperature_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_cooling_temperature_tmp;
    error_level_config_cooling_temperature_tmp.m_ignore_info = ((bool_t)(error_level_config_cooling_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_cooling_temperature_tmp.m_info_thresh = ((error_level_config_cooling_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_cooling_temperature_tmp.m_info_timeout = ((error_level_config_cooling_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_cooling_temperature_tmp.m_ignore_warning = ((bool_t)(error_level_config_cooling_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_cooling_temperature_tmp.m_warning_thresh = ((error_level_config_cooling_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_cooling_temperature_tmp.m_warning_timeout = ((error_level_config_cooling_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_cooling_temperature_tmp.m_ignore_error = ((bool_t)(error_level_config_cooling_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_cooling_temperature_tmp.m_error_thresh = ((error_level_config_cooling_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_cooling_temperature_tmp.m_error_timeout = ((error_level_config_cooling_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_cooling_temperature(error_level_config_cooling_temperature_tmp);
    break;
  }
  case 43 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float bat24_temperature_tmp;
    bat24_temperature_tmp = (float)((msg.m_data & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_bat24_temperature(bat24_temperature_tmp);
    break;
  }
  case 44 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_bat24_temperature_tmp;
    error_level_bat24_temperature_tmp = (error_level)((msg.m_data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_bat24_temperature(error_level_bat24_temperature_tmp);
    break;
  }
  case 45 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle == 0 || msg.m_header.m_eof != 0) {
        return;
      }
      error_level_config_bat24_temperature_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_bat24_temperature_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_bat24_temperature_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[error_level_config_bat24_temperature_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_bat24_temperature_tmp;
    error_level_config_bat24_temperature_tmp.m_ignore_info = ((bool_t)(error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_bat24_temperature_tmp.m_info_thresh = ((error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_bat24_temperature_tmp.m_info_timeout = ((error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_temperature_tmp.m_ignore_warning = ((bool_t)(error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_bat24_temperature_tmp.m_warning_thresh = ((error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_bat24_temperature_tmp.m_warning_timeout = ((error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_temperature_tmp.m_ignore_error = ((bool_t)(error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_bat24_temperature_tmp.m_error_thresh = ((error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_bat24_temperature_tmp.m_error_timeout = ((error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_bat24_temperature(error_level_config_bat24_temperature_tmp);
    break;
  }
  case 46 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float supercap_temperature_tmp;
    supercap_temperature_tmp = (float)((msg.m_data & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_supercap_temperature(supercap_temperature_tmp);
    break;
  }
  case 47 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_supercap_temperature_tmp;
    error_level_supercap_temperature_tmp = (error_level)((msg.m_data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_supercap_temperature(error_level_supercap_temperature_tmp);
    break;
  }
  case 48 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle == 0 || msg.m_header.m_eof != 0) {
        return;
      }
      error_level_config_supercap_temperature_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_supercap_temperature_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_supercap_temperature_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[error_level_config_supercap_temperature_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_supercap_temperature_tmp;
    error_level_config_supercap_temperature_tmp.m_ignore_info = ((bool_t)(error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_supercap_temperature_tmp.m_info_thresh = ((error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_supercap_temperature_tmp.m_info_timeout = ((error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_supercap_temperature_tmp.m_ignore_warning = ((bool_t)(error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_supercap_temperature_tmp.m_warning_thresh = ((error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_supercap_temperature_tmp.m_warning_timeout = ((error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_supercap_temperature_tmp.m_ignore_error = ((bool_t)(error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_supercap_temperature_tmp.m_error_thresh = ((error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_supercap_temperature_tmp.m_error_timeout = ((error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_supercap_temperature(error_level_config_supercap_temperature_tmp);
    break;
  }
  case 49 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float buck_temperature_tmp;
    buck_temperature_tmp = (float)((msg.m_data & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_buck_temperature(buck_temperature_tmp);
    break;
  }
  case 50 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_buck_temperature_tmp;
    error_level_buck_temperature_tmp = (error_level)((msg.m_data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_buck_temperature(error_level_buck_temperature_tmp);
    break;
  }
  case 51 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle == 0 || msg.m_header.m_eof != 0) {
        return;
      }
      error_level_config_buck_temperature_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_buck_temperature_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_buck_temperature_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_buck_temperature_tmp_tx_fragmentation_buffer[error_level_config_buck_temperature_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_buck_temperature_tmp;
    error_level_config_buck_temperature_tmp.m_ignore_info = ((bool_t)(error_level_config_buck_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_buck_temperature_tmp.m_info_thresh = ((error_level_config_buck_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_buck_temperature_tmp.m_info_timeout = ((error_level_config_buck_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_buck_temperature_tmp.m_ignore_warning = ((bool_t)(error_level_config_buck_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_buck_temperature_tmp.m_warning_thresh = ((error_level_config_buck_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_buck_temperature_tmp.m_warning_timeout = ((error_level_config_buck_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_buck_temperature_tmp.m_ignore_error = ((bool_t)(error_level_config_buck_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_buck_temperature_tmp.m_error_thresh = ((error_level_config_buck_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_buck_temperature_tmp.m_error_timeout = ((error_level_config_buck_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_buck_temperature(error_level_config_buck_temperature_tmp);
    break;
  }
  case 52 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float ebox_temperature_tmp;
    ebox_temperature_tmp = (float)((msg.m_data & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_ebox_temperature(ebox_temperature_tmp);
    break;
  }
  case 53 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_ebox_temperature_tmp;
    error_level_ebox_temperature_tmp = (error_level)((msg.m_data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_ebox_temperature(error_level_ebox_temperature_tmp);
    break;
  }
  case 54 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle == 0 || msg.m_header.m_eof != 0) {
        return;
      }
      error_level_config_ebox_temperature_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_ebox_temperature_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_ebox_temperature_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_ebox_temperature_tmp_tx_fragmentation_buffer[error_level_config_ebox_temperature_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_ebox_temperature_tmp;
    error_level_config_ebox_temperature_tmp.m_ignore_info = ((bool_t)(error_level_config_ebox_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_ebox_temperature_tmp.m_info_thresh = ((error_level_config_ebox_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_ebox_temperature_tmp.m_info_timeout = ((error_level_config_ebox_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_ebox_temperature_tmp.m_ignore_warning = ((bool_t)(error_level_config_ebox_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_ebox_temperature_tmp.m_warning_thresh = ((error_level_config_ebox_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_ebox_temperature_tmp.m_warning_timeout = ((error_level_config_ebox_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_ebox_temperature_tmp.m_ignore_error = ((bool_t)(error_level_config_ebox_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_ebox_temperature_tmp.m_error_thresh = ((error_level_config_ebox_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_ebox_temperature_tmp.m_error_timeout = ((error_level_config_ebox_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_ebox_temperature(error_level_config_ebox_temperature_tmp);
    break;
  }
  case 55 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    float ambient_temperature_tmp;
    ambient_temperature_tmp = (float)((msg.m_data & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_ambient_temperature(ambient_temperature_tmp);
    break;
  }
  case 56 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_level error_level_ambient_temperature_tmp;
    error_level_ambient_temperature_tmp = (error_level)((msg.m_data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_ambient_temperature(error_level_ambient_temperature_tmp);
    break;
  }
  case 57 : {
    if (msg.m_header.m_sof == 1) {
      if (msg.m_header.m_toggle == 0 || msg.m_header.m_eof != 0) {
        return;
      }
      error_level_config_ambient_temperature_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_ambient_temperature_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_ambient_temperature_tmp_tx_fragmentation_offset >= 7) {
        return;
      }
    }
    error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[error_level_config_ambient_temperature_tmp_tx_fragmentation_offset] = msg.m_data;
    if (msg.m_header.m_eof == 0) {
      return;
    }
    error_level_config error_level_config_ambient_temperature_tmp;
    error_level_config_ambient_temperature_tmp.m_ignore_info = ((bool_t)(error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_ambient_temperature_tmp.m_info_thresh = ((error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_ambient_temperature_tmp.m_info_timeout = ((error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_ambient_temperature_tmp.m_ignore_warning = ((bool_t)(error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_ambient_temperature_tmp.m_warning_thresh = ((error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_ambient_temperature_tmp.m_warning_timeout = ((error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_ambient_temperature_tmp.m_ignore_error = ((bool_t)(error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 1))));
    error_level_config_ambient_temperature_tmp.m_error_thresh = ((error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_ambient_temperature_tmp.m_error_timeout = ((error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_ambient_temperature(error_level_config_ambient_temperature_tmp);
    break;
  }
  case 58 : {
    if (msg.m_header.m_sof != 1 || msg.m_header.m_toggle != 0 || msg.m_header.m_eof != 1) {
      return;
    }
    error_flag assertion_fault_tmp;
    assertion_fault_tmp = (error_flag)((msg.m_data & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_assertion_fault(assertion_fault_tmp);
    break;
  }
  default:
    return;
  }
  resp.m_header.m_od_index = msg.m_header.m_od_index;
  resp.m_header.m_client_id = msg.m_header.m_client_id;
  resp.m_header.m_server_id = msg.m_header.m_server_id;
  resp.m_header.m_erno = set_resp_erno_Success;
  canzero_frame resp_frame;
  canzero_serialize_canzero_message_set_resp(&resp, &resp_frame);
  canzero_can1_send(&resp_frame);

}
__attribute__((weak)) void canzero_handle_heartbeat(canzero_frame* frame) {
  canzero_message_heartbeat msg;
  canzero_deserialize_canzero_message_heartbeat(frame, &msg);
}
void canzero_can0_poll() {
  canzero_frame frame;
  while (canzero_can0_recv(&frame)) {
    switch (frame.id) {
      case 0x7F:
        canzero_handle_get_req(&frame);
        break;
      case 0x7E:
        canzero_handle_set_req(&frame);
        break;
      case 0x9F:
        canzero_handle_heartbeat(&frame);
        break;
    }
  }
}
void canzero_can1_poll() {
  canzero_frame frame;
  while (canzero_can1_recv(&frame)) {
    switch (frame.id) {
    }
  }
}
uint32_t canzero_update_continue(uint32_t time){
  schedule_jobs(time);
  return scheduler_next_job_timeout();
}
void canzero_init() {
  canzero_can0_setup(1000000, NULL, 0);
  canzero_can1_setup(1000000, NULL, 0);

  job_pool_allocator_init();
  scheduler.size = 0;
  schedule_heartbeat_job();
  schedule_state_interval_job();
  schedule_position_estimation_interval_job();
  schedule_bat24_interval_job();
  schedule_link24_interval_job();
  schedule_link45_interval_job();
  schedule_cooling_interval_job();
  schedule_temperatures_interval_job();
  schedule_errors_interval_job();

}
void canzero_set_state(input_board_state value) {
  extern input_board_state __oe_state;
  if (__oe_state != value) {
    __oe_state = value;
    uint32_t time = canzero_get_time();
    if (state_interval_job.climax > state_interval_job.job.stream_job.last_schedule + 0) {
      state_interval_job.climax = state_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&state_interval_job);
    }
  }
}
void canzero_set_sdc_status(sdc_status value) {
  extern sdc_status __oe_sdc_status;
  if (__oe_sdc_status != value) {
    __oe_sdc_status = value;
    uint32_t time = canzero_get_time();
    if (state_interval_job.climax > state_interval_job.job.stream_job.last_schedule + 0) {
      state_interval_job.climax = state_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&state_interval_job);
    }
  }
}
void canzero_set_error_level_bat24_under_voltage(error_level value) {
  extern error_level __oe_error_level_bat24_under_voltage;
  if (__oe_error_level_bat24_under_voltage != value) {
    __oe_error_level_bat24_under_voltage = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_bat24_over_voltage(error_level value) {
  extern error_level __oe_error_level_bat24_over_voltage;
  if (__oe_error_level_bat24_over_voltage != value) {
    __oe_error_level_bat24_over_voltage = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_bat24_over_current(error_level value) {
  extern error_level __oe_error_level_bat24_over_current;
  if (__oe_error_level_bat24_over_current != value) {
    __oe_error_level_bat24_over_current = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_link24_under_voltage(error_level value) {
  extern error_level __oe_error_level_link24_under_voltage;
  if (__oe_error_level_link24_under_voltage != value) {
    __oe_error_level_link24_under_voltage = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_link24_over_voltage(error_level value) {
  extern error_level __oe_error_level_link24_over_voltage;
  if (__oe_error_level_link24_over_voltage != value) {
    __oe_error_level_link24_over_voltage = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_link24_over_current(error_level value) {
  extern error_level __oe_error_level_link24_over_current;
  if (__oe_error_level_link24_over_current != value) {
    __oe_error_level_link24_over_current = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_link45_under_voltage(error_level value) {
  extern error_level __oe_error_level_link45_under_voltage;
  if (__oe_error_level_link45_under_voltage != value) {
    __oe_error_level_link45_under_voltage = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_link45_over_voltage(error_level value) {
  extern error_level __oe_error_level_link45_over_voltage;
  if (__oe_error_level_link45_over_voltage != value) {
    __oe_error_level_link45_over_voltage = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_link45_over_current(error_level value) {
  extern error_level __oe_error_level_link45_over_current;
  if (__oe_error_level_link45_over_current != value) {
    __oe_error_level_link45_over_current = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_cooling_cycle_under_pressure(error_level value) {
  extern error_level __oe_error_level_cooling_cycle_under_pressure;
  if (__oe_error_level_cooling_cycle_under_pressure != value) {
    __oe_error_level_cooling_cycle_under_pressure = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_cooling_cycle_over_pressure(error_level value) {
  extern error_level __oe_error_level_cooling_cycle_over_pressure;
  if (__oe_error_level_cooling_cycle_over_pressure != value) {
    __oe_error_level_cooling_cycle_over_pressure = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_mcu_temperature(error_level value) {
  extern error_level __oe_error_level_mcu_temperature;
  if (__oe_error_level_mcu_temperature != value) {
    __oe_error_level_mcu_temperature = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_cooling_cycle_temperature(error_level value) {
  extern error_level __oe_error_level_cooling_cycle_temperature;
  if (__oe_error_level_cooling_cycle_temperature != value) {
    __oe_error_level_cooling_cycle_temperature = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_bat24_temperature(error_level value) {
  extern error_level __oe_error_level_bat24_temperature;
  if (__oe_error_level_bat24_temperature != value) {
    __oe_error_level_bat24_temperature = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_supercap_temperature(error_level value) {
  extern error_level __oe_error_level_supercap_temperature;
  if (__oe_error_level_supercap_temperature != value) {
    __oe_error_level_supercap_temperature = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_buck_temperature(error_level value) {
  extern error_level __oe_error_level_buck_temperature;
  if (__oe_error_level_buck_temperature != value) {
    __oe_error_level_buck_temperature = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_ebox_temperature(error_level value) {
  extern error_level __oe_error_level_ebox_temperature;
  if (__oe_error_level_ebox_temperature != value) {
    __oe_error_level_ebox_temperature = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_ambient_temperature(error_level value) {
  extern error_level __oe_error_level_ambient_temperature;
  if (__oe_error_level_ambient_temperature != value) {
    __oe_error_level_ambient_temperature = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_assertion_fault(error_flag value) {
  extern error_flag __oe_assertion_fault;
  if (__oe_assertion_fault != value) {
    __oe_assertion_fault = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
