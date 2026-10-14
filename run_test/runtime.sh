
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

python3 - <<'PY'
import subprocess
import time
import statistics
import sys

REPEATS = 7
TIME_LIMIT_MS = 2000
RUN_TIMEOUT = 10

case = 0

try:
    while True:
        # 入力生成は計測対象外
        gen = subprocess.run(
            ["./generate"],
            stdout=subprocess.PIPE,
            check=True,
            timeout=RUN_TIMEOUT,
        )
        data = gen.stdout

        times = []
        failed = False

        for _ in range(REPEATS):
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
                print(f"\nTIMEOUT: testcase {case + 1}")
                failed = True
                break

            elapsed = time.perf_counter_ns() - start

            if result.returncode != 0:
                print(f"\nRUNTIME ERROR: testcase {case + 1}")
                print("Exit code:", result.returncode)
                print("--- Input ---")
                sys.stdout.flush()
                print(data.decode(errors="replace"))
                failed = True
                break

            times.append(elapsed / 1_000_000)

        if failed:
            break

        case += 1

        minimum = min(times)
        median = statistics.median(times)
        average = statistics.mean(times)
        maximum = max(times)

        status = "TLE" if median >= TIME_LIMIT_MS else "OK"

        print(
            f"TESTCASE {case}: {status} | "
            f"MIN {minimum:.3f} ms | "
            f"MEDIAN {median:.3f} ms | "
            f"AVG {average:.3f} ms | "
            f"MAX {maximum:.3f} ms",
            flush=True,
        )

        if status == "TLE":
            print("\n--- Input ---")
            print(data.decode(errors="replace"))
            break

except KeyboardInterrupt:
    print("\nStopped.")
PY
