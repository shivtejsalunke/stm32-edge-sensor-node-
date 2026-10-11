#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."
mkdir -p results
python3 simulator/mock_sensor.py --count 20 --seed 17 --period-ms 1000 --out results/sample_telemetry.jsonl
if command -v cc >/dev/null; then
  cc -std=c11 -Wall -Wextra -Werror -pedantic -Ifirmware/App tests/test_firmware.c firmware/App/data_buffer.c firmware/App/telemetry.c firmware/App/sensor_manager.c firmware/App/mqtt_client.c -lm -o /tmp/stm32-edge-node-test
  /tmp/stm32-edge-node-test
else
  echo "C compiler unavailable; firmware unit tests NOT RUN" >&2
  exit 127
fi
python3 -m pytest -q tests
