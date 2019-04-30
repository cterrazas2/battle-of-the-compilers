/*
 * author: Christopher Terrazas
 * uni: ct2856
 * threading.cpp: file for testing multiple threads.
 * Used following resources:
 *  Tour of C++ - Bjarne Stroustrup
 *  https://en.cppreference.com
 */

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <unordered_set>
#include <chrono>
#include <thread>


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
 * insert - inserts elements into a vector.
 * params: unordered set, vector
 * return: void
*/
template<typename T>
void insert(const unordered_set<T> rs, vector<T>& vec)
{
  for (auto i = rs.begin();i!=rs.end();i++)
            vec.push_back(*i);

  cerr << vec.size();

}

/*
 * erase - Erases elements in a vector.
 * params: vector
 * return: void
*/
template<typename T>
void erase(vector<T>& vec)
{
  while(!vec.empty())
      vec.pop_back();

  cerr << vec.size();
}

template<typename T>
void print(T v)
{
  if (v.size()) {
      cerr << "[";
      for (auto n: v) {
            cerr << n << "," ;
          }
          cerr <<  "]\n";
  } else { cerr << "[]\n"; }
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
  int N = 100000; // Default num integers.

  auto start = system_clock::now();

  unordered_set<int> rs;
  vector<int> vec;
  std::thread t1(generateRandom<int>, std::ref(rs), std::ref(MAX), std::ref(N) );
  t1.join();

  std::thread t2(insert<int>, std::ref(rs), std::ref(vec) );
  t2.join();


  std::thread t3(InsertionSort<int>, std::ref(vec) );
  t3.join();
  //print(vec);

  std::thread t4(erase<int>, std::ref(vec) );
  t4.join();

  auto end = system_clock::now();
  auto time_trial = duration_cast<milliseconds>(end-start).count();

  cout << "Multiple Threads Time: " << time_trial << "ms\n";


	return 0;
}
