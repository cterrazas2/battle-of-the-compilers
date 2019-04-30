#!/bin/bash
echo "g++ uset file executing..."
./uset_gcc 2>buf.txt
echo "clang++ uset file executing..."
./uset_clang 2>buf.txt
echo "icpc uset file executing..."
./uset_intel 2>buf.txt
