#!/bin/bash 
>&2 echo "g++ compiling..."
./map1
>&2 echo "clang++ compiling..."
./map2
>&2 echo "icpc compiling..."
./map3
