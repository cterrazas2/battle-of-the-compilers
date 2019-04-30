#!/bin/bash
echo "g++ queue file executing..."
./queue_gcc 2>buf.txt
echo "clang++ queue file executing..."
./queue_clang 2>buf.txt
echo "icpc queue file executing..."
./queue_intel 2>buf.txt
