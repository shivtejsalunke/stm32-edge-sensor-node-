#include "mqtt_client.h"

mqtt_status_t mqtt_client_connect(mqtt_transport_t *transport) {
    if (transport == NULL || transport->connect == NULL) return MQTT_STATUS_ERROR;
    return transport->connect(transport->context)
        ? MQTT_STATUS_CONNECTED : MQTT_STATUS_ERROR;
}

bool mqtt_client_publish_json(mqtt_transport_t *transport, const char *topic,
                              const char *payload, size_t payload_len) {
    if (transport == NULL || transport->publish == NULL || topic == NULL ||
        payload == NULL || payload_len == 0U) return false;
    return transport->publish(transport->context, topic, payload, payload_len);
}

void mqtt_client_disconnect(mqtt_transport_t *transport) {
    if (transport != NULL && transport->disconnect != NULL)
        transport->disconnect(transport->context);
}
