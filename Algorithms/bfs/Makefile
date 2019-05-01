executables = bfs_gcc bfs_clang bfs_intel

.PHONY: default
default: $(executables)

bfs_gcc: bfs.cpp
	time g++ -std=c++17 -O2 bfs.cpp -o bfs_gcc
	g++ -std=c++17 -O2 -S bfs.cpp -o bfs_gcc.s
bfs_clang: bfs.cpp
	time clang++ -std=c++17 -O2 bfs.cpp -o bfs_clang
	clang++ -std=c++17 -O2 -S bfs.cpp -o bfs_clang.s
bfs_intel: bfs.cpp
	time icpc -std=c++17 -O2 bfs.cpp -o bfs_intel
	icpc -std=c++17 -O2 -S bfs.cpp -o bfs_intel.s
.PHONY: clean
clean:
	rm -f bfs_gcc* bfs_clang* bfs_intel* buf.txt

.PHONY: suites
suites:
	sh BfsTestSuite.sh

.PHONY: all
all: clean default
