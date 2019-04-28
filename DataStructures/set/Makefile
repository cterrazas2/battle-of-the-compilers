executables = set1 set2 set3

.PHONY: default
default: $(executables)

set1: set.cpp
	time g++ -std=c++17 -O2 set.cpp -o set1
	g++ -std=c++17 -O2 -S set.cpp -o set1.s
set2: set.cpp
	time clang++ -std=c++17 -O2 set.cpp -o set2
	clang++ -std=c++17 -O2 -S set.cpp -o set2.s
set3: set.cpp
	time icpc -std=c++17 -O2 set.cpp -o set3
	icpc -std=c++17 -O2 -S set.cpp -o set3.s
.PHONY: clean
clean:
	rm -f *.s set1 set2 set3 buf.txt

.PHONY: all
all: clean default
