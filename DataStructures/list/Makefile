executables = list_gcc list_clang list_intel

.PHONY: default
default: $(executables)

list_gcc: list.cpp
	time g++ -std=c++17 -O2 list.cpp -o list_gcc
	g++ -std=c++17 -O2 -S list.cpp -o list_gcc.s
list_clang: list.cpp
	time clang++ -std=c++17 -O2 list.cpp -o list_clang
	clang++ -std=c++17 -O2 -S list.cpp -o list_clang.s
list_intel: list.cpp
	time icpc -std=c++17 -O2 list.cpp -o list_intel
	icpc -std=c++17 -O2 -S list.cpp -o list_intel.s
.PHONY: clean
clean:
	rm -f list_gcc* list_clang* list_intel* buf.txt

.PHONY: suites
suites:
	sh ListTestSuite.sh

.PHONY: all
all: clean default
