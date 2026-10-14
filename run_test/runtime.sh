#!/bin/bash

set -u

CXX="g++"
CXXFLAGS=(
    -O2
    -march=native
    -w
    -DATCODER
    -DONLINE_JUDGE
    -std=gnu++23
)

echo "=== Compile ==="

"$CXX" main.cpp -o main "${CXXFLAGS[@]}" || exit 1
"$CXX" generate.cpp -o generate "${CXXFLAGS[@]}" || exit 1

echo "=== Compilation successful ==="
echo "=== Benchmark started ==="
echo "Press Ctrl+C to stop."
echo

python3 - <<'PY'
import subprocess
import time
import statistics
import sys
from pathlib import Path

TIME_LIMIT_MS = 2000
RUN_TIMEOUT = 10
BATCH_SIZE = 10

case = 0
total_runs = 0
times = []

def save_input(case_number, data):
    path = Path(f"failed_{case_number}.txt")
    path.write_bytes(data)
    print(f"Input saved to: {path}", flush=True)

try:
    while True:
        # 入力生成（計測時間には含めない）
        try:
            gen = subprocess.run(
                ["./generate"],
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                check=True,
            )
        except subprocess.CalledProcessError as e:
            print("\nGENERATOR ERROR", flush=True)
            print(f"Exit code: {e.returncode}", flush=True)
            if e.stderr:
                print(
                    e.stderr.decode(errors="replace"),
                    file=sys.stderr,
                    flush=True,
                )
            break

        data = gen.stdout
        case += 1

        # 10回実行
        for run in range(1, BATCH_SIZE + 1):
            start = time.perf_counter_ns()

            try:
                result = subprocess.run(
                    ["./main"],
                    input=data,
                    stdout=subprocess.DEVNULL,
                    stderr=subprocess.PIPE,
                    timeout=RUN_TIMEOUT,
                )
            except subprocess.TimeoutExpired:
                print(
                    f"\nRUN {total_runs + 1}: TIMEOUT "
                    f"(>{RUN_TIMEOUT}s)",
                    flush=True,
                )
                save_input(case, data)
                raise SystemExit(1)

            elapsed_ms = (
                time.perf_counter_ns() - start
            ) / 1_000_000

            total_runs += 1
            times.append(elapsed_ms)

            status = "TLE" if elapsed_ms >= TIME_LIMIT_MS else "OK"

            print(
                f"RUN {total_runs}: "
                f"{elapsed_ms:.3f} ms [{status}]",
                flush=True,
            )

            if result.returncode != 0:
                print(
                    f"RUNTIME ERROR: exit code {result.returncode}",
                    flush=True,
                )
                if result.stderr:
                    print(
                        result.stderr.decode(errors="replace"),
                        file=sys.stderr,
                        flush=True,
                    )
                save_input(case, data)
                raise SystemExit(1)

        # 10回分の統計を表示
        batch = times[-BATCH_SIZE:]

        print(
            f"MIN {min(batch):.3f} ms | "
            f"MAX {max(batch):.3f} ms | "
            f"AVG {statistics.mean(batch):.3f} ms | "
            f"MED {statistics.median(batch):.3f} ms",
            flush=True,
        )
        print("-" * 70, flush=True)

except KeyboardInterrupt:
    print("\nStopped by user.", flush=True)

print("\n=== Benchmark finished ===", flush=True)
PY
