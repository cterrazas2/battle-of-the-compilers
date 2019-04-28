#include <iostream>
#include <chrono>
#include <vector>
#include <set>
#include <random>
#include <string>
using namespace std;

/* Fills a set with random strings and then randomly removes elements from the set. */
void set_access(const vector<string>& rands, set<string>* set){
	// Test insertion
	for (const auto& elem: rands) {
		set->insert(elem);
	}

	std::cerr << set->size() << "\n";

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

	std::cerr << set->size() << "\n";

	std::set<string> tempset;
	for (const auto& elem: rands) {
		tempset.insert(elem);
	}

	std::cerr << set->size() << "\n";
	// Test swap 
	set->swap(tempset);
	std::cerr << set->size() << "\n";
}

/* Times set function */
void time(void (*fn)(const std::vector<string>&, std::set<string>*), const std::vector<string>& rands, std::set<string>* set){
	auto start = chrono::high_resolution_clock::now();
	fn(rands, set);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	cout << "cold cache took time: " << duration << " milliseconds" << endl;
	start = chrono::high_resolution_clock::now();
	fn(rands, set);
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
	std::set<string> set;
	time(set_access, rands, &set);
	return 0;
}