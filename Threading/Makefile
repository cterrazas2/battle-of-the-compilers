executables = threading_gcc threading_clang threading_intel

.PHONY: default
default: $(executables)

threading_gcc: threading.cpp
	time g++ -std=c++17 -O2 threading.cpp -o threading_gcc
	g++ -std=c++17 -O2 -S threading.cpp -o threading_gcc.s
threading_clang: threading.cpp
	time clang++ -std=c++17 -O2 threading.cpp -o threading_clang
	clang++ -std=c++17 -O2 -S threading.cpp -o threading_clang.s
threading_intel: threading.cpp
	time icpc -std=c++17 -O2 threading.cpp -o threading_intel
	icpc -std=c++17 -O2 -S threading.cpp -o threading_intel.s
.PHONY: clean
clean:
	rm -f threading_gcc* threading_clang* threading_intel* buf.txt

.PHONY: suites
suites:
	sh ThreadingTestSuite.sh

.PHONY: all
all: clean default
