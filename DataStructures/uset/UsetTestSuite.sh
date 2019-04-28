#!/bin/bash 
>&2 echo "g++ compiling..."
./uset1
>&2 echo "clang++ compiling..."
./uset2
>&2 echo "icpc compiling..."
./uset3
