executables = stack_gcc stack_clang stack_intel

.PHONY: default
default: $(executables)

stack_gcc: stack.cpp
	time g++ -std=c++17 -O2 stack.cpp -o stack_gcc
	g++ -std=c++17 -O2 -S stack.cpp -o stack_gcc.s
stack_clang: stack.cpp
	time clang++ -std=c++17 -O2 stack.cpp -o stack_clang
	clang++ -std=c++17 -O2 -S stack.cpp -o stack_clang.s
stack_intel: stack.cpp
	time icpc -std=c++17 -O2 stack.cpp -o stack_intel
	icpc -std=c++17 -O2 -S stack.cpp -o stack_intel.s
.PHONY: clean
clean:
	rm -f stack_gcc* stack_clang* stack_intel* buf.txt

.PHONY: suites
suites:
	sh StackTestSuite.sh

.PHONY: all
all: clean default
