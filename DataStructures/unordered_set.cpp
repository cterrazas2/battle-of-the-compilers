#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_set>
#include <random>
using namespace std;

/* Fills an unordered_set with random strings and then randomly removes elements from the unordered_set. */
void set_access(const vector<string>& rands, unordered_set<string>* unordered_set){
	// Test insertion
	for (const auto& elem: rands) {
		unordered_set->insert(elem);
	}

	default_random_engine real(0); 
	uniform_int_distribution<int> distribution(0, unordered_set->size());

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
	std::unordered_set<string> tempset;
	for (const auto& elem: rands) {
		tempset.insert(elem);
	}

	// Test swap
	for (int i=0; i < 10; i++){
		unordered_set->swap(tempset);
	}
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
	set_access(rands, &unordered_set);
	return 0;
}