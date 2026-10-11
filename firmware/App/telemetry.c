#include "telemetry.h"
#include <math.h>
#include <stdio.h>

bool telemetry_serialize_json(const telemetry_sample_t *sample, char *dst, size_t capacity) {
    if (sample == NULL || dst == NULL || capacity == 0U) return false;
    if (!isfinite(sample->temperature_c) || !isfinite(sample->vibration_rms) ||
        sample->vibration_rms < 0.0f) return false;
    int written = snprintf(dst, capacity,
        "{\"timestamp_ms\":%lu,\"sequence\":%lu,\"temperature_c\":%.3f,\"vibration_rms\":%.6f,\"simulated\":%s}",
        (unsigned long)sample->timestamp_ms, (unsigned long)sample->sequence,
        (double)sample->temperature_c, (double)sample->vibration_rms,
        sample->simulated ? "true" : "false");
    return written >= 0 && (size_t)written < capacity;
}
