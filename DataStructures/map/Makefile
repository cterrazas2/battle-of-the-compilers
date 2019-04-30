executables = map_gcc map_clang map_intel

.PHONY: default
default: $(executables)

map_gcc: map.cpp
	time g++ -std=c++17 -O2 map.cpp -o map_gcc
	g++ -std=c++17 -O2 -S map.cpp -o map_gcc.s
map_clang: map.cpp
	time clang++ -std=c++17 -O2 map.cpp -o map_clang
	clang++ -std=c++17 -O2 -S map.cpp -o map_clang.s
map_intel: map.cpp
	time icpc -std=c++17 -O2 map.cpp -o map_intel
	icpc -std=c++17 -O2 -S map.cpp -o map_intel.s
.PHONY: clean
clean:
	rm -f map_gcc* map_clang* map_intel* buf.txt

.PHONY: suites
suites:
	sh MapTestSuite.sh

.PHONY: all
all: clean default
