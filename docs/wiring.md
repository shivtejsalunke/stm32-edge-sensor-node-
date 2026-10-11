# Wiring and board integration

No board or sensor part number has been selected, so this document intentionally does not specify fabricated pin assignments.

Before wiring, record the exact STM32 part/board, I/O voltage levels, power supply and current budget, sensor part number, interface (I2C/SPI/ADC/etc.), bus address, pull-up requirements, grounding, connectors, sampling bandwidth and mechanical mounting. Check the vendor datasheets and board schematic.

Add a board-specific pin map and wiring diagram after component selection. Validate voltage compatibility and sensor calibration before collecting measurements. The portable C callback is where a board driver should connect to the application layer.
