#!/bin/bash
>&2 echo "g++ threading file executing..."
./threading1
>&2 echo "clang++ threading file executing..."
./threading2
>&2 echo "icpc threading file executing..."
./threading3
