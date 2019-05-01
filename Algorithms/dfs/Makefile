executables = dfs_gcc dfs_clang dfs_intel

.PHONY: default
default: $(executables)

dfs_gcc: dfs.cpp
	time g++ -std=c++17 -O2 dfs.cpp -o dfs_gcc
	g++ -std=c++17 -O2 -S dfs.cpp -o dfs_gcc.s
dfs_clang: dfs.cpp
	time clang++ -std=c++17 -O2 dfs.cpp -o dfs_clang
	clang++ -std=c++17 -O2 -S dfs.cpp -o dfs_clang.s
dfs_intel: dfs.cpp
	time icpc -std=c++17 -O2 dfs.cpp -o dfs_intel
	icpc -std=c++17 -O2 -S dfs.cpp -o dfs_intel.s
.PHONY: clean
clean:
	rm -f dfs_gcc* dfs_clang* dfs_intel* buf.txt

.PHONY: suites
suites:
	sh DfsTestSuite.sh

.PHONY: all
all: clean default
