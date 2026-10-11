#ifndef CONFIG_EXAMPLE_H
#define CONFIG_EXAMPLE_H
/* Example configuration only. Never commit live credentials. */
#define TELEMETRY_PUBLISH_PERIOD_MS 1000U
#define TELEMETRY_TOPIC "demo/shivtej/sensor-node/telemetry"
#define MQTT_HOST "mqtt.example.invalid"
#define MQTT_PORT 8883U /* TLS endpoint expected; adapter must implement TLS. */
#define MQTT_CLIENT_ID "stm32-edge-sensor-node-demo"
/* Inject CA roots and secrets via secure build/secret provisioning, not Git. */
#endif
