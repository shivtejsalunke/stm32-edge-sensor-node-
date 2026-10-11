# Troubleshooting

- **Host compile fails:** confirm a C11 compiler is available and use the strict command in the Makefile.
- **Buffer push fails:** check whether the fixed 64-entry buffer is full and inspect the drop counter; the current policy rejects the newest sample.
- **Serialization fails:** verify non-null pointers, finite floats, and sufficient output capacity.
- **Sensor callback fails:** surface the error in the target application; never publish stale/uninitialized readings as healthy data.
- **MQTT cannot connect:** confirm broker DNS/port, trust chain, clock validity where required for certificate checks, authentication and topic ACLs. Never disable certificate verification in a real deployment.
- **Simulated/real data confusion:** check the JSON `simulated` field and preserve provenance.
- **No target artifacts:** expected until the exact MCU, toolchain, startup code, linker script and HAL integration are selected.
