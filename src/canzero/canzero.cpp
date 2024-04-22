#include "canzero.h"
input_board_state __oe_state;
bool_t __oe_expect_link45_online;
float __oe_position_estimation;
error_level __oe_error_level_position_estimation;
float __oe_velocity_estimation;
error_level __oe_error_level_velocity_estimation;
float __oe_acceleration_estimation;
error_level __oe_error_level_acceleration_estimation;
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
error_level __oe_error_level_link45_under_voltage;
error_level_config __oe_error_level_config_link45_under_voltage;
error_level __oe_error_level_link45_over_voltage;
error_level_config __oe_error_level_config_link45_over_voltage;
float __oe_link45_current;
error_level __oe_error_level_link45_over_current;
error_level_config __oe_error_level_config_link45_over_current;
sdc_status __oe_sdc_status;
float __oe_cooling_cycle_pressure;
error_level __oe_error_level_cooling_cycle_under_pressure;
error_level_config __oe_error_level_config_cooling_cycle_under_pressure;
error_level __oe_error_level_cooling_cycle_over_pressure;
error_level_config __oe_error_level_config_cooling_cycle_over_pressure;
int16_t __oe_fiducial_count1;
int16_t __oe_fiducial_count2;
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
uint8_t __oe_battery_24V_temperature;
uint8_t __oe_error_level_bat24_over_currrent;

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
    stream_interval_job stream_interval_job;
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
  state_interval_job.job.stream_interval_job.stream_id = 0;
  state_interval_job.job.stream_interval_job.last_schedule = time;
  scheduler_schedule(&state_interval_job);
}
static job_t state_estimation_interval_job;
static const uint32_t state_estimation_interval = 50;
static void schedule_state_estimation_interval_job(){
  uint32_t time = canzero_get_time();
  state_estimation_interval_job.climax = time + state_estimation_interval;
  state_estimation_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  state_estimation_interval_job.job.stream_interval_job.stream_id = 1;
  state_estimation_interval_job.job.stream_interval_job.last_schedule = time;
  scheduler_schedule(&state_estimation_interval_job);
}
static job_t safety_sensors_interval_job;
static const uint32_t safety_sensors_interval = 1000;
static void schedule_safety_sensors_interval_job(){
  uint32_t time = canzero_get_time();
  safety_sensors_interval_job.climax = time + safety_sensors_interval;
  safety_sensors_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  safety_sensors_interval_job.job.stream_interval_job.stream_id = 2;
  safety_sensors_interval_job.job.stream_interval_job.last_schedule = time;
  scheduler_schedule(&safety_sensors_interval_job);
}
static job_t errors_interval_job;
static const uint32_t errors_interval = 0;
static void schedule_errors_interval_job(){
  uint32_t time = canzero_get_time();
  errors_interval_job.climax = time + errors_interval;
  errors_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  errors_interval_job.job.stream_interval_job.stream_id = 3;
  errors_interval_job.job.stream_interval_job.last_schedule = time;
  scheduler_schedule(&errors_interval_job);
}
static job_t sdc_status_interval_job;
static const uint32_t sdc_status_interval = 50;
static void schedule_sdc_status_interval_job(){
  uint32_t time = canzero_get_time();
  sdc_status_interval_job.climax = time + sdc_status_interval;
  sdc_status_interval_job.tag = STREAM_INTERVAL_JOB_TAG;
  sdc_status_interval_job.job.stream_interval_job.stream_id = 4;
  sdc_status_interval_job.job.stream_interval_job.last_schedule = time;
  scheduler_schedule(&sdc_status_interval_job);
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
      switch (job->job.stream_interval_job.stream_id) {
      case 0: {
        job->job.stream_interval_job.last_schedule = time;
        scheduler_reschedule(time + 1000);
        canzero_exit_critical();
        canzero_message_input_board_stream_state stream_message;
        stream_message.sdc_status = __oe_sdc_status;
        stream_message.state = __oe_state;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_state(&stream_message, &stream_frame);
        canzero_can1_send(&stream_frame);
        break;
      }
      case 1: {
        job->job.stream_interval_job.last_schedule = time;
        scheduler_reschedule(time + 50);
        canzero_exit_critical();
        canzero_message_input_board_stream_state_estimation stream_message;
        stream_message.position_estimation = __oe_position_estimation;
        stream_message.velocity_estimation = __oe_velocity_estimation;
        stream_message.acceleration_estimation = __oe_acceleration_estimation;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_state_estimation(&stream_message, &stream_frame);
        canzero_can0_send(&stream_frame);
        break;
      }
      case 2: {
        job->job.stream_interval_job.last_schedule = time;
        scheduler_reschedule(time + 1000);
        canzero_exit_critical();
        canzero_message_input_board_stream_safety_sensors stream_message;
        stream_message.mcu_temperature = __oe_mcu_temperature;
        stream_message.cooling_cycle_temperature = __oe_cooling_cycle_temperature;
        stream_message.battery_24V_temperature = __oe_battery_24V_temperature;
        stream_message.ebox_temperature = __oe_ebox_temperature;
        stream_message.cooling_cycle_pressure = __oe_cooling_cycle_pressure;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_safety_sensors(&stream_message, &stream_frame);
        canzero_can1_send(&stream_frame);
        break;
      }
      case 3: {
        job->job.stream_interval_job.last_schedule = time;
        scheduler_reschedule(time + 1000);
        canzero_exit_critical();
        canzero_message_input_board_stream_errors stream_message;
        stream_message.error_level_position_estimation = __oe_error_level_position_estimation;
        stream_message.error_level_velocity_estimation = __oe_error_level_velocity_estimation;
        stream_message.error_level_acceleration_estimation = __oe_error_level_acceleration_estimation;
        stream_message.error_level_bat24_under_voltage = __oe_error_level_bat24_under_voltage;
        stream_message.error_level_bat24_over_voltage = __oe_error_level_bat24_over_voltage;
        stream_message.error_level_bat24_over_currrent = __oe_error_level_bat24_over_currrent;
        stream_message.error_level_link24_under_voltage = __oe_error_level_link24_under_voltage;
        stream_message.error_level_link24_over_voltage = __oe_error_level_link24_over_voltage;
        stream_message.error_level_link24_over_current = __oe_error_level_link24_over_current;
        stream_message.error_level_link45_under_voltage = __oe_error_level_link45_under_voltage;
        stream_message.error_level_link45_over_voltage = __oe_error_level_link45_over_voltage;
        stream_message.error_level_link45_over_current = __oe_error_level_link45_over_current;
        stream_message.error_level_cooling_cycle_under_pressure = __oe_error_level_cooling_cycle_under_pressure;
        stream_message.error_level_cooling_cycle_over_pressure = __oe_error_level_cooling_cycle_over_pressure;
        stream_message.error_level_mcu_temperature = __oe_error_level_mcu_temperature;
        stream_message.error_level_cooling_cycle_temperature = __oe_error_level_cooling_cycle_temperature;
        stream_message.error_level_bat24_temperature = __oe_error_level_bat24_temperature;
        stream_message.error_level_supercap_temperature = __oe_error_level_supercap_temperature;
        stream_message.error_level_buck_temperature = __oe_error_level_buck_temperature;
        stream_message.error_level_ebox_temperature = __oe_error_level_ebox_temperature;
        stream_message.error_level_ambient_temperature = __oe_error_level_ambient_temperature;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_errors(&stream_message, &stream_frame);
        canzero_can0_send(&stream_frame);
        break;
      }
      case 4: {
        job->job.stream_interval_job.last_schedule = time;
        scheduler_reschedule(time + 500);
        canzero_exit_critical();
        canzero_message_input_board_stream_sdc_status stream_message;
        stream_message.sdc_status = __oe_sdc_status;
        canzero_frame stream_frame;
        canzero_serialize_canzero_message_input_board_stream_sdc_status(&stream_message, &stream_frame);
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
      heartbeat.node_id = node_id_input_board;
      canzero_frame heartbeat_frame;
      canzero_serialize_canzero_message_heartbeat(&heartbeat, &heartbeat_frame);
      canzero_can0_send(&heartbeat_frame);
      break;
    }
    case GET_RESP_FRAGMENTATION_JOB_TAG: {
      get_resp_fragmentation_job *fragmentation_job = &job->job.get_fragmentation_job;
      canzero_message_get_resp fragmentation_response;
      fragmentation_response.header.sof = 0;
      fragmentation_response.header.toggle = fragmentation_job->offset % 2;
      fragmentation_response.header.od_index = fragmentation_job->od_index;
      fragmentation_response.header.client_id = 0xC;
      fragmentation_response.header.server_id = fragmentation_job->server_id;
      fragmentation_response.data = fragmentation_job->buffer[fragmentation_job->offset];
      fragmentation_job->offset += 1;
      if (fragmentation_job->offset == fragmentation_job->size) {
        fragmentation_response.header.eof = 1;
        scheduler_unschedule();
      } else {
        fragmentation_response.header.eof = 0;
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
static uint32_t __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[6];
static uint32_t __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[6];
static uint32_t __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[6];
static uint32_t __oe_error_level_config_link24_under_voltage_rx_fragmentation_buffer[6];
static uint32_t __oe_error_level_config_link24_over_voltage_rx_fragmentation_buffer[6];
static uint32_t __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[6];
static uint32_t __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[6];
static uint32_t __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[6];
static uint32_t __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[6];
static uint32_t __oe_error_level_config_cooling_cycle_under_pressure_rx_fragmentation_buffer[6];
static uint32_t __oe_error_level_config_cooling_cycle_over_pressure_rx_fragmentation_buffer[6];
static uint32_t __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[6];
static uint32_t __oe_error_level_config_cooling_temperature_rx_fragmentation_buffer[6];
static uint32_t __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[6];
static uint32_t __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[6];
static uint32_t __oe_error_level_config_buck_temperature_rx_fragmentation_buffer[6];
static uint32_t __oe_error_level_config_ebox_temperature_rx_fragmentation_buffer[6];
static uint32_t __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[6];
static void canzero_handle_get_req(canzero_frame* frame) {
  canzero_message_get_req msg;
  canzero_deserialize_canzero_message_get_req(frame, &msg);
  if (msg.header.server_id != 12) {
    return;
  }
  canzero_message_get_resp resp;
  switch (msg.header.od_index) {
  case 0: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_state) & (0xFF >> (8 - 1)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 1: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_expect_link45_online) & (0xFF >> (8 - 1)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 2: {
    resp.data |= ((uint32_t)((__oe_position_estimation - (-100)) / 0.00000004656612874161595)) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 3: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_error_level_position_estimation) & (0xFF >> (8 - 2)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 4: {
    resp.data |= ((uint32_t)((__oe_velocity_estimation - (-10)) / 0.00030518043793392844)) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 5: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_error_level_velocity_estimation) & (0xFF >> (8 - 2)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 6: {
    resp.data |= ((uint32_t)((__oe_acceleration_estimation - (-5)) / 0.00008392462043183032)) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 7: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_error_level_acceleration_estimation) & (0xFF >> (8 - 2)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 8: {
    resp.data |= ((uint32_t)((__oe_track_length - (0)) / 0.000000011641532185403987)) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 9: {
    resp.data |= ((uint32_t)((__oe_bat24_voltage - (0)) / 0.000000011641532185403987)) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 10: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_error_level_bat24_under_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 11: {
    __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_under_voltage.info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_under_voltage.info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_under_voltage.warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_under_voltage.warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_under_voltage.error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_under_voltage.error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.data = __oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer[0];
    resp.header.sof = 1;
    resp.header.eof = 0;
    resp.header.toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_bat24_under_voltage_rx_fragmentation_buffer, 6, 11, msg.header.server_id);
    break;
  }
  case 12: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_error_level_bat24_over_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 13: {
    __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_over_voltage.info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_over_voltage.info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_over_voltage.warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_over_voltage.warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_over_voltage.error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_over_voltage.error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.data = __oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer[0];
    resp.header.sof = 1;
    resp.header.eof = 0;
    resp.header.toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_bat24_over_voltage_rx_fragmentation_buffer, 6, 13, msg.header.server_id);
    break;
  }
  case 14: {
    resp.data |= ((uint32_t)((__oe_bat24_current - (-30)) / 0.000000013969838622484784)) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 15: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_error_level_bat24_over_current) & (0xFF >> (8 - 2)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 16: {
    __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_over_current.info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_over_current.info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_over_current.warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_over_current.warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_over_current.error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_over_current.error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.data = __oe_error_level_config_bat24_over_current_rx_fragmentation_buffer[0];
    resp.header.sof = 1;
    resp.header.eof = 0;
    resp.header.toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_bat24_over_current_rx_fragmentation_buffer, 6, 16, msg.header.server_id);
    break;
  }
  case 17: {
    resp.data |= ((uint32_t)((__oe_link24_voltage - (0)) / 0.000000011641532185403987)) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 18: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_error_level_link24_under_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 19: {
    __oe_error_level_config_link24_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_under_voltage.info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_under_voltage.info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_under_voltage.warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_under_voltage.warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_under_voltage.error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_under_voltage.error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.data = __oe_error_level_config_link24_under_voltage_rx_fragmentation_buffer[0];
    resp.header.sof = 1;
    resp.header.eof = 0;
    resp.header.toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_link24_under_voltage_rx_fragmentation_buffer, 6, 19, msg.header.server_id);
    break;
  }
  case 20: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_error_level_link24_over_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 21: {
    __oe_error_level_config_link24_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_over_voltage.info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_over_voltage.info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_over_voltage.warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_over_voltage.warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_over_voltage.error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_over_voltage.error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.data = __oe_error_level_config_link24_over_voltage_rx_fragmentation_buffer[0];
    resp.header.sof = 1;
    resp.header.eof = 0;
    resp.header.toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_link24_over_voltage_rx_fragmentation_buffer, 6, 21, msg.header.server_id);
    break;
  }
  case 22: {
    resp.data |= ((uint32_t)((__oe_link24_current - (-30)) / 0.000000013969838622484784)) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 23: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_error_level_link24_over_current) & (0xFF >> (8 - 2)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 24: {
    __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_over_current.info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_over_current.info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_over_current.warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_over_current.warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_over_current.error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link24_over_current.error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.data = __oe_error_level_config_link24_over_current_rx_fragmentation_buffer[0];
    resp.header.sof = 1;
    resp.header.eof = 0;
    resp.header.toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_link24_over_current_rx_fragmentation_buffer, 6, 24, msg.header.server_id);
    break;
  }
  case 25: {
    resp.data |= ((uint32_t)((__oe_link45_voltage - (0)) / 0.00000023283064370807974)) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 26: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_error_level_link45_under_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 27: {
    __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_under_voltage.info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_under_voltage.info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_under_voltage.warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_under_voltage.warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_under_voltage.error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_under_voltage.error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.data = __oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer[0];
    resp.header.sof = 1;
    resp.header.eof = 0;
    resp.header.toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_link45_under_voltage_rx_fragmentation_buffer, 6, 27, msg.header.server_id);
    break;
  }
  case 28: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_error_level_link45_over_voltage) & (0xFF >> (8 - 2)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 29: {
    __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_over_voltage.info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_over_voltage.info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_over_voltage.warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_over_voltage.warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_over_voltage.error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_over_voltage.error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.data = __oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer[0];
    resp.header.sof = 1;
    resp.header.eof = 0;
    resp.header.toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_link45_over_voltage_rx_fragmentation_buffer, 6, 29, msg.header.server_id);
    break;
  }
  case 30: {
    resp.data |= ((uint32_t)((__oe_link45_current - (-1000)) / 0.0000004656612874161595)) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 31: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_error_level_link45_over_current) & (0xFF >> (8 - 2)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 32: {
    __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_over_current.info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_over_current.info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_over_current.warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_over_current.warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_over_current.error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_link45_over_current.error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.data = __oe_error_level_config_link45_over_current_rx_fragmentation_buffer[0];
    resp.header.sof = 1;
    resp.header.eof = 0;
    resp.header.toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_link45_over_current_rx_fragmentation_buffer, 6, 32, msg.header.server_id);
    break;
  }
  case 33: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_sdc_status) & (0xFF >> (8 - 1)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 34: {
    resp.data |= ((uint32_t)((__oe_cooling_cycle_pressure - (-1)) / 0.0392156862745098)) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 35: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_error_level_cooling_cycle_under_pressure) & (0xFF >> (8 - 2)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 36: {
    __oe_error_level_config_cooling_cycle_under_pressure_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_cycle_under_pressure.info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_cooling_cycle_under_pressure_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_cycle_under_pressure.info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_cooling_cycle_under_pressure_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_cycle_under_pressure.warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_cooling_cycle_under_pressure_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_cycle_under_pressure.warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_cooling_cycle_under_pressure_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_cycle_under_pressure.error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_cooling_cycle_under_pressure_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_cycle_under_pressure.error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.data = __oe_error_level_config_cooling_cycle_under_pressure_rx_fragmentation_buffer[0];
    resp.header.sof = 1;
    resp.header.eof = 0;
    resp.header.toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_cooling_cycle_under_pressure_rx_fragmentation_buffer, 6, 36, msg.header.server_id);
    break;
  }
  case 37: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_error_level_cooling_cycle_over_pressure) & (0xFF >> (8 - 2)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 38: {
    __oe_error_level_config_cooling_cycle_over_pressure_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_cycle_over_pressure.info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_cooling_cycle_over_pressure_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_cycle_over_pressure.info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_cooling_cycle_over_pressure_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_cycle_over_pressure.warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_cooling_cycle_over_pressure_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_cycle_over_pressure.warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_cooling_cycle_over_pressure_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_cycle_over_pressure.error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_cooling_cycle_over_pressure_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_cycle_over_pressure.error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.data = __oe_error_level_config_cooling_cycle_over_pressure_rx_fragmentation_buffer[0];
    resp.header.sof = 1;
    resp.header.eof = 0;
    resp.header.toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_cooling_cycle_over_pressure_rx_fragmentation_buffer, 6, 38, msg.header.server_id);
    break;
  }
  case 39: {
    resp.data |= ((uint32_t)(((uint16_t)__oe_fiducial_count1) & (0xFFFF >> (16 - 16)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 40: {
    resp.data |= ((uint32_t)(((uint16_t)__oe_fiducial_count2) & (0xFFFF >> (16 - 16)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 41: {
    resp.data |= ((uint32_t)((__oe_mcu_temperature - (-1)) / 0.592156862745098)) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 42: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_error_level_mcu_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 43: {
    __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_mcu_temperature.info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_mcu_temperature.info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_mcu_temperature.warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_mcu_temperature.warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_mcu_temperature.error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_mcu_temperature.error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.data = __oe_error_level_config_mcu_temperature_rx_fragmentation_buffer[0];
    resp.header.sof = 1;
    resp.header.eof = 0;
    resp.header.toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_mcu_temperature_rx_fragmentation_buffer, 6, 43, msg.header.server_id);
    break;
  }
  case 44: {
    resp.data |= ((uint32_t)((__oe_cooling_cycle_temperature - (-1)) / 0.592156862745098)) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 45: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_error_level_cooling_cycle_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 46: {
    __oe_error_level_config_cooling_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_temperature.info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_cooling_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_temperature.info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_cooling_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_temperature.warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_cooling_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_temperature.warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_cooling_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_temperature.error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_cooling_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_cooling_temperature.error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.data = __oe_error_level_config_cooling_temperature_rx_fragmentation_buffer[0];
    resp.header.sof = 1;
    resp.header.eof = 0;
    resp.header.toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_cooling_temperature_rx_fragmentation_buffer, 6, 46, msg.header.server_id);
    break;
  }
  case 47: {
    resp.data |= ((uint32_t)((__oe_bat24_temperature - (-1)) / 0.592156862745098)) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 48: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_error_level_bat24_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 49: {
    __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_temperature.info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_temperature.info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_temperature.warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_temperature.warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_temperature.error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_bat24_temperature.error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.data = __oe_error_level_config_bat24_temperature_rx_fragmentation_buffer[0];
    resp.header.sof = 1;
    resp.header.eof = 0;
    resp.header.toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_bat24_temperature_rx_fragmentation_buffer, 6, 49, msg.header.server_id);
    break;
  }
  case 50: {
    resp.data |= ((uint32_t)((__oe_supercap_temperature - (-1)) / 0.592156862745098)) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 51: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_error_level_supercap_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 52: {
    __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_supercap_temperature.info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_supercap_temperature.info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_supercap_temperature.warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_supercap_temperature.warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_supercap_temperature.error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_supercap_temperature.error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.data = __oe_error_level_config_supercap_temperature_rx_fragmentation_buffer[0];
    resp.header.sof = 1;
    resp.header.eof = 0;
    resp.header.toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_supercap_temperature_rx_fragmentation_buffer, 6, 52, msg.header.server_id);
    break;
  }
  case 53: {
    resp.data |= ((uint32_t)((__oe_buck_temperature - (-1)) / 0.592156862745098)) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 54: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_error_level_buck_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 55: {
    __oe_error_level_config_buck_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_buck_temperature.info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_buck_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_buck_temperature.info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_buck_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_buck_temperature.warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_buck_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_buck_temperature.warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_buck_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_buck_temperature.error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_buck_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_buck_temperature.error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.data = __oe_error_level_config_buck_temperature_rx_fragmentation_buffer[0];
    resp.header.sof = 1;
    resp.header.eof = 0;
    resp.header.toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_buck_temperature_rx_fragmentation_buffer, 6, 55, msg.header.server_id);
    break;
  }
  case 56: {
    resp.data |= ((uint32_t)((__oe_ebox_temperature - (-1)) / 0.592156862745098)) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 57: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_error_level_ebox_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 58: {
    __oe_error_level_config_ebox_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_ebox_temperature.info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_ebox_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_ebox_temperature.info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_ebox_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_ebox_temperature.warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_ebox_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_ebox_temperature.warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_ebox_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_ebox_temperature.error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_ebox_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_ebox_temperature.error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.data = __oe_error_level_config_ebox_temperature_rx_fragmentation_buffer[0];
    resp.header.sof = 1;
    resp.header.eof = 0;
    resp.header.toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_ebox_temperature_rx_fragmentation_buffer, 6, 58, msg.header.server_id);
    break;
  }
  case 59: {
    resp.data |= ((uint32_t)((__oe_ambient_temperature - (-1)) / 0.592156862745098)) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 60: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_error_level_ambient_temperature) & (0xFF >> (8 - 2)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 61: {
    __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_ambient_temperature.info_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_ambient_temperature.info_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_ambient_temperature.warning_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_ambient_temperature.warning_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_ambient_temperature.error_thresh - ((float)-10000)) / (float)0.000004656612874161595)) & (0xFFFFFFFF >> (32 - 32)));
    __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[0] = (((uint32_t)((__oe_error_level_config_ambient_temperature.error_timeout - ((float)0)) / (float)0.000000013969838622484784)) & (0xFFFFFFFF >> (32 - 32)));

    resp.data = __oe_error_level_config_ambient_temperature_rx_fragmentation_buffer[0];
    resp.header.sof = 1;
    resp.header.eof = 0;
    resp.header.toggle = 0;
    schedule_get_resp_fragmentation_job(__oe_error_level_config_ambient_temperature_rx_fragmentation_buffer, 6, 61, msg.header.server_id);
    break;
  }
  case 62: {
    resp.data |= ((uint32_t)(((uint8_t)__oe_assertion_fault) & (0xFF >> (8 - 1)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 63: {
    resp.data |= ((uint32_t)(__oe_battery_24V_temperature & (0xFF >> (8 - 1)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  case 64: {
    resp.data |= ((uint32_t)(__oe_error_level_bat24_over_currrent & (0xFF >> (8 - 1)))) << 0;
    resp.header.sof = 1;
    resp.header.eof = 1;
    resp.header.toggle = 0;
    break;
  }
  }
  resp.header.od_index = msg.header.od_index;
  resp.header.client_id = msg.header.client_id;
  resp.header.server_id = msg.header.server_id;
  canzero_frame resp_frame;
  canzero_serialize_canzero_message_get_resp(&resp, &resp_frame);
  canzero_can0_send(&resp_frame);
}
static uint32_t error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[6];
static uint32_t error_level_config_bat24_under_voltage_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[6];
static uint32_t error_level_config_bat24_over_voltage_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[6];
static uint32_t error_level_config_bat24_over_current_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_link24_under_voltage_tmp_tx_fragmentation_buffer[6];
static uint32_t error_level_config_link24_under_voltage_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_link24_over_voltage_tmp_tx_fragmentation_buffer[6];
static uint32_t error_level_config_link24_over_voltage_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[6];
static uint32_t error_level_config_link24_over_current_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[6];
static uint32_t error_level_config_link45_under_voltage_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[6];
static uint32_t error_level_config_link45_over_voltage_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[6];
static uint32_t error_level_config_link45_over_current_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_buffer[6];
static uint32_t error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_buffer[6];
static uint32_t error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[6];
static uint32_t error_level_config_mcu_temperature_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_cooling_temperature_tmp_tx_fragmentation_buffer[6];
static uint32_t error_level_config_cooling_temperature_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[6];
static uint32_t error_level_config_bat24_temperature_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[6];
static uint32_t error_level_config_supercap_temperature_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_buck_temperature_tmp_tx_fragmentation_buffer[6];
static uint32_t error_level_config_buck_temperature_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_ebox_temperature_tmp_tx_fragmentation_buffer[6];
static uint32_t error_level_config_ebox_temperature_tmp_tx_fragmentation_offset = 0;
static uint32_t error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[6];
static uint32_t error_level_config_ambient_temperature_tmp_tx_fragmentation_offset = 0;
static void canzero_handle_set_req(canzero_frame* frame) {
  canzero_message_set_req msg;
  canzero_deserialize_canzero_message_set_req(frame, &msg);
  if (msg.header.server_id != 12) {
    return;
  }
  canzero_message_set_resp resp;
  switch (msg.header.od_index) {
  case 0 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    input_board_state state_tmp;
    state_tmp = (input_board_state)((msg.data & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_state(state_tmp);
    break;
  }
  case 1 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    bool_t expect_link45_online_tmp;
    expect_link45_online_tmp = (bool_t)((msg.data & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_expect_link45_online(expect_link45_online_tmp);
    break;
  }
  case 2 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    float position_estimation_tmp;
    position_estimation_tmp = (float)((msg.data & (0xFFFFFFFF >> (32 - 32))) * 0.00000004656612874161595 + -100);
    canzero_set_position_estimation(position_estimation_tmp);
    break;
  }
  case 3 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    error_level error_level_position_estimation_tmp;
    error_level_position_estimation_tmp = (error_level)((msg.data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_position_estimation(error_level_position_estimation_tmp);
    break;
  }
  case 4 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    float velocity_estimation_tmp;
    velocity_estimation_tmp = (float)((msg.data & (0xFFFFFFFF >> (32 - 16))) * 0.00030518043793392844 + -10);
    canzero_set_velocity_estimation(velocity_estimation_tmp);
    break;
  }
  case 5 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    error_level error_level_velocity_estimation_tmp;
    error_level_velocity_estimation_tmp = (error_level)((msg.data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_velocity_estimation(error_level_velocity_estimation_tmp);
    break;
  }
  case 6 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    float acceleration_estimation_tmp;
    acceleration_estimation_tmp = (float)((msg.data & (0xFFFFFFFF >> (32 - 16))) * 0.00008392462043183032 + -5);
    canzero_set_acceleration_estimation(acceleration_estimation_tmp);
    break;
  }
  case 7 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    error_level error_level_acceleration_estimation_tmp;
    error_level_acceleration_estimation_tmp = (error_level)((msg.data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_acceleration_estimation(error_level_acceleration_estimation_tmp);
    break;
  }
  case 8 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    float track_length_tmp;
    track_length_tmp = (float)((msg.data & (0xFFFFFFFF >> (32 - 32))) * 0.000000011641532185403987 + 0);
    canzero_set_track_length(track_length_tmp);
    break;
  }
  case 9 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    float bat24_voltage_tmp;
    bat24_voltage_tmp = (float)((msg.data & (0xFFFFFFFF >> (32 - 32))) * 0.000000011641532185403987 + 0);
    canzero_set_bat24_voltage(bat24_voltage_tmp);
    break;
  }
  case 10 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    error_level error_level_bat24_under_voltage_tmp;
    error_level_bat24_under_voltage_tmp = (error_level)((msg.data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_bat24_under_voltage(error_level_bat24_under_voltage_tmp);
    break;
  }
  case 11 : {
    if (msg.header.sof == 1) {
      if (msg.header.toggle == 0 || msg.header.eof != 0) {
        return;
      }
      error_level_config_bat24_under_voltage_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_bat24_under_voltage_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_bat24_under_voltage_tmp_tx_fragmentation_offset >= 6) {
        return;
      }
    }
    error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[error_level_config_bat24_under_voltage_tmp_tx_fragmentation_offset] = msg.data;
    if (msg.header.eof == 0) {
      return;
    }
    error_level_config error_level_config_bat24_under_voltage_tmp;
    error_level_config_bat24_under_voltage_tmp.info_thresh = ((error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_bat24_under_voltage_tmp.info_timeout = ((error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_under_voltage_tmp.warning_thresh = ((error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_bat24_under_voltage_tmp.warning_timeout = ((error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_under_voltage_tmp.error_thresh = ((error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_bat24_under_voltage_tmp.error_timeout = ((error_level_config_bat24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_bat24_under_voltage(error_level_config_bat24_under_voltage_tmp);
    break;
  }
  case 12 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    error_level error_level_bat24_over_voltage_tmp;
    error_level_bat24_over_voltage_tmp = (error_level)((msg.data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_bat24_over_voltage(error_level_bat24_over_voltage_tmp);
    break;
  }
  case 13 : {
    if (msg.header.sof == 1) {
      if (msg.header.toggle == 0 || msg.header.eof != 0) {
        return;
      }
      error_level_config_bat24_over_voltage_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_bat24_over_voltage_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_bat24_over_voltage_tmp_tx_fragmentation_offset >= 6) {
        return;
      }
    }
    error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[error_level_config_bat24_over_voltage_tmp_tx_fragmentation_offset] = msg.data;
    if (msg.header.eof == 0) {
      return;
    }
    error_level_config error_level_config_bat24_over_voltage_tmp;
    error_level_config_bat24_over_voltage_tmp.info_thresh = ((error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_bat24_over_voltage_tmp.info_timeout = ((error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_over_voltage_tmp.warning_thresh = ((error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_bat24_over_voltage_tmp.warning_timeout = ((error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_over_voltage_tmp.error_thresh = ((error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_bat24_over_voltage_tmp.error_timeout = ((error_level_config_bat24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_bat24_over_voltage(error_level_config_bat24_over_voltage_tmp);
    break;
  }
  case 14 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    float bat24_current_tmp;
    bat24_current_tmp = (float)((msg.data & (0xFFFFFFFF >> (32 - 32))) * 0.000000013969838622484784 + -30);
    canzero_set_bat24_current(bat24_current_tmp);
    break;
  }
  case 15 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    error_level error_level_bat24_over_current_tmp;
    error_level_bat24_over_current_tmp = (error_level)((msg.data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_bat24_over_current(error_level_bat24_over_current_tmp);
    break;
  }
  case 16 : {
    if (msg.header.sof == 1) {
      if (msg.header.toggle == 0 || msg.header.eof != 0) {
        return;
      }
      error_level_config_bat24_over_current_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_bat24_over_current_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_bat24_over_current_tmp_tx_fragmentation_offset >= 6) {
        return;
      }
    }
    error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[error_level_config_bat24_over_current_tmp_tx_fragmentation_offset] = msg.data;
    if (msg.header.eof == 0) {
      return;
    }
    error_level_config error_level_config_bat24_over_current_tmp;
    error_level_config_bat24_over_current_tmp.info_thresh = ((error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_bat24_over_current_tmp.info_timeout = ((error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_over_current_tmp.warning_thresh = ((error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_bat24_over_current_tmp.warning_timeout = ((error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_over_current_tmp.error_thresh = ((error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_bat24_over_current_tmp.error_timeout = ((error_level_config_bat24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_bat24_over_current(error_level_config_bat24_over_current_tmp);
    break;
  }
  case 17 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    float link24_voltage_tmp;
    link24_voltage_tmp = (float)((msg.data & (0xFFFFFFFF >> (32 - 32))) * 0.000000011641532185403987 + 0);
    canzero_set_link24_voltage(link24_voltage_tmp);
    break;
  }
  case 18 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    error_level error_level_link24_under_voltage_tmp;
    error_level_link24_under_voltage_tmp = (error_level)((msg.data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_link24_under_voltage(error_level_link24_under_voltage_tmp);
    break;
  }
  case 19 : {
    if (msg.header.sof == 1) {
      if (msg.header.toggle == 0 || msg.header.eof != 0) {
        return;
      }
      error_level_config_link24_under_voltage_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_link24_under_voltage_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_link24_under_voltage_tmp_tx_fragmentation_offset >= 6) {
        return;
      }
    }
    error_level_config_link24_under_voltage_tmp_tx_fragmentation_buffer[error_level_config_link24_under_voltage_tmp_tx_fragmentation_offset] = msg.data;
    if (msg.header.eof == 0) {
      return;
    }
    error_level_config error_level_config_link24_under_voltage_tmp;
    error_level_config_link24_under_voltage_tmp.info_thresh = ((error_level_config_link24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link24_under_voltage_tmp.info_timeout = ((error_level_config_link24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link24_under_voltage_tmp.warning_thresh = ((error_level_config_link24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link24_under_voltage_tmp.warning_timeout = ((error_level_config_link24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link24_under_voltage_tmp.error_thresh = ((error_level_config_link24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link24_under_voltage_tmp.error_timeout = ((error_level_config_link24_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_link24_under_voltage(error_level_config_link24_under_voltage_tmp);
    break;
  }
  case 20 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    error_level error_level_link24_over_voltage_tmp;
    error_level_link24_over_voltage_tmp = (error_level)((msg.data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_link24_over_voltage(error_level_link24_over_voltage_tmp);
    break;
  }
  case 21 : {
    if (msg.header.sof == 1) {
      if (msg.header.toggle == 0 || msg.header.eof != 0) {
        return;
      }
      error_level_config_link24_over_voltage_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_link24_over_voltage_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_link24_over_voltage_tmp_tx_fragmentation_offset >= 6) {
        return;
      }
    }
    error_level_config_link24_over_voltage_tmp_tx_fragmentation_buffer[error_level_config_link24_over_voltage_tmp_tx_fragmentation_offset] = msg.data;
    if (msg.header.eof == 0) {
      return;
    }
    error_level_config error_level_config_link24_over_voltage_tmp;
    error_level_config_link24_over_voltage_tmp.info_thresh = ((error_level_config_link24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link24_over_voltage_tmp.info_timeout = ((error_level_config_link24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link24_over_voltage_tmp.warning_thresh = ((error_level_config_link24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link24_over_voltage_tmp.warning_timeout = ((error_level_config_link24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link24_over_voltage_tmp.error_thresh = ((error_level_config_link24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link24_over_voltage_tmp.error_timeout = ((error_level_config_link24_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_link24_over_voltage(error_level_config_link24_over_voltage_tmp);
    break;
  }
  case 22 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    float link24_current_tmp;
    link24_current_tmp = (float)((msg.data & (0xFFFFFFFF >> (32 - 32))) * 0.000000013969838622484784 + -30);
    canzero_set_link24_current(link24_current_tmp);
    break;
  }
  case 23 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    error_level error_level_link24_over_current_tmp;
    error_level_link24_over_current_tmp = (error_level)((msg.data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_link24_over_current(error_level_link24_over_current_tmp);
    break;
  }
  case 24 : {
    if (msg.header.sof == 1) {
      if (msg.header.toggle == 0 || msg.header.eof != 0) {
        return;
      }
      error_level_config_link24_over_current_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_link24_over_current_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_link24_over_current_tmp_tx_fragmentation_offset >= 6) {
        return;
      }
    }
    error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[error_level_config_link24_over_current_tmp_tx_fragmentation_offset] = msg.data;
    if (msg.header.eof == 0) {
      return;
    }
    error_level_config error_level_config_link24_over_current_tmp;
    error_level_config_link24_over_current_tmp.info_thresh = ((error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link24_over_current_tmp.info_timeout = ((error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link24_over_current_tmp.warning_thresh = ((error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link24_over_current_tmp.warning_timeout = ((error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link24_over_current_tmp.error_thresh = ((error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link24_over_current_tmp.error_timeout = ((error_level_config_link24_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_link24_over_current(error_level_config_link24_over_current_tmp);
    break;
  }
  case 25 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    float link45_voltage_tmp;
    link45_voltage_tmp = (float)((msg.data & (0xFFFFFFFF >> (32 - 32))) * 0.00000023283064370807974 + 0);
    canzero_set_link45_voltage(link45_voltage_tmp);
    break;
  }
  case 26 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    error_level error_level_link45_under_voltage_tmp;
    error_level_link45_under_voltage_tmp = (error_level)((msg.data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_link45_under_voltage(error_level_link45_under_voltage_tmp);
    break;
  }
  case 27 : {
    if (msg.header.sof == 1) {
      if (msg.header.toggle == 0 || msg.header.eof != 0) {
        return;
      }
      error_level_config_link45_under_voltage_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_link45_under_voltage_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_link45_under_voltage_tmp_tx_fragmentation_offset >= 6) {
        return;
      }
    }
    error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[error_level_config_link45_under_voltage_tmp_tx_fragmentation_offset] = msg.data;
    if (msg.header.eof == 0) {
      return;
    }
    error_level_config error_level_config_link45_under_voltage_tmp;
    error_level_config_link45_under_voltage_tmp.info_thresh = ((error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link45_under_voltage_tmp.info_timeout = ((error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link45_under_voltage_tmp.warning_thresh = ((error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link45_under_voltage_tmp.warning_timeout = ((error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link45_under_voltage_tmp.error_thresh = ((error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link45_under_voltage_tmp.error_timeout = ((error_level_config_link45_under_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_link45_under_voltage(error_level_config_link45_under_voltage_tmp);
    break;
  }
  case 28 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    error_level error_level_link45_over_voltage_tmp;
    error_level_link45_over_voltage_tmp = (error_level)((msg.data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_link45_over_voltage(error_level_link45_over_voltage_tmp);
    break;
  }
  case 29 : {
    if (msg.header.sof == 1) {
      if (msg.header.toggle == 0 || msg.header.eof != 0) {
        return;
      }
      error_level_config_link45_over_voltage_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_link45_over_voltage_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_link45_over_voltage_tmp_tx_fragmentation_offset >= 6) {
        return;
      }
    }
    error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[error_level_config_link45_over_voltage_tmp_tx_fragmentation_offset] = msg.data;
    if (msg.header.eof == 0) {
      return;
    }
    error_level_config error_level_config_link45_over_voltage_tmp;
    error_level_config_link45_over_voltage_tmp.info_thresh = ((error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link45_over_voltage_tmp.info_timeout = ((error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link45_over_voltage_tmp.warning_thresh = ((error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link45_over_voltage_tmp.warning_timeout = ((error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link45_over_voltage_tmp.error_thresh = ((error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link45_over_voltage_tmp.error_timeout = ((error_level_config_link45_over_voltage_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_link45_over_voltage(error_level_config_link45_over_voltage_tmp);
    break;
  }
  case 30 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    float link45_current_tmp;
    link45_current_tmp = (float)((msg.data & (0xFFFFFFFF >> (32 - 32))) * 0.0000004656612874161595 + -1000);
    canzero_set_link45_current(link45_current_tmp);
    break;
  }
  case 31 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    error_level error_level_link45_over_current_tmp;
    error_level_link45_over_current_tmp = (error_level)((msg.data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_link45_over_current(error_level_link45_over_current_tmp);
    break;
  }
  case 32 : {
    if (msg.header.sof == 1) {
      if (msg.header.toggle == 0 || msg.header.eof != 0) {
        return;
      }
      error_level_config_link45_over_current_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_link45_over_current_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_link45_over_current_tmp_tx_fragmentation_offset >= 6) {
        return;
      }
    }
    error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[error_level_config_link45_over_current_tmp_tx_fragmentation_offset] = msg.data;
    if (msg.header.eof == 0) {
      return;
    }
    error_level_config error_level_config_link45_over_current_tmp;
    error_level_config_link45_over_current_tmp.info_thresh = ((error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link45_over_current_tmp.info_timeout = ((error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link45_over_current_tmp.warning_thresh = ((error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link45_over_current_tmp.warning_timeout = ((error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_link45_over_current_tmp.error_thresh = ((error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_link45_over_current_tmp.error_timeout = ((error_level_config_link45_over_current_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_link45_over_current(error_level_config_link45_over_current_tmp);
    break;
  }
  case 33 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    sdc_status sdc_status_tmp;
    sdc_status_tmp = (sdc_status)((msg.data & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_sdc_status(sdc_status_tmp);
    break;
  }
  case 34 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    float cooling_cycle_pressure_tmp;
    cooling_cycle_pressure_tmp = (float)((msg.data & (0xFFFFFFFF >> (32 - 8))) * 0.0392156862745098 + -1);
    canzero_set_cooling_cycle_pressure(cooling_cycle_pressure_tmp);
    break;
  }
  case 35 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    error_level error_level_cooling_cycle_under_pressure_tmp;
    error_level_cooling_cycle_under_pressure_tmp = (error_level)((msg.data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_cooling_cycle_under_pressure(error_level_cooling_cycle_under_pressure_tmp);
    break;
  }
  case 36 : {
    if (msg.header.sof == 1) {
      if (msg.header.toggle == 0 || msg.header.eof != 0) {
        return;
      }
      error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_offset >= 6) {
        return;
      }
    }
    error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_buffer[error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_offset] = msg.data;
    if (msg.header.eof == 0) {
      return;
    }
    error_level_config error_level_config_cooling_cycle_under_pressure_tmp;
    error_level_config_cooling_cycle_under_pressure_tmp.info_thresh = ((error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_cooling_cycle_under_pressure_tmp.info_timeout = ((error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_cooling_cycle_under_pressure_tmp.warning_thresh = ((error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_cooling_cycle_under_pressure_tmp.warning_timeout = ((error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_cooling_cycle_under_pressure_tmp.error_thresh = ((error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_cooling_cycle_under_pressure_tmp.error_timeout = ((error_level_config_cooling_cycle_under_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_cooling_cycle_under_pressure(error_level_config_cooling_cycle_under_pressure_tmp);
    break;
  }
  case 37 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    error_level error_level_cooling_cycle_over_pressure_tmp;
    error_level_cooling_cycle_over_pressure_tmp = (error_level)((msg.data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_cooling_cycle_over_pressure(error_level_cooling_cycle_over_pressure_tmp);
    break;
  }
  case 38 : {
    if (msg.header.sof == 1) {
      if (msg.header.toggle == 0 || msg.header.eof != 0) {
        return;
      }
      error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_offset >= 6) {
        return;
      }
    }
    error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_buffer[error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_offset] = msg.data;
    if (msg.header.eof == 0) {
      return;
    }
    error_level_config error_level_config_cooling_cycle_over_pressure_tmp;
    error_level_config_cooling_cycle_over_pressure_tmp.info_thresh = ((error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_cooling_cycle_over_pressure_tmp.info_timeout = ((error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_cooling_cycle_over_pressure_tmp.warning_thresh = ((error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_cooling_cycle_over_pressure_tmp.warning_timeout = ((error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_cooling_cycle_over_pressure_tmp.error_thresh = ((error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_cooling_cycle_over_pressure_tmp.error_timeout = ((error_level_config_cooling_cycle_over_pressure_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_cooling_cycle_over_pressure(error_level_config_cooling_cycle_over_pressure_tmp);
    break;
  }
  case 39 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    int16_t fiducial_count1_tmp;
    fiducial_count1_tmp = (int16_t)(msg.data & (0xFFFFFFFF >> (32 - 16)));
    canzero_set_fiducial_count1(fiducial_count1_tmp);
    break;
  }
  case 40 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    int16_t fiducial_count2_tmp;
    fiducial_count2_tmp = (int16_t)(msg.data & (0xFFFFFFFF >> (32 - 16)));
    canzero_set_fiducial_count2(fiducial_count2_tmp);
    break;
  }
  case 41 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    float mcu_temperature_tmp;
    mcu_temperature_tmp = (float)((msg.data & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_mcu_temperature(mcu_temperature_tmp);
    break;
  }
  case 42 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    error_level error_level_mcu_temperature_tmp;
    error_level_mcu_temperature_tmp = (error_level)((msg.data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_mcu_temperature(error_level_mcu_temperature_tmp);
    break;
  }
  case 43 : {
    if (msg.header.sof == 1) {
      if (msg.header.toggle == 0 || msg.header.eof != 0) {
        return;
      }
      error_level_config_mcu_temperature_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_mcu_temperature_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_mcu_temperature_tmp_tx_fragmentation_offset >= 6) {
        return;
      }
    }
    error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[error_level_config_mcu_temperature_tmp_tx_fragmentation_offset] = msg.data;
    if (msg.header.eof == 0) {
      return;
    }
    error_level_config error_level_config_mcu_temperature_tmp;
    error_level_config_mcu_temperature_tmp.info_thresh = ((error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_mcu_temperature_tmp.info_timeout = ((error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_mcu_temperature_tmp.warning_thresh = ((error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_mcu_temperature_tmp.warning_timeout = ((error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_mcu_temperature_tmp.error_thresh = ((error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_mcu_temperature_tmp.error_timeout = ((error_level_config_mcu_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_mcu_temperature(error_level_config_mcu_temperature_tmp);
    break;
  }
  case 44 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    float cooling_cycle_temperature_tmp;
    cooling_cycle_temperature_tmp = (float)((msg.data & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_cooling_cycle_temperature(cooling_cycle_temperature_tmp);
    break;
  }
  case 45 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    error_level error_level_cooling_cycle_temperature_tmp;
    error_level_cooling_cycle_temperature_tmp = (error_level)((msg.data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_cooling_cycle_temperature(error_level_cooling_cycle_temperature_tmp);
    break;
  }
  case 46 : {
    if (msg.header.sof == 1) {
      if (msg.header.toggle == 0 || msg.header.eof != 0) {
        return;
      }
      error_level_config_cooling_temperature_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_cooling_temperature_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_cooling_temperature_tmp_tx_fragmentation_offset >= 6) {
        return;
      }
    }
    error_level_config_cooling_temperature_tmp_tx_fragmentation_buffer[error_level_config_cooling_temperature_tmp_tx_fragmentation_offset] = msg.data;
    if (msg.header.eof == 0) {
      return;
    }
    error_level_config error_level_config_cooling_temperature_tmp;
    error_level_config_cooling_temperature_tmp.info_thresh = ((error_level_config_cooling_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_cooling_temperature_tmp.info_timeout = ((error_level_config_cooling_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_cooling_temperature_tmp.warning_thresh = ((error_level_config_cooling_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_cooling_temperature_tmp.warning_timeout = ((error_level_config_cooling_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_cooling_temperature_tmp.error_thresh = ((error_level_config_cooling_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_cooling_temperature_tmp.error_timeout = ((error_level_config_cooling_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_cooling_temperature(error_level_config_cooling_temperature_tmp);
    break;
  }
  case 47 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    float bat24_temperature_tmp;
    bat24_temperature_tmp = (float)((msg.data & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_bat24_temperature(bat24_temperature_tmp);
    break;
  }
  case 48 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    error_level error_level_bat24_temperature_tmp;
    error_level_bat24_temperature_tmp = (error_level)((msg.data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_bat24_temperature(error_level_bat24_temperature_tmp);
    break;
  }
  case 49 : {
    if (msg.header.sof == 1) {
      if (msg.header.toggle == 0 || msg.header.eof != 0) {
        return;
      }
      error_level_config_bat24_temperature_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_bat24_temperature_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_bat24_temperature_tmp_tx_fragmentation_offset >= 6) {
        return;
      }
    }
    error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[error_level_config_bat24_temperature_tmp_tx_fragmentation_offset] = msg.data;
    if (msg.header.eof == 0) {
      return;
    }
    error_level_config error_level_config_bat24_temperature_tmp;
    error_level_config_bat24_temperature_tmp.info_thresh = ((error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_bat24_temperature_tmp.info_timeout = ((error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_temperature_tmp.warning_thresh = ((error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_bat24_temperature_tmp.warning_timeout = ((error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_bat24_temperature_tmp.error_thresh = ((error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_bat24_temperature_tmp.error_timeout = ((error_level_config_bat24_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_bat24_temperature(error_level_config_bat24_temperature_tmp);
    break;
  }
  case 50 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    float supercap_temperature_tmp;
    supercap_temperature_tmp = (float)((msg.data & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_supercap_temperature(supercap_temperature_tmp);
    break;
  }
  case 51 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    error_level error_level_supercap_temperature_tmp;
    error_level_supercap_temperature_tmp = (error_level)((msg.data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_supercap_temperature(error_level_supercap_temperature_tmp);
    break;
  }
  case 52 : {
    if (msg.header.sof == 1) {
      if (msg.header.toggle == 0 || msg.header.eof != 0) {
        return;
      }
      error_level_config_supercap_temperature_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_supercap_temperature_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_supercap_temperature_tmp_tx_fragmentation_offset >= 6) {
        return;
      }
    }
    error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[error_level_config_supercap_temperature_tmp_tx_fragmentation_offset] = msg.data;
    if (msg.header.eof == 0) {
      return;
    }
    error_level_config error_level_config_supercap_temperature_tmp;
    error_level_config_supercap_temperature_tmp.info_thresh = ((error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_supercap_temperature_tmp.info_timeout = ((error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_supercap_temperature_tmp.warning_thresh = ((error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_supercap_temperature_tmp.warning_timeout = ((error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_supercap_temperature_tmp.error_thresh = ((error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_supercap_temperature_tmp.error_timeout = ((error_level_config_supercap_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_supercap_temperature(error_level_config_supercap_temperature_tmp);
    break;
  }
  case 53 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    float buck_temperature_tmp;
    buck_temperature_tmp = (float)((msg.data & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_buck_temperature(buck_temperature_tmp);
    break;
  }
  case 54 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    error_level error_level_buck_temperature_tmp;
    error_level_buck_temperature_tmp = (error_level)((msg.data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_buck_temperature(error_level_buck_temperature_tmp);
    break;
  }
  case 55 : {
    if (msg.header.sof == 1) {
      if (msg.header.toggle == 0 || msg.header.eof != 0) {
        return;
      }
      error_level_config_buck_temperature_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_buck_temperature_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_buck_temperature_tmp_tx_fragmentation_offset >= 6) {
        return;
      }
    }
    error_level_config_buck_temperature_tmp_tx_fragmentation_buffer[error_level_config_buck_temperature_tmp_tx_fragmentation_offset] = msg.data;
    if (msg.header.eof == 0) {
      return;
    }
    error_level_config error_level_config_buck_temperature_tmp;
    error_level_config_buck_temperature_tmp.info_thresh = ((error_level_config_buck_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_buck_temperature_tmp.info_timeout = ((error_level_config_buck_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_buck_temperature_tmp.warning_thresh = ((error_level_config_buck_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_buck_temperature_tmp.warning_timeout = ((error_level_config_buck_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_buck_temperature_tmp.error_thresh = ((error_level_config_buck_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_buck_temperature_tmp.error_timeout = ((error_level_config_buck_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_buck_temperature(error_level_config_buck_temperature_tmp);
    break;
  }
  case 56 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    float ebox_temperature_tmp;
    ebox_temperature_tmp = (float)((msg.data & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_ebox_temperature(ebox_temperature_tmp);
    break;
  }
  case 57 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    error_level error_level_ebox_temperature_tmp;
    error_level_ebox_temperature_tmp = (error_level)((msg.data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_ebox_temperature(error_level_ebox_temperature_tmp);
    break;
  }
  case 58 : {
    if (msg.header.sof == 1) {
      if (msg.header.toggle == 0 || msg.header.eof != 0) {
        return;
      }
      error_level_config_ebox_temperature_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_ebox_temperature_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_ebox_temperature_tmp_tx_fragmentation_offset >= 6) {
        return;
      }
    }
    error_level_config_ebox_temperature_tmp_tx_fragmentation_buffer[error_level_config_ebox_temperature_tmp_tx_fragmentation_offset] = msg.data;
    if (msg.header.eof == 0) {
      return;
    }
    error_level_config error_level_config_ebox_temperature_tmp;
    error_level_config_ebox_temperature_tmp.info_thresh = ((error_level_config_ebox_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_ebox_temperature_tmp.info_timeout = ((error_level_config_ebox_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_ebox_temperature_tmp.warning_thresh = ((error_level_config_ebox_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_ebox_temperature_tmp.warning_timeout = ((error_level_config_ebox_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_ebox_temperature_tmp.error_thresh = ((error_level_config_ebox_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_ebox_temperature_tmp.error_timeout = ((error_level_config_ebox_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_ebox_temperature(error_level_config_ebox_temperature_tmp);
    break;
  }
  case 59 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    float ambient_temperature_tmp;
    ambient_temperature_tmp = (float)((msg.data & (0xFFFFFFFF >> (32 - 8))) * 0.592156862745098 + -1);
    canzero_set_ambient_temperature(ambient_temperature_tmp);
    break;
  }
  case 60 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    error_level error_level_ambient_temperature_tmp;
    error_level_ambient_temperature_tmp = (error_level)((msg.data & (0xFFFFFFFF >> (32 - 2))));
    canzero_set_error_level_ambient_temperature(error_level_ambient_temperature_tmp);
    break;
  }
  case 61 : {
    if (msg.header.sof == 1) {
      if (msg.header.toggle == 0 || msg.header.eof != 0) {
        return;
      }
      error_level_config_ambient_temperature_tmp_tx_fragmentation_offset = 0;
    }else {
      error_level_config_ambient_temperature_tmp_tx_fragmentation_offset += 1;
      if (error_level_config_ambient_temperature_tmp_tx_fragmentation_offset >= 6) {
        return;
      }
    }
    error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[error_level_config_ambient_temperature_tmp_tx_fragmentation_offset] = msg.data;
    if (msg.header.eof == 0) {
      return;
    }
    error_level_config error_level_config_ambient_temperature_tmp;
    error_level_config_ambient_temperature_tmp.info_thresh = ((error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_ambient_temperature_tmp.info_timeout = ((error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_ambient_temperature_tmp.warning_thresh = ((error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_ambient_temperature_tmp.warning_timeout = ((error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    error_level_config_ambient_temperature_tmp.error_thresh = ((error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000004656612874161595 + -10000;
    error_level_config_ambient_temperature_tmp.error_timeout = ((error_level_config_ambient_temperature_tmp_tx_fragmentation_buffer[0] & (0xFFFFFFFF >> (32 - 32)))) * 0.000000013969838622484784 + 0;
    canzero_set_error_level_config_ambient_temperature(error_level_config_ambient_temperature_tmp);
    break;
  }
  case 62 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    error_flag assertion_fault_tmp;
    assertion_fault_tmp = (error_flag)((msg.data & (0xFFFFFFFF >> (32 - 1))));
    canzero_set_assertion_fault(assertion_fault_tmp);
    break;
  }
  case 63 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    uint8_t battery_24V_temperature_tmp;
    battery_24V_temperature_tmp = (uint8_t)(msg.data & (0xFFFFFFFF >> (32 - 1)));
    canzero_set_battery_24V_temperature(battery_24V_temperature_tmp);
    break;
  }
  case 64 : {
    if (msg.header.sof != 1 || msg.header.toggle != 0 || msg.header.eof != 1) {
      return;
    }
    uint8_t error_level_bat24_over_currrent_tmp;
    error_level_bat24_over_currrent_tmp = (uint8_t)(msg.data & (0xFFFFFFFF >> (32 - 1)));
    canzero_set_error_level_bat24_over_currrent(error_level_bat24_over_currrent_tmp);
    break;
  }
  default:
    return;
  }
  resp.header.od_index = msg.header.od_index;
  resp.header.client_id = msg.header.client_id;
  resp.header.server_id = msg.header.server_id;
  resp.header.erno = set_resp_erno_Success;
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
      case 0x13B:
        canzero_handle_get_req(&frame);
        break;
      case 0x17B:
        canzero_handle_heartbeat(&frame);
        break;
    }
  }
}
void canzero_can1_poll() {
  canzero_frame frame;
  while (canzero_can1_recv(&frame)) {
    switch (frame.id) {
      case 0x15B:
        canzero_handle_set_req(&frame);
        break;
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
  schedule_state_estimation_interval_job();
  schedule_safety_sensors_interval_job();
  schedule_errors_interval_job();
  schedule_sdc_status_interval_job();

}
void canzero_set_state(input_board_state value) {
  extern input_board_state __oe_state;
  if (__oe_state != value) {
    __oe_state = value;
    uint32_t time = canzero_get_time();
    if (state_interval_job.climax > state_interval_job.job.stream_interval_job.last_schedule + 0) {
      state_interval_job.climax = state_interval_job.job.stream_interval_job.last_schedule + 0;
      scheduler_promote_job(&state_interval_job);
    }
  }
}
void canzero_set_error_level_position_estimation(error_level value) {
  extern error_level __oe_error_level_position_estimation;
  if (__oe_error_level_position_estimation != value) {
    __oe_error_level_position_estimation = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_interval_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_interval_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_velocity_estimation(error_level value) {
  extern error_level __oe_error_level_velocity_estimation;
  if (__oe_error_level_velocity_estimation != value) {
    __oe_error_level_velocity_estimation = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_interval_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_interval_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_acceleration_estimation(error_level value) {
  extern error_level __oe_error_level_acceleration_estimation;
  if (__oe_error_level_acceleration_estimation != value) {
    __oe_error_level_acceleration_estimation = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_interval_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_interval_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_bat24_under_voltage(error_level value) {
  extern error_level __oe_error_level_bat24_under_voltage;
  if (__oe_error_level_bat24_under_voltage != value) {
    __oe_error_level_bat24_under_voltage = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_interval_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_interval_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_bat24_over_voltage(error_level value) {
  extern error_level __oe_error_level_bat24_over_voltage;
  if (__oe_error_level_bat24_over_voltage != value) {
    __oe_error_level_bat24_over_voltage = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_interval_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_interval_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_link24_under_voltage(error_level value) {
  extern error_level __oe_error_level_link24_under_voltage;
  if (__oe_error_level_link24_under_voltage != value) {
    __oe_error_level_link24_under_voltage = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_interval_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_interval_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_link24_over_voltage(error_level value) {
  extern error_level __oe_error_level_link24_over_voltage;
  if (__oe_error_level_link24_over_voltage != value) {
    __oe_error_level_link24_over_voltage = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_interval_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_interval_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_link24_over_current(error_level value) {
  extern error_level __oe_error_level_link24_over_current;
  if (__oe_error_level_link24_over_current != value) {
    __oe_error_level_link24_over_current = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_interval_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_interval_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_link45_under_voltage(error_level value) {
  extern error_level __oe_error_level_link45_under_voltage;
  if (__oe_error_level_link45_under_voltage != value) {
    __oe_error_level_link45_under_voltage = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_interval_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_interval_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_link45_over_voltage(error_level value) {
  extern error_level __oe_error_level_link45_over_voltage;
  if (__oe_error_level_link45_over_voltage != value) {
    __oe_error_level_link45_over_voltage = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_interval_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_interval_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_link45_over_current(error_level value) {
  extern error_level __oe_error_level_link45_over_current;
  if (__oe_error_level_link45_over_current != value) {
    __oe_error_level_link45_over_current = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_interval_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_interval_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_sdc_status(sdc_status value) {
  extern sdc_status __oe_sdc_status;
  if (__oe_sdc_status != value) {
    __oe_sdc_status = value;
    uint32_t time = canzero_get_time();
    if (state_interval_job.climax > state_interval_job.job.stream_interval_job.last_schedule + 0) {
      state_interval_job.climax = state_interval_job.job.stream_interval_job.last_schedule + 0;
      scheduler_promote_job(&state_interval_job);
    }
    if (sdc_status_interval_job.climax > sdc_status_interval_job.job.stream_interval_job.last_schedule + 50) {
      sdc_status_interval_job.climax = sdc_status_interval_job.job.stream_interval_job.last_schedule + 50;
      scheduler_promote_job(&sdc_status_interval_job);
    }
  }
}
void canzero_set_error_level_cooling_cycle_under_pressure(error_level value) {
  extern error_level __oe_error_level_cooling_cycle_under_pressure;
  if (__oe_error_level_cooling_cycle_under_pressure != value) {
    __oe_error_level_cooling_cycle_under_pressure = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_interval_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_interval_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_cooling_cycle_over_pressure(error_level value) {
  extern error_level __oe_error_level_cooling_cycle_over_pressure;
  if (__oe_error_level_cooling_cycle_over_pressure != value) {
    __oe_error_level_cooling_cycle_over_pressure = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_interval_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_interval_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_mcu_temperature(error_level value) {
  extern error_level __oe_error_level_mcu_temperature;
  if (__oe_error_level_mcu_temperature != value) {
    __oe_error_level_mcu_temperature = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_interval_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_interval_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_cooling_cycle_temperature(error_level value) {
  extern error_level __oe_error_level_cooling_cycle_temperature;
  if (__oe_error_level_cooling_cycle_temperature != value) {
    __oe_error_level_cooling_cycle_temperature = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_interval_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_interval_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_bat24_temperature(error_level value) {
  extern error_level __oe_error_level_bat24_temperature;
  if (__oe_error_level_bat24_temperature != value) {
    __oe_error_level_bat24_temperature = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_interval_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_interval_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_supercap_temperature(error_level value) {
  extern error_level __oe_error_level_supercap_temperature;
  if (__oe_error_level_supercap_temperature != value) {
    __oe_error_level_supercap_temperature = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_interval_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_interval_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_buck_temperature(error_level value) {
  extern error_level __oe_error_level_buck_temperature;
  if (__oe_error_level_buck_temperature != value) {
    __oe_error_level_buck_temperature = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_interval_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_interval_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_ebox_temperature(error_level value) {
  extern error_level __oe_error_level_ebox_temperature;
  if (__oe_error_level_ebox_temperature != value) {
    __oe_error_level_ebox_temperature = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_interval_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_interval_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_ambient_temperature(error_level value) {
  extern error_level __oe_error_level_ambient_temperature;
  if (__oe_error_level_ambient_temperature != value) {
    __oe_error_level_ambient_temperature = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_interval_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_interval_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
void canzero_set_error_level_bat24_over_currrent(uint8_t value) {
  extern uint8_t __oe_error_level_bat24_over_currrent;
  if (__oe_error_level_bat24_over_currrent != value) {
    __oe_error_level_bat24_over_currrent = value;
    uint32_t time = canzero_get_time();
    if (errors_interval_job.climax > errors_interval_job.job.stream_interval_job.last_schedule + 0) {
      errors_interval_job.climax = errors_interval_job.job.stream_interval_job.last_schedule + 0;
      scheduler_promote_job(&errors_interval_job);
    }
  }
}
