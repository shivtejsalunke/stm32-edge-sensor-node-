"""Generate deterministic SIMULATED telemetry JSONL; not physical sensor data."""
import argparse
import json
import math
import random
from pathlib import Path

def samples(count: int, seed: int, period_ms: int):
    if count < 1 or period_ms < 1:
        raise ValueError("count and period_ms must be positive")
    rng = random.Random(seed)
    for index in range(count):
        yield {
            "timestamp_ms": index * period_ms,
            "sequence": index,
            "temperature_c": round(25 + 1.8 * math.sin(index / 20) + rng.gauss(0, 0.08), 3),
            "vibration_rms": round(abs(0.08 + 0.02 * math.sin(index / 7) + rng.gauss(0, 0.005)), 6),
            "simulated": True,
        }

def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--count", type=int, default=100)
    parser.add_argument("--seed", type=int, default=17)
    parser.add_argument("--period-ms", type=int, default=1000)
    parser.add_argument("--out", type=Path, default=Path("results/sample_telemetry.jsonl"))
    args = parser.parse_args()
    try:
        records = list(samples(args.count, args.seed, args.period_ms))
    except ValueError as exc:
        parser.error(str(exc))
    args.out.parent.mkdir(parents=True, exist_ok=True)
    with args.out.open("w", encoding="utf-8") as output:
        for record in records:
            output.write(json.dumps(record, separators=(",", ":")) + "\n")
    print(f"Wrote {len(records)} SIMULATED sample records to {args.out}")

if __name__ == "__main__":
    main()
