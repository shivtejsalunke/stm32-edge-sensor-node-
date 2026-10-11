#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H
#include <stdbool.h>
#include <stddef.h>

/* Transport adapter contract. Integrate a selected MQTT/TLS client on the target board. */
typedef struct {
    bool (*connect)(void *context);
    bool (*publish)(void *context, const char *topic, const char *payload, size_t payload_len);
    void (*disconnect)(void *context);
    void *context;
} mqtt_transport_t;

typedef enum {
    MQTT_STATUS_DISCONNECTED = 0,
    MQTT_STATUS_CONNECTED = 1,
    MQTT_STATUS_ERROR = 2
} mqtt_status_t;

mqtt_status_t mqtt_client_connect(mqtt_transport_t *transport);
bool mqtt_client_publish_json(mqtt_transport_t *transport, const char *topic,
                              const char *payload, size_t payload_len);
void mqtt_client_disconnect(mqtt_transport_t *transport);
#endif
