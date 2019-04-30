#!/bin/bash
echo "g++ map file executing..."
./map_gcc 2>buf.txt
echo "clang++ map file executing..."
./map_clang 2>buf.txt
echo "icpc map file executing..."
./map_intel 2>buf.txt
