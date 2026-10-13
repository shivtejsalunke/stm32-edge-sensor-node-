# STM32 Edge Sensor Node — MQTT Telemetry

> Embedded sensing node concept for collecting diagnostic data and publishing structured telemetry.

![C](https://img.shields.io/badge/C-C11-A8B9CC?style=flat-square&logo=c)
![STM32](https://img.shields.io/badge/STM32-Firmware-03234B?style=flat-square)
![MQTT](https://img.shields.io/badge/MQTT-Telemetry-660066?style=flat-square)

## Project Status

**Stage:** [design / firmware prototype / fabricated board / bench validated]  
**Hardware revision:** [revision or N/A]

State clearly whether board files are conceptual, reviewed, fabricated, or tested. Avoid implying a manufactured 4-layer board unless the design and hardware evidence support that claim.

## Overview & Architecture

Describe sensors, sampled signals, MCU responsibilities, message flow, and the MQTT consumer. Add a diagram showing sensor → MCU → MQTT broker → subscriber/dashboard.

## Hardware Summary

| Item | Details |
|---|---|
| MCU | [exact STM32 part] |
| Sensors | [part numbers and measurement ranges] |
| PCB | [stack-up, layer count, revision] |
| Power | [input voltage, rails, estimated/measured current] |
| Interfaces | [I2C / SPI / UART / GPIO, as implemented] |
| Debug / programming | [SWD / UART / other] |

Link schematic PDF, PCB layout screenshots, BOM, ERC/DRC reports, and manufacturing exports if available and permitted.

## Firmware & MQTT

Document compiler and IDE versions, clock configuration, pin mapping, drivers, sampling schedule, topic convention, JSON/binary schema, QoS, retained messages, reconnect logic, and error handling.

Example payload (illustrative only; change to the actual schema):

```json
{
  "device_id": "sensor-node-01",
  "timestamp": "2026-01-01T00:00:00Z",
  "temperature_c": 25.0,
  "vibration_rms": 0.012,
  "status": "sample"
}
```

Never commit secrets or live broker credentials. Provide a safe configuration example.

## Repository Structure

```text
.
├── hardware/
│   ├── schematics/
│   ├── pcb/
│   ├── fabrication/
│   └── bom/
├── firmware/
│   ├── Core/
│   ├── Drivers/
│   ├── MQTT/
│   └── README.md
├── examples/
│   └── mqtt-subscriber/
├── tests/
├── results/
├── docs/
│   ├── images/
│   └── reports/
└── README.md
```

Adapt names to the real KiCad and firmware project. Avoid committing generated files that the toolchain can reliably recreate.

## Setup & Build

Document the exact toolchain version, environment configuration, build steps, flash/debug procedure, and subscriber setup. Include actual commands validated from a clean checkout.

## Validation

| Test | Evidence | Status |
|---|---|---|
| Schematic / PCB ERC & DRC | Exported reports and documented exceptions | [status] |
| Firmware build | Compiler output and version | [status] |
| Sensor readout | Values compared with a reference | [status] |
| MQTT publish/subscribe | Broker/client logs | [status] |
| Reconnect handling | Disconnect/recovery logs | [status] |
| Power consumption | Measurement setup and readings | [status] |

## Security & Reliability

Document credentials storage, TLS/authentication assumptions, retry/backoff behavior, invalid-sensor-data handling, watchdog strategy, and safe failure behavior.

## Limitations & Roadmap

- [Known limitation / unvalidated subsystem]
- [ ] Add an end-to-end publish/subscribe demo.
- [ ] Document power measurements.
- [ ] Provide ERC/DRC and fabrication review evidence.
- [ ] Add firmware tests for malformed data and disconnect/reconnect paths.

## References & License

Cite vendor datasheets, libraries, and third-party hardware assets. Specify redistribution/licensing terms for source and design files.

## Contact

**Shivtej Salunke · SAL Dynamics**  
[GitHub](https://github.com/shivtejsalunke) · [LinkedIn](https://www.linkedin.com/in/shivtejsalunke) · [Email](mailto:shivtejsalunke23@gmail.com)
