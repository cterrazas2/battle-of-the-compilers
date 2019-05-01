/*
 * author: Christopher Terrazas
 * uni: ct2856
 * binarysearch.cpp: file for utilizing binarysearch on a list.
 * Used following resources:
 *  Tour of C++ - Bjarne Stroustrup
 *  https://en.cppreference.com
 */
#include <iostream>
#include <list>
#include <algorithm>
#include <chrono>

using namespace::std;
using namespace std::chrono;


/*
 * insert - inserts elements into a list.
 * params: list, N elements
 * return: void
*/
template<typename T>
void insert(list<T>& lis, T N)
{
      for (int i=0;i<=N;i++) {
          lis.push_back(i);
      }
    	cerr << lis.size();
}

/*
 * BinarySearch - finds element in list using binary search from <alorithm>
 * params: list, target
 * return: boolean
*/
template<typename T>
bool BinarySearch(list<T>& lis, T target)
{
  return binary_search(lis.begin(),lis.end(),target);
}

int main() {

  list<int> lis;
  int target = -1;
  int MAX = 10000000;
  insert(lis,MAX);
  auto start = system_clock::now();
  auto result = BinarySearch(lis,target);
  auto end = system_clock::now();
  cerr << result << endl;
  auto time_trial = duration_cast<milliseconds>(end-start).count();
  cout << "BinarySearch Time: " << time_trial << "ms\n";

  return 0;
}
