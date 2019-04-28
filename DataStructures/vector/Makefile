executables = vector1 vector2 vector3

.PHONY: default
default: $(executables)

vector1: vector.cpp
	time g++ -std=c++17 -O2 vector.cpp -o vector1
	g++ -std=c++17 -O2 -S vector.cpp -o vector1.s
vector2: vector.cpp
	time clang++ -std=c++17 -O2 vector.cpp -o vector2
	clang++ -std=c++17 -O2 -S vector.cpp -o vector2.s
vector3: vector.cpp
	time icpc -std=c++17 -O2 vector.cpp -o vector3
	icpc -std=c++17 -O2 -S vector.cpp -o vector3.s
.PHONY: clean
clean:
	rm -f *.s vector1 vector2 vector3 buf.txt

.PHONY: suites
suites:
	sh VectorTestSuite.sh

.PHONY: all
all: clean default
