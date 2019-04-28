#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_set>
#include <random>
#include <string>
using namespace std;

/* Fills an unordered_set with random strings and then randomly removes elements from the unordered_set. */
void set_access(const vector<string>& rands, unordered_set<string>* unordered_set){
	// Test insertion
	for (const auto& elem: rands) {
		unordered_set->insert(elem);
	}
	std::cerr << unordered_set->size() << "\n";
	default_random_engine real(0); 
	uniform_int_distribution<int> distribution(0, unordered_set->size());

	std::cerr << unordered_set->size() << "\n";

	// Test deletion
	for (int i=0; i < unordered_set->size();){
		int pos = distribution(real);
		if (pos < unordered_set->size()){
			auto it = unordered_set->begin();
			for (int z = 0; z < pos; z++){
				it++;
			}
			unordered_set->erase(it);
			++i;
		}
	}
	std::cerr << unordered_set->size() << "\n";
	unordered_set->clear();
	std::cerr << unordered_set->size() << "\n";
	std::unordered_set<string> tempset;
	for (const auto& elem: rands) {
		tempset.insert(elem);
	}

	std::cerr << tempset.size() << "\n";
	// Test swap
	unordered_set->swap(tempset);
	std::cerr << unordered_set->size() << "\n";
}

/* Times unordered_set function */
void time(void (*fn)(const std::vector<string>&, std::unordered_set<string>*), const std::vector<string>& rands, std::unordered_set<string>* unordered_set){
	auto start = chrono::high_resolution_clock::now();
	fn(rands, unordered_set);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	cout << "cold cache took time: " << duration << " milliseconds" << endl;
	start = chrono::high_resolution_clock::now();
	fn(rands, unordered_set);
	end = chrono::high_resolution_clock::now();
	duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	cout << "warm cache took time: " << duration << " milliseconds" << endl;
}

int main() {
	default_random_engine re(0); 
	uniform_int_distribution<int> dist(0, 100000000);
	int size = 5000;
	std::vector<string> rands(size);
	for (int i=0; i < size; ++i){
		rands.push_back(to_string(dist(re)));
	}
	std::cout << rands[0];
	std::unordered_set<string> unordered_set;
	time(set_access, rands, &unordered_set);
	return 0;
}