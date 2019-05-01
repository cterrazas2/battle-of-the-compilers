#!/bin/bash
# Run this Script to test all test suites all at once

dir=$(pwd)

# Make/Test DataStructures
cd $dir/DataStructures/list/
make
make suites
cd ../map
make
make suites
cd ../queue
make
make suites
cd ../set
make
make suites
cd ../stack
make
make suites
cd ../uset
make
make suites
cd ../vector
make
make suites

# Clean Up DataStructures
cd $dir/DataStructures/list/
make clean
cd ../map
make clean
cd ../queue
make clean
cd ../set
make clean
cd ../stack
make clean
cd ../uset
make clean
cd ../vector
make clean

# Make/Test Algos
cd $dir/Algorithms/bfs
make
make suites
cd ../binarysearch
make
make suites
cd ../dfs
make
make suites
cd ../isort
make
make suites

# Clean Up Algos
cd $dir/Algorithms/bfs
make clean
cd ../binarysearch
make clean
cd ../dfs
make clean
cd ../isort
make clean

# Make/Test Threading
cd $dir/Threading
make
make suites

# Clean Threading
cd $dir/Threading
make clean
