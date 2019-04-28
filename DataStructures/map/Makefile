executables = map1 map2 map3

.PHONY: default
default: $(executables)

map1: map.cpp
	time g++ -std=c++17 -O2 map.cpp -o map1
	g++ -std=c++17 -O2 -S map.cpp -o map1.s
map2: map.cpp
	time clang++ -std=c++17 -O2 map.cpp -o map2
	clang++ -std=c++17 -O2 -S map.cpp -o map2.s
map3: map.cpp
	time icpc -std=c++17 -O2 map.cpp -o map3
	icpc -std=c++17 -O2 -S map.cpp -o map3.s
.PHONY: clean
clean:
	rm -f *.s map1 map2 map3 buf.txt

.PHONY: suites
suites:
	sh MapTestSuite.sh

.PHONY: all
all: clean default
