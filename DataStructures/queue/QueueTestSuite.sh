#!/bin/bash
>&2 echo "g++ queue file executing..."
./queue1
>&2 echo "clang++ queue file executing..."
./queue2
>&2 echo "icpc queue file executing..."
./queue3
