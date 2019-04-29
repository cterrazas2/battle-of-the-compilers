#!/bin/bash
>&2 echo "g++ map file executing..."
./map1
>&2 echo "clang++ map file executing..."
./map2
>&2 echo "icpc map file executing..."
./map3
