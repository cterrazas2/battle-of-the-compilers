executables = vec1 vec2 vec3

.PHONY: default
default: $(executables)

vec1: vector.cpp
	time g++ -std=c++17 -O2 vector.cpp -o vec1

vec2: vector.cpp
	time clang++ -std=c++17 -O2 vector.cpp -o vec2

vec3: vector.cpp
	time icpc -std=c++17 -O2 vector.cpp -o vec3

.PHONY: clean
clean:
	rm -f vec1 vec2 vec3 buf.txt

.PHONY: all
all: clean default
