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

echo "Compiling gutyo.cpp..."
"$CXX" gutyo.cpp -o TLE "${CXXFLAGS[@]}"
if [ $? -ne 0 ]; then
    echo "gutyo.cpp: CE"
    exit 1
fi

echo "Compiling generate.cpp..."
"$CXX" generate.cpp -o generate "${CXXFLAGS[@]}"
if [ $? -ne 0 ]; then
    echo "generate.cpp: CE"
    exit 1
fi

echo "=== Compilation successful ==="
echo

while :; do

    # テストケース生成
    ./generate > in.txt

    # main
    start_time=$(date +%s%3N)
    ./main < in.txt > out1.txt
    main_status=$?
    end_time=$(date +%s%3N)

    # TLE / 正解プログラム
    ./TLE < in.txt > out2.txt
    tle_status=$?

    # main の Runtime Error
    if [ $main_status -ne 0 ]; then
        echo
        echo "=============================="
        echo "RUNTIME ERROR!"
        echo "=============================="

        echo "--- Input ---"
        cat in.txt

        echo
        echo "--- Exit Code ---"
        echo "$main_status"

        break
    fi

    # TLE の Runtime Error
    if [ $tle_status -ne 0 ]; then
        echo
        echo "=============================="
        echo "TLE PROGRAM RUNTIME ERROR!"
        echo "=============================="

        echo "--- Input ---"
        cat in.txt

        break
    fi

    # 出力比較
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
