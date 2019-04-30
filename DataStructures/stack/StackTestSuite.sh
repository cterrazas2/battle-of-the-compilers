#!/bin/bash
echo "g++ stack file executing..."
./stack_gcc 2>buf.txt
echo "clang++ stack file executing..."
./stack_clang 2>buf.txt
echo "icpc stack file executing..."
./stack_intel 2>buf.txt
