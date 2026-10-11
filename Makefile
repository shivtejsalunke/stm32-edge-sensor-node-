.PHONY: test demo

test:
	python3 -m pytest -q tests
	cc -std=c11 -Wall -Wextra -Werror -pedantic -Ifirmware/App tests/test_firmware.c firmware/App/data_buffer.c firmware/App/telemetry.c firmware/App/sensor_manager.c -lm -o /tmp/stm32-edge-node-test
	/tmp/stm32-edge-node-test

demo:
	bash scripts/run_demo.sh
