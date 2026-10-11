#include "data_buffer.h"
#include "sensor_manager.h"
#include "telemetry.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

static bool mock_sensor(float *temperature, float *vibration, void *context) {
    (void)context;
    *temperature = 24.5f;
    *vibration = 0.125f;
    return true;
}
static bool invalid_sensor(float *temperature, float *vibration, void *context) {
    (void)context;
    *temperature = NAN;
    *vibration = 0.1f;
    return true;
}
static bool failed_sensor(float *temperature, float *vibration, void *context) {
    (void)temperature; (void)vibration; (void)context;
    return false;
}

int main(void) {
    data_buffer_t buffer;
    telemetry_sample_t input = { .timestamp_ms = 1000U, .temperature_c = 24.5f,
        .vibration_rms = 0.125f, .sequence = 7U, .simulated = 1U };
    telemetry_sample_t output;
    char json[192];

    data_buffer_init(&buffer);
    assert(data_buffer_count(&buffer) == 0U);
    assert(data_buffer_push(&buffer, &input));
    assert(data_buffer_count(&buffer) == 1U);
    assert(data_buffer_pop(&buffer, &output));
    assert(output.sequence == input.sequence);
    assert(!data_buffer_pop(&buffer, &output));

    for (size_t i = 0U; i < DATA_BUFFER_CAPACITY; ++i) assert(data_buffer_push(&buffer, &input));
    assert(!data_buffer_push(&buffer, &input));
    assert(buffer.dropped == 1U);
    assert(data_buffer_count(&buffer) == DATA_BUFFER_CAPACITY);

    assert(sensor_manager_read(&output, 2000U, 9U, mock_sensor, NULL, true));
    assert(output.simulated == 1U && output.sequence == 9U);
    assert(!sensor_manager_read(&output, 2000U, 9U, invalid_sensor, NULL, false));
    assert(!sensor_manager_read(&output, 2000U, 9U, failed_sensor, NULL, false));

    assert(telemetry_serialize_json(&input, json, sizeof json));
    assert(strstr(json, "\"simulated\":true") != NULL);
    assert(strstr(json, "\"sequence\":7") != NULL);
    assert(!telemetry_serialize_json(&input, json, 4U));
    input.temperature_c = NAN;
    assert(!telemetry_serialize_json(&input, json, sizeof json));
    puts("PASS test_firmware");
    return 0;
}
