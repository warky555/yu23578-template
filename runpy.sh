#!/bin/bash

testcase_counter=0

trap 'echo; echo "Stopped."; exit 0' INT

echo "=== Compile ==="

CXX="g++"
CXXFLAGS=(
    -O2
    -march=native
    -w
    -DATCODER
    -DONLINE_JUDGE
    -std=gnu++23
)

echo "Compiling main.cpp..."
"$CXX" main.cpp -o main "${CXXFLAGS[@]}"

if [ $? -ne 0 ]; then
    echo "main.cpp: CE"
    exit 1
fi

echo "Compiling TLE.cpp..."
"$CXX" TLE.cpp -o TLE "${CXXFLAGS[@]}"

if [ $? -ne 0 ]; then
    echo "TLE.cpp: CE"
    exit 1
fi

echo "=== Compilation successful ==="
echo

while :; do
    python3 generate.py > in.txt

    start_time=$(date +%s%3N)
    ./main < in.txt > out1.txt
    main_status=$?
    end_time=$(date +%s%3N)

    ./TLE < in.txt > out2.txt
    tle_status=$?

    if [ $main_status -ne 0 ]; then
        echo
        echo "=============================="
        echo "Runtime Error!"
        echo "=============================="
        echo "--- Input ---"
        cat in.txt
        echo "--- Exit Code ---"
        echo "$main_status"
        break
    fi

    if [ $tle_status -ne 0 ]; then
        echo
        echo "TLE program Runtime Error!"
        break
    fi

    if ! diff -ZB out1.txt out2.txt > /dev/null; then
        echo
        echo "=============================="
        echo "FOUND WRONG ANSWER!"
        echo "=============================="

        echo
        echo "--- Input ---"
        cat in.txt

        echo
        echo "--- Your Output ---"
        cat out1.txt

        echo
        echo "--- Correct Output ---"
        cat out2.txt

        break
    fi

    ((testcase_counter++))
    diff_ms=$((end_time - start_time))
    echo "TESTCASE ${testcase_counter} : AC (${diff_ms} ms)"
done