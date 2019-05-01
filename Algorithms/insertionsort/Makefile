executables = insertionsort_gcc insertionsort_clang insertionsort_intel

.PHONY: default
default: $(executables)

insertionsort_gcc: insertionsort.cpp
	time g++ -std=c++17 -O2 insertionsort.cpp -o insertionsort_gcc
	g++ -std=c++17 -O2 -S insertionsort.cpp -o insertionsort_gcc.s
insertionsort_clang: insertionsort.cpp
	time clang++ -std=c++17 -O2 insertionsort.cpp -o insertionsort_clang
	clang++ -std=c++17 -O2 -S insertionsort.cpp -o insertionsort_clang.s
insertionsort_intel: insertionsort.cpp
	time icpc -std=c++17 -O2 insertionsort.cpp -o insertionsort_intel
	icpc -std=c++17 -O2 -S insertionsort.cpp -o insertionsort_intel.s
.PHONY: clean
clean:
	rm -f insertionsort_gcc* insertionsort_clang* insertionsort_intel* buf.txt

.PHONY: suites
suites:
	sh InsertionsortTestSuite.sh

.PHONY: all
all: clean default
