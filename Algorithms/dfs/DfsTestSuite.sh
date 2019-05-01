#!/bin/bash
echo "g++ dfs file executing..."
./dfs_gcc 2>buf.txt
echo "clang++ dfs file executing..."
./dfs_clang 2>buf.txt
echo "icpc dfs file executing..."
./dfs_intel 2>buf.txt
