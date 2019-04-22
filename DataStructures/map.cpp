#include <iostream>
#include <chrono>
#include <vector>
#include <map>
#include <random>
using namespace std;

/* Fills a map with random elements and then randomly removes elements from the map. */
void map_access(const std::vector<int>& rands, std::map<int, int>* map){
	// Test insertion
	for (const auto& elem: rands) {
		(*map)[elem] = 0;
	}

	default_random_engine real(0); 
	uniform_int_distribution<int> distribution(0, map->size());

	// Test deletion
	for (int i=0; i < map->size();){
		int pos = distribution(real);
		if (pos < map->size()){
			auto it = map->begin();
			for (int z = 0; z < pos; z++){
				it++;
			}
			map->erase(it);
			++i;
		}
	}

	for (const auto& elem: rands) {
		(*map)[elem] = 0;
	}

	// Test map lookup 
	for (int i=0; i < 10; i++){
		int key = distribution(real);
		auto search = map->find(key);
		if (search != map->end()) {
			(*map)[key] = 1;
		}
	}
}

/* Times map function */
void time(void (*fn)(const std::vector<int>&, std::map<int, int>*), const std::vector<int>& rands, std::map<int, int>* map){
	fn(rands, map);
	auto start = chrono::high_resolution_clock::now();
	fn(rands, map);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	cout << "map took time: " << duration << " milliseconds" << endl;
}

int main() {
	default_random_engine re(0); 
	uniform_int_distribution<int> dist(0, 100000000);
	int size = 5000;
	std::vector<int> rands(size);
	for (int i=0; i < size; ++i){
		rands.push_back(dist(re));
	}
	std::map<int, int> map;
	time(map_access, rands, &map);
	return 0;
}