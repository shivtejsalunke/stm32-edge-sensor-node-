# Bring-up checklist

1. Select exact STM32 MCU/board, compiler, IDE/toolchain and HAL/SDK version.
2. Record sensor part numbers, voltage/power requirements, units, range and calibration method.
3. Add board-specific build files, startup/system code and driver implementation; preserve upstream licenses.
4. Implement the sensor callback and verify failure, timeout, disconnect and invalid-data handling.
5. Measure sampling cadence, buffer pressure, memory footprint and serialized payload size.
6. Integrate an MQTT client and TLS stack; validate certificates and use secure secret provisioning.
7. Test broker loss/reconnect, packet loss, queue overflow, reset, rollover, and sustained load on hardware.
8. Capture measured build, flash/RAM, latency and long-run results with exact board and toolchain versions.

Host unit tests are a useful first gate, not a substitute for a cross-build or board test.
