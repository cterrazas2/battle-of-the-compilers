/*
 * author: Christopher Terrazas
 * uni: ct2856
 * insertionsort.cpp: file for utilizing insertion sort on a vector.
 * Used following resources:
 *  Tour of C++ - Bjarne Stroustrup
 *  https://en.cppreference.com
 */
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace::std;
using namespace std::chrono;

/*
 *  generateRandom - Generates a random set of integers based on MAX and N.
 *  params: unordered set, max bound, N bound
 *  return: void
*/
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

/*
 * insert - inserts elements in non-decreasing order into a vector.
 * params: unordered set, vector
 * return: void
*/
template<typename T>
void insert(const unordered_set<T> us, vector<T>& vec)
{
  for (auto i = us.begin();i!=us.end();i++) {
        vec.push_back(*i);
  }
    	cerr << vec.size();
}

/*
 * InsertionSort - sorts elements in vector using insertion sort
 * params: vector
 * return: void
*/
template<typename T>
void InsertionSort(vector<T>& vec)
{
  for (int i=1;i<vec.size();i++) {
      auto k = vec[i];
      auto j = i-1;
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
