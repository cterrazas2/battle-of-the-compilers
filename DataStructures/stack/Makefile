executables = stack1 stack2 stack3

.PHONY: default
default: $(executables)

stack1: stack.cpp
	time g++ -std=c++17 -O2 stack.cpp -o stack1
	g++ -std=c++17 -O2 -S stack.cpp -o stack1.s
stack2: stack.cpp
	time clang++ -std=c++17 -O2 stack.cpp -o stack2
	clang++ -std=c++17 -O2 -S stack.cpp -o stack2.s
stack3: stack.cpp
	time icpc -std=c++17 -O2 stack.cpp -o stack3
	icpc -std=c++17 -O2 -S stack.cpp -o stack3.s
.PHONY: clean
clean:
	rm -f *.s stack1 stack2 stack3 buf.txt

.PHONY: all
all: clean default
