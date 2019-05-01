#!/bin/bash
echo "g++ bfs file executing..."
./bfs_gcc 2>buf.txt
echo "clang++ bfs file executing..."
./bfs_clang 2>buf.txt
echo "icpc bfs file executing..."
./bfs_intel 2>buf.txt
