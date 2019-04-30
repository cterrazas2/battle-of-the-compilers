executables = queue_gcc queue_clang queue_intel

.PHONY: default
default: $(executables)

queue_gcc: queue.cpp
	time g++ -std=c++17 -O2 queue.cpp -o queue_gcc
	g++ -std=c++17 -O2 -S queue.cpp -o queue_gcc.s
queue_clang: queue.cpp
	time clang++ -std=c++17 -O2 queue.cpp -o queue_clang
	clang++ -std=c++17 -O2 -S queue.cpp -o queue_clang.s
queue_intel: queue.cpp
	time icpc -std=c++17 -O2 queue.cpp -o queue_intel
	icpc -std=c++17 -O2 -S queue.cpp -o queue_intel.s
.PHONY: clean
clean:
	rm -f queue_gcc* queue_clang* queue_intel* buf.txt

.PHONY: suites
suites:
	sh QueueTestSuite.sh

.PHONY: all
all: clean default
