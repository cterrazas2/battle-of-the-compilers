executables = isort_gcc isort_clang isort_intel

.PHONY: default
default: $(executables)

isort_gcc: insertionsort.cpp
	time g++ -std=c++17 -O2 insertionsort.cpp -o isort_gcc
	g++ -std=c++17 -O2 -S insertionsort.cpp -o isort_gcc.s
isort_clang: insertionsort.cpp
	time clang++ -std=c++17 -O2 insertionsort.cpp -o isort_clang
	clang++ -std=c++17 -O2 -S insertionsort.cpp -o isort_clang.s
isort_intel: insertionsort.cpp
	time icpc -std=c++17 -O2 insertionsort.cpp -o isort_intel
	icpc -std=c++17 -O2 -S insertionsort.cpp -o isort_intel.s
.PHONY: clean
clean:
	rm -f isort_gcc* isort_clang* isort_intel* buf.txt

.PHONY: suites
suites:
	sh IsortTestSuite.sh

.PHONY: all
all: clean default
