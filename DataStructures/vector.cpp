#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>
#include <set>

using namespace::std;
using namespace std::chrono;


void testVec(int* a, int* x, int n) {
	vector<int> v;
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
    int n = 5000;

    //run twice to account for cold caching
    for (int seed=0; seed<2; seed++) {
        default_random_engine re(seed);
        uniform_real_distribution<double> dist(0.0, 100000000); //reduce chance of collision

        int randn = 2*n;
        int a_rand[randn];
        for (int i=0; i<randn; i++)
            a_rand[i] = dist(re);
        set<int> a_unique(a_rand,a_rand+n);

        int a[n];
        auto tp = a_unique.begin();
        for (int i=0; i<n; i++)
            tp++;
        copy(a_unique.begin(), tp, a);

        //construct array of random indices to remove
        int x[n];
        for (int i=0; i<n; i++) {
            uniform_real_distribution<double> dist2(0,n-i);
            x[i] = dist2(re);
        }
    
        auto start = system_clock::now();
        testVec(a,x,n);
        auto end = system_clock::now();
        auto dur = duration_cast<milliseconds>(end-start).count();
        
        //ignore first trial
        if (seed != 0)
            cout << dur << endl;
    }
		
	return 0;
}

