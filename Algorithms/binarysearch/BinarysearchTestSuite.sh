#!/bin/bash
echo "g++ binarysearch file executing..."
./binarysearch_gcc 2>buf.txt
echo "clang++ binarysearch file executing..."
./binarysearch_clang 2>buf.txt
echo "icpc binarysearch file executing..."
./binarysearch_intel 2>buf.txt
