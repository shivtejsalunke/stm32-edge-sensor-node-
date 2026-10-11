# MQTT telemetry protocol

## Suggested topic

`demo/shivtej/sensor-node/telemetry`

Use a deployment-specific namespace and broker ACLs for real devices. The topic is an example, not a production provisioning scheme.

## JSON fields

| Field | Type | Meaning |
|---|---|---|
| `timestamp_ms` | unsigned integer | Application timestamp; the actual time base must be specified by the port |
| `sequence` | unsigned integer | Per-device sample sequence, with rollover behavior documented |
| `temperature_c` | number | Temperature in degrees Celsius |
| `vibration_rms` | number | Non-negative RMS scalar; sensor unit and scaling must be defined |
| `simulated` | boolean | Provenance flag; true for generated examples |

The C core serializes records but delegates publish to an injected transport callback. The repository does not contain a complete C MQTT/TLS implementation.

## Security/integration requirements

Use a maintained client library, certificate validation, authenticated clients, least-privilege topic ACLs, a defined QoS/retain policy, bounded payloads, reconnect/backoff behavior and secure credential provisioning. Do not embed secrets in firmware source or commit them. The optional Python subscriber verifies certificates by default; insecure demo mode is only for an isolated local network.
