#include "data_buffer.h"
#include "sensor_manager.h"
#include "telemetry.h"
#include "mqtt_client.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct { unsigned connects; unsigned publishes; unsigned disconnects; } transport_state_t;

static bool mock_connect(void *context) {
    ((transport_state_t *)context)->connects++;
    return true;
}
static bool mock_publish(void *context, const char *topic, const char *payload, size_t len) {
    transport_state_t *state = (transport_state_t *)context;
    state->publishes++;
    return topic != NULL && payload != NULL && len > 0U;
}
static void mock_disconnect(void *context) {
    ((transport_state_t *)context)->disconnects++;
}
static bool mock_sensor(float *temperature, float *vibration, void *context) {
    (void)context; *temperature = 24.5f; *vibration = 0.125f; return true;
}
static bool invalid_sensor(float *temperature, float *vibration, void *context) {
    (void)context; *temperature = NAN; *vibration = 0.1f; return true;
}
static bool failed_sensor(float *temperature, float *vibration, void *context) {
    (void)temperature; (void)vibration; (void)context; return false;
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

    transport_state_t state = {0U, 0U, 0U};
    mqtt_transport_t transport = { mock_connect, mock_publish, mock_disconnect, &state };
    assert(mqtt_client_connect(&transport) == MQTT_STATUS_CONNECTED);
    assert(state.connects == 1U);
    assert(mqtt_client_publish_json(&transport, "demo/device/telemetry", "{\"ok\":true}", 11U));
    assert(state.publishes == 1U);
    assert(!mqtt_client_publish_json(&transport, NULL, "{}", 2U));
    mqtt_client_disconnect(&transport);
    assert(state.disconnects == 1U);
    assert(mqtt_client_connect(NULL) == MQTT_STATUS_ERROR);
    puts("PASS test_firmware");
    return 0;
}
