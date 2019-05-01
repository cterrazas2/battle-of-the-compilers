#!/bin/bash
echo "g++ insertionsort file executing..."
./insertionsort_gcc 2>buf.txt
echo "clang++ insertionsort file executing..."
./insertionsort_clang 2>buf.txt
echo "icpc insertionsort file executing..."
./insertionsort_intel 2>buf.txt
