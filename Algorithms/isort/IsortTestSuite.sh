#!/bin/bash
echo "g++ isort file executing..."
./isort_gcc 2>buf.txt
echo "clang++ isort file executing..."
./isort_clang 2>buf.txt
echo "icpc isort file executing..."
./isort_intel 2>buf.txt
