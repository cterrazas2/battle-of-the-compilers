#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace::std;
using namespace std::chrono;

template<typename T>
void generateRandom(unordered_set<T>& rs, const int MAX, const int N)
{
  random_device rd;
  default_random_engine dr(rd());
  uniform_int_distribution<int> ud(0,MAX);
  int rando = 0;

  for (int i=0;i<N;i++) {
    rando = ud(dr);
    auto f = rs.find(rando);

    if (f != rs.end()) { // found a duplicate
       int tmp = rando;

       for (int i = 0;i<MAX;i++) {
         if (i != tmp) {
           rando = ud(dr);
           auto f = rs.find(rando);
           if (f == rs.end()) {
              rs.insert(rando); // generate the first unique random and break, must insert each loop
              break;
           }
         }
       }

    } else {
       rs.insert(rando);
    }

  }
    	cerr << rs.size();
}

template<typename T>
void insert(const unordered_set<T> us, vector<T>& vec)
{
  for (auto i = us.begin();i!=us.end();i++) {
        vec.push_back(*i);
  }
    	cerr << vec.size();
}

template<typename T>
void InsertionSort(vector<T>& vec)
{
  for (int i=1;i<vec.size();i++) {
      int k = vec[i];
      int j = i-1;
      while (j >= 0 && vec[j] > k) {
        vec[j+1] = vec[j];
        j = j-1;
      }
      vec[j+1] = k;
  }
    	cerr << vec.size();
}

int main() {

  int MAX = 1000000;
  int N = 10000; // Default num integers.
  unordered_set<int> rs;
  vector<int> vec;

  generateRandom(rs,MAX,N);
  insert(rs,vec);

  auto start = system_clock::now();
  InsertionSort(vec);
  auto end = system_clock::now();
  auto time_trial = duration_cast<milliseconds>(end-start).count();
  cerr << "Insertion Sort Time: " << time_trial << "ms\n";
  return 0;
}
