executables = vector_gcc vector_clang vector_intel

.PHONY: default
default: $(executables)

vector_gcc: vector.cpp
	time g++ -std=c++17 -O2 vector.cpp -o vector_gcc
	g++ -std=c++17 -O2 -S vector.cpp -o vector_gcc.s
vector_clang: vector.cpp
	time clang++ -std=c++17 -O2 vector.cpp -o vector_clang
	clang++ -std=c++17 -O2 -S vector.cpp -o vector_clang.s
vector_intel: vector.cpp
	time icpc -std=c++17 -O2 vector.cpp -o vector_intel
	icpc -std=c++17 -O2 -S vector.cpp -o vector_intel.s
.PHONY: clean
clean:
	rm -f vector_gcc* vector_clang* vector_intel* buf.txt

.PHONY: suites
suites:
	sh VectorTestSuite.sh

.PHONY: all
all: clean default
