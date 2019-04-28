executables = list1 list2 list3

.PHONY: default
default: $(executables)

list1: list.cpp
	time g++ -std=c++17 -O2 list.cpp -o list1
	g++ -std=c++17 -O2 -S list.cpp -o list1.s
list2: list.cpp
	time clang++ -std=c++17 -O2 list.cpp -o list2
	clang++ -std=c++17 -O2 -S list.cpp -o list2.s
list3: list.cpp
	time icpc -std=c++17 -O2 list.cpp -o list3
	icpc -std=c++17 -O2 -S list.cpp -o list3.s
.PHONY: clean
clean:
	rm -f *.s list1 list2 list3 buf.txt

.PHONY: all
all: clean default
