executables = uset1 uset2 uset3

.PHONY: default
default: $(executables)

uset1: unordered_set.cpp
	time g++ -std=c++17 -O2 unordered_set.cpp -o uset1
	g++ -std=c++17 -O2 -S unordered_set.cpp -o uset1.s
uset2: unordered_set.cpp
	time clang++ -std=c++17 -O2 unordered_set.cpp -o uset2
	clang++ -std=c++17 -O2 -S unordered_set.cpp -o uset2.s
uset3: unordered_set.cpp
	time icpc -std=c++17 -O2 unordered_set.cpp -o uset3
	icpc -std=c++17 -O2 -S unordered_set.cpp -o uset3.s
.PHONY: clean
clean:
	rm -f *.s uset1 uset2 uset3 buf.txt

.PHONY: suites
suites:
	sh UsetTestSuite.sh

.PHONY: all
all: clean default
