#include "sensor_manager.h"
#include <math.h>

bool sensor_manager_read(telemetry_sample_t *out, uint32_t timestamp_ms,
                         uint32_t sequence, sensor_read_fn reader,
                         void *context, bool simulated) {
    if (out == NULL || reader == NULL) return false;
    float temperature = 0.0f;
    float vibration = 0.0f;
    if (!reader(&temperature, &vibration, context)) return false;
    if (!isfinite(temperature) || !isfinite(vibration) || vibration < 0.0f) return false;
    out->timestamp_ms = timestamp_ms;
    out->sequence = sequence;
    out->temperature_c = temperature;
    out->vibration_rms = vibration;
    out->simulated = simulated ? 1U : 0U;
    return true;
}
