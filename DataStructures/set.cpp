#include <iostream>
#include <chrono>
#include <vector>
#include <set>
#include <random>
using namespace std;

/* Fills a set with random strings and then randomly removes elements from the set. */
void set_access(const vector<string>& rands, set<string>* set){
	// Test insertion
	for (const auto& elem: rands) {
		set->insert(elem);
	}

	default_random_engine real(0); 
	uniform_int_distribution<int> distribution(0, set->size());

	// Test deletion
	for (int i=0; i < set->size();){
		int pos = distribution(real);
		if (pos < set->size()){
			auto it = set->begin();
			for (int z = 0; z < pos; z++){
				it++;
			}
			set->erase(it);
			++i;
		}
	}
	std::set<string> tempset;
	for (const auto& elem: rands) {
		tempset.insert(elem);
	}

	// Test swap
	for (int i=0; i < 10; i++){
		set->swap(tempset);
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
	std::set<string> set;
	set_access(rands, &set);
	return 0;
}