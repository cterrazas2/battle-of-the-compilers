executables = queue1 queue2 queue3

.PHONY: default
default: $(executables)

queue1: queue.cpp
	time g++ -std=c++17 -O2 queue.cpp -o queue1
	g++ -std=c++17 -O2 -S queue.cpp -o queue1.s
queue2: queue.cpp
	time clang++ -std=c++17 -O2 queue.cpp -o queue2
	clang++ -std=c++17 -O2 -S queue.cpp -o queue2.s
queue3: queue.cpp
	time icpc -std=c++17 -O2 queue.cpp -o queue3
	icpc -std=c++17 -O2 -S queue.cpp -o queue3.s
.PHONY: clean
clean:
	rm -f *.s queue1 queue2 queue3 buf.txt

.PHONY: all
all: clean default
