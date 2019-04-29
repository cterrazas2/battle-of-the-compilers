executables = threading1 threading2 threading3

.PHONY: default
default: $(executables)

threading1: threading.cpp
	time g++ -std=c++17 -O2 threading.cpp -o threading1
	g++ -std=c++17 -O2 -S threading.cpp -o threading1.s
threading2: threading.cpp
	time clang++ -std=c++17 -O2 threading.cpp -o threading2
	clang++ -std=c++17 -O2 -S threading.cpp -o threading2.s
threading3: threading.cpp
	time icpc -std=c++17 -O2 threading.cpp -o threading3
	icpc -std=c++17 -O2 -S threading.cpp -o threading3.s
.PHONY: clean
clean:
	rm -f *.s threading1 threading2 threading3 buf.txt

.PHONY: suites
suites:
	sh threadingTestSuite.sh

.PHONY: all
all: clean default
