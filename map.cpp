#include <iostream>
#include <chrono>
#include <vector>
#include <map>
#include <random>
using namespace std;

/* Fills a map with random elements and then randomly removes elements from the map. */
void time_map(const std::vector<int>& rands, std::map<int, int>* map){
	auto start = chrono::high_resolution_clock::now();
	for (const auto& elem: rands) {
		(*map)[elem] = 0;
	}

	default_random_engine real(0); 
	uniform_int_distribution<int> distribution(0, map->size());

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
	time_map(rands, &map);
	return 0;
}