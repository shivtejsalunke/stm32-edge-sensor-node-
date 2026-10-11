from simulator.mock_sensor import samples

def test_samples_are_deterministic_and_marked_simulated():
    first = list(samples(5, 17, 1000))
    second = list(samples(5, 17, 1000))
    assert first == second and len(first) == 5
    assert all(row["simulated"] is True for row in first)
    assert [row["sequence"] for row in first] == list(range(5))
    assert all(row["vibration_rms"] >= 0 for row in first)

def test_telemetry_schema_fields():
    row = next(samples(1, 1, 500))
    assert set(row) == {"timestamp_ms", "sequence", "temperature_c", "vibration_rms", "simulated"}
