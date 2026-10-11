#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H
#include "data_buffer.h"
#include <stdbool.h>

/* Board-specific acquisition is injected through this callback; no STM32 family is assumed. */
typedef bool (*sensor_read_fn)(float *temperature_c, float *vibration_rms, void *context);
bool sensor_manager_read(telemetry_sample_t *out, uint32_t timestamp_ms,
                         uint32_t sequence, sensor_read_fn reader,
                         void *context, bool simulated);
#endif
