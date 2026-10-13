# Custom PCB Edge Sensor Node via MQTT

> Embedded sensing node concept for collecting diagnostic data and sending telemetry to a downstream MQTT consumer.

![KiCad](https://img.shields.io/badge/KiCad-PCB%20Design-314CB0?style=flat-square)
![STM32](https://img.shields.io/badge/STM32-Firmware-03234B?style=flat-square)
![MQTT](https://img.shields.io/badge/MQTT-Telemetry-660066?style=flat-square)
![Status](https://img.shields.io/badge/status-in%20development-orange?style=flat-square)

## Overview

Describe the use case, signals monitored, target environment, and expected consumer of the data. State whether the repository contains a concept, schematic/layout design, fabricated prototype, or bench-validated hardware.

## Objectives

- Acquire [sensor values] using documented interfaces.
- Publish well-defined MQTT messages to [broker/consumer].
- Make the PCB, firmware build, and test flow reviewable.
- Validate power, connectivity, sensor readings, and error handling.

## System Architecture

Document the signal path from sensor → microcontroller → network transport → consumer/dashboard.

![System architecture](docs/images/system-architecture.png)

## Hardware

| Item | Specification |
|---|---|
| MCU | [Exact STM32 part number] |
| Sensors | [Part numbers, ranges, interfaces] |
| PCB revision | [Revision / design status] |
| Layer count | [Confirm from actual board files] |
| Power input and rails | [Voltage/current requirements] |
| Connectors and debug | [SWD/UART/etc.] |

Include design screenshots or exports: schematic PDF, PCB layout, board render, fabrication outputs, and BOM. Never imply a PCB was manufactured or tested unless it was.

## Firmware & Telemetry

Document the toolchain, build configuration, sensor drivers, sampling interval, MQTT topic names, payload schema, retained/QoS settings, reconnect behavior, and authentication/TLS assumptions.

Example payload (adapt to the actual schema):

```json
{
  "device_id": "sensor-node-01",
  "timestamp": "2026-01-01T00:00:00Z",
  "temperature_c": 25.0,
  "vibration_rms": 0.012,
  "status": "sample"
}
```

Do not commit Wi-Fi credentials, broker passwords, private certificates, or access tokens. Provide a safe example configuration file instead.

## Repository Layout

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
├── docs/
│   ├── images/
│   └── reports/
├── tests/
│   └── test-payloads/
├── examples/
│   └── mqtt-subscriber/
├── .gitignore
├── .env.example
└── README.md
```

Adapt folders to the real KiCad and STM32CubeIDE project structure; avoid duplicate generated files unless they help reproduce the build.

## Requirements

- KiCad version: [version]
- STM32CubeIDE / compiler: [version]
- Board and MCU: [exact part number]
- MQTT broker/client: [software and version]
- Lab equipment used: [if applicable]

## Setup & Build

1. Open the schematic and PCB with the stated KiCad version.
2. Open the firmware project using the listed IDE/toolchain.
3. Configure target MCU, clock tree, pin assignments, and connection settings.
4. Build and flash using the documented debugger/programmer.
5. Run the MQTT subscriber and inspect messages.

Add exact, tested commands and screenshots for the real implementation.

## Validation Plan

| Test | Method | Expected evidence | Status |
|---|---|---|---|
| Electrical / power checks | [bench method] | [measurements] | [not run / pass / fail] |
| Sensor readout | [known reference / test] | [logs] | [status] |
| MQTT connection | [broker + client] | [publish/subscribe log] | [status] |
| Reconnect / error handling | [disconnect test] | [recovery evidence] | [status] |
| PCB DRC / ERC | KiCad checks | [report] | [status] |

## Power, Reliability & Security

State the power budget, safe operating limits, sampling constraints, failure behavior, firmware update approach, and security limitations. Keep credentials outside version control.

## Results

Report only verified facts. Separate schematic/DRC results, firmware simulation, bench measurements, and field tests. Link raw logs or reports where possible.

## Limitations & Roadmap

- [Known hardware/firmware limitation]
- [Unvalidated subsystem]
- [ ] Complete DRC/ERC and document unresolved items.
- [ ] Add repeatable firmware build steps.
- [ ] Capture a real broker publish/subscribe demonstration.
- [ ] Record current, sensor accuracy, and reliability test results.

## License & Third-Party Components

Specify a license for the source and hardware files. Check vendor licenses and redistribution terms for symbol, footprint, library, and driver dependencies.

## Contact

**Shivtej Salunke · SAL Dynamics**  
[GitHub](https://github.com/shivtejsalunke) · [LinkedIn](https://www.linkedin.com/in/shivtejsalunke) · [Email](mailto:shivtejsalunke23@gmail.com)
