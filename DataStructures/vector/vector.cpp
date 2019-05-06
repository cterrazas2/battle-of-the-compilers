#include <iostream>
#include <chrono>
#include <vector>
#include <random>

using namespace::std;
using namespace std::chrono;


void testVec(int* a, int* x, int n) {
	vector<int> v;

// test performance of intel with preallocation
//	v.reserve(n);

	for (int i=0; i<n; i++) {
		auto it=v.begin();
		if (i != 0) {
			while(*it < a[i]) {
				if (it == v.end())
					break;
				it++;
			}
		}
		v.insert(it,a[i]);
	}

	cerr << v.size();

	for (int i=0; i<n; i++) {
		auto it=v.begin();
		int pos = 0;
		while(pos < x[i]) {
			it++;
			pos++;
		}
		v.erase(it);
	}

	cerr << v.size();
}


//main function
int main() {
    //run twice: once for warm, once for cold cache
    for (int seed=0; seed<2; seed++) {
        default_random_engine re(seed);
        uniform_real_distribution<double> dist(0.0, 100000000); //reduce chance of collision

		int a[10000];
		for (int i = 0; i < 10000; i++) {
			a[i] = dist(re);
		}

        //construct array of random indices to remove
		int x[10000];
        for (int i=0; i<10000; i++) {
            uniform_real_distribution<double> dist2(0,10000-i);
            x[i] = dist2(re);
        }
    
        auto start = system_clock::now();
        testVec(a,x,10000);
        auto end = system_clock::now();
        auto dur = duration_cast<milliseconds>(end-start).count();
        cerr << dur << endl;
        
        if (seed == 0)
            cout << "runtime (cold):" << dur << endl;
        else if (seed == 1)
            cout << "runtime (warm):" << dur << endl;
    }
	return 0;
}

