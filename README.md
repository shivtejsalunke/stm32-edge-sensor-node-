# STM32 Edge Sensor Node
### Embedded C · Industrial Telemetry · MQTT Integration Boundary

<div align="center">

[![C11](https://img.shields.io/badge/C-C11-A8B9CC?logo=c&logoColor=black)](https://en.cppreference.com/w/c/11)
[![STM32](https://img.shields.io/badge/STM32-Firmware-03234B)](https://www.st.com/)
[![MQTT](https://img.shields.io/badge/MQTT-Telemetry-660066)](https://mqtt.org/)
[![Status](https://img.shields.io/badge/status-embedded%20project-blue)](#project-status)

</div>

## Project Status

**Stage:** [firmware prototype / schematic-layout design / fabricated hardware / bench validated]  
**Target MCU:** [exact STM32 part number]  
**PCB revision:** [revision or N/A]

Be explicit about the current state. A firmware prototype, a board design, a fabricated PCB, and a bench-validated device are different engineering milestones.

## Overview

This project focuses on an embedded sensor-node architecture for acquiring diagnostic measurements and publishing structured telemetry to an MQTT broker. Document the actual sensors, interfaces, sampling schedule, message schema, and receiving service implemented in this repository.

## System Architecture

```text
Sensors
  ↓ I²C / SPI / ADC / GPIO (as implemented)
STM32 firmware
  ↓ MQTT client / network interface
Broker
  ↓
Subscriber or monitoring dashboard
```

Replace this high-level diagram with the actual architecture, interfaces, and component part numbers.

## Hardware Summary

| Item | Specification |
|---|---|
| MCU | [Exact STM32 part number] |
| Sensors | [Part numbers, ranges, interfaces] |
| PCB stack-up | [Actual layer count and evidence] |
| Power input and rails | [Voltage/current requirements] |
| Connectors and debug | [SWD/UART/etc.] |
| Hardware stage | [Design / fabricated / tested] |

If a 4-layer PCB is claimed, link the actual stack-up or board fabrication specification and distinguish design files from a manufactured board.

## Firmware & MQTT

Document the compiler and IDE versions, clock configuration, pin mappings, sensor drivers, sampling interval, MQTT topic names, payload schema, QoS, retained-message settings, reconnection behavior, and authentication/TLS assumptions.

Illustrative payload only — change it to match the implemented schema:

```json
{
  "device_id": "sensor-node-01",
  "timestamp": "2026-01-01T00:00:00Z",
  "temperature_c": 25.0,
  "vibration_rms": 0.012,
  "status": "sample"
}
```

Never commit Wi-Fi credentials, broker passwords, private certificates, or access tokens. Supply a safe example configuration instead.

## Suggested Repository Layout

Adapt to the actual KiCad and firmware files:

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

## Setup & Build

Provide exact toolchain versions, project configuration, build steps, flash/debug procedure, and subscriber setup. Ensure the process works from a clean checkout and document any proprietary software requirements.

## Validation

| Test | Evidence | Status |
|---|---|---|
| Schematic / PCB ERC & DRC | Exported reports and unresolved exceptions | [status] |
| Firmware build | Compiler output and toolchain version | [status] |
| Sensor readout | Values compared with a known reference | [status] |
| MQTT publish/subscribe | Broker and client logs | [status] |
| Disconnect/reconnect | Recovery logs | [status] |
| Power consumption | Instrument, test conditions, readings | [status] |

Publish evidence for each completed test. Mark untested items as not run rather than implying validation.

## Security & Reliability

Document credential handling, transport security, reconnect/backoff strategy, invalid sensor data behavior, watchdog strategy, and safe failure behavior.

## Limitations & Roadmap

- [Known hardware or firmware limitation]
- [Unvalidated subsystem]
- [ ] Add an end-to-end publish/subscribe demo.
- [ ] Document the board stack-up and ERC/DRC results.
- [ ] Record current draw and sensor-reference measurements.
- [ ] Add firmware tests for malformed data and reconnect paths.

## References & License

Cite vendor datasheets, libraries, and third-party hardware assets. Specify the actual license for source and design files and respect component-library redistribution terms.

## Contact

**Shivtej Salunke · SAL Dynamics**  
[GitHub](https://github.com/shivtejsalunke) · [LinkedIn](https://www.linkedin.com/in/shivtejsalunke) · [Email](mailto:shivtejsalunke23@gmail.com)
