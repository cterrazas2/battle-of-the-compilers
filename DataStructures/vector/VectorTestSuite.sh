#!/bin/bash
echo "g++ vector file executing..."
./vector_gcc 2>buf.txt
echo "clang++ vector file executing..."
./vector_clang 2>buf.txt
echo "icpc vector file executing..."
./vector_intel 2>buf.txt
