executables = binarysearch_gcc binarysearch_clang binarysearch_intel

.PHONY: default
default: $(executables)

binarysearch_gcc: binarysearch.cpp
	time g++ -std=c++17 -O2 binarysearch.cpp -o binarysearch_gcc
	g++ -std=c++17 -O2 -S binarysearch.cpp -o binarysearch_gcc.s
binarysearch_clang: binarysearch.cpp
	time clang++ -std=c++17 -O2 binarysearch.cpp -o binarysearch_clang
	clang++ -std=c++17 -O2 -S binarysearch.cpp -o binarysearch_clang.s
binarysearch_intel: binarysearch.cpp
	time icpc -std=c++17 -O2 binarysearch.cpp -o binarysearch_intel
	icpc -std=c++17 -O2 -S binarysearch.cpp -o binarysearch_intel.s
.PHONY: clean
clean:
	rm -f binarysearch_gcc* binarysearch_clang* binarysearch_intel* buf.txt

.PHONY: suites
suites:
	sh BinarysearchTestSuite.sh

.PHONY: all
all: clean default
