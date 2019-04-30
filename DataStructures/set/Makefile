executables = set_gcc set_clang set_intel

.PHONY: default
default: $(executables)

set_gcc: set.cpp
	time g++ -std=c++17 -O2 set.cpp -o set_gcc
	g++ -std=c++17 -O2 -S set.cpp -o set_gcc.s
set_clang: set.cpp
	time clang++ -std=c++17 -O2 set.cpp -o set_clang
	clang++ -std=c++17 -O2 -S set.cpp -o set_clang.s
set_intel: set.cpp
	time icpc -std=c++17 -O2 set.cpp -o set_intel
	icpc -std=c++17 -O2 -S set.cpp -o set_intel.s
.PHONY: clean
clean:
	rm -f set_gcc* set_clang* set_intel* buf.txt

.PHONY: suites
suites:
	sh SetTestSuite.sh

.PHONY: all
all: clean default
