executables = uset_gcc uset_clang uset_intel

.PHONY: default
default: $(executables)

uset_gcc: unordered_set.cpp
	time g++ -std=c++17 -O2 unordered_set.cpp -o uset_gcc
	g++ -std=c++17 -O2 -S unordered_set.cpp -o uset_gcc.s
uset_clang: unordered_set.cpp
	time clang++ -std=c++17 -O2 unordered_set.cpp -o uset_clang
	clang++ -std=c++17 -O2 -S unordered_set.cpp -o uset_clang.s
uset_intel: unordered_set.cpp
	time icpc -std=c++17 -O2 unordered_set.cpp -o uset_intel
	icpc -std=c++17 -O2 -S unordered_set.cpp -o uset_intel.s
.PHONY: clean
clean:
	rm -f uset_gcc* uset_clang* uset_intel* buf.txt

.PHONY: suites
suites:
	sh UsetTestSuite.sh

.PHONY: all
all: clean default
