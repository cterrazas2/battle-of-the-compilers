#!/bin/bash
>&2 echo "g++ stack file executing..."
./stack1
>&2 echo "clang++ stack file executing..."
./stack2
>&2 echo "icpc stack file executing..."
./stack3
