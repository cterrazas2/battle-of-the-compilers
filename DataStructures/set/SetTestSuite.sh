#!/bin/bash
echo "g++ set file executing..."
./set_gcc 2>buf.txt
echo "clang++ set file executing..."
./set_clang 2>buf.txt
echo "icpc set file executing..."
./set_intel 2>buf.txt
