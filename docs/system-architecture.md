# System architecture

The project is split into portable application logic and target-specific integration seams.

1. **Acquisition:** `sensor_manager_read` accepts a callback. A board integration should implement it with the selected sensor driver and return temperature and vibration RMS in documented units.
2. **Validation:** callbacks that fail, null arguments, non-finite data and negative vibration RMS are rejected.
3. **Buffering:** a fixed 64-record ring buffer avoids dynamic allocation. The defined overflow policy rejects new records and increments a counter.
4. **Serialization:** a bounded JSON serializer rejects non-finite values and insufficient output capacity.
5. **Transport:** `mqtt_client.h` defines a connect/publish/disconnect contract. It is intentionally not tied to an MCU, RTOS, HAL, network stack or TLS client.
6. **Monitoring:** a deterministic Python simulator generates records marked `simulated=true`; the optional Python subscriber can inspect a broker configured separately.

The dotted/unfinished hardware and transport stages are integration work. No physical target compatibility or end-to-end telemetry delivery is claimed.
