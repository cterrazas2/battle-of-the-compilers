#!/bin/bash
echo "g++ list file executing..."
./list_gcc 2>buf.txt
echo "clang++ list file executing..."
./list_clang 2>buf.txt
echo "icpc list file executing..."
./list_intel 2>buf.txt
