#!/bin/bash
echo "g++ threading file executing..."
./threading_gcc 2>buf.txt
echo "clang++ threading file executing..."
./threading_clang 2>buf.txt
echo "icpc threading file executing..."
./threading_intel 2>buf.txt
