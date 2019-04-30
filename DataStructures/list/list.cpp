/*
 * author: Christopher Terrazas
 * uni: ct2856
 * list.cpp: file for insert, access and erase for list data structure.
 * Used following resources:
 *  Tour of C++ - Bjarne Stroustrup
 *  https://en.cppreference.com
 */

#include <iostream>
#include <list>
#include <random>
#include <algorithm>
#include <unordered_set>
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
 * insert - inserts elements in non-decreasing order into a list.
 * params: unordered set, list
 * return: void
*/
template<typename T>
void insert(const unordered_set<T> us, list<T>& lis)
{
  for (auto i = us.begin();i!=us.end();i++) {

        if (i == us.begin()) { // push first element
            lis.push_back(*us.begin());
        } else {

          auto l = lis.begin();
          int count = 0;

          for (;l!=lis.end();l++) {
                if (*i < *l)
                  break;

                count++;
          }
          int offset = count > 0 ? count : 0;

          auto pos = lis.begin();

          while ( offset-- > 0)
              pos++;

          lis.insert(pos,*i);

          count = 0;
        }

  }
    	cerr << lis.size();
}


/*
 * erase - Erases all elements in a list.
 * params: list
 * return: void
*/
template<typename T>
void erase(list<T>& lis)
{
  random_device rd;
  default_random_engine dr(rd());
  int size = lis.size()-1;
  int shrinking = size;
  int listIndex = 0;
  while (size-- >= 0) {
       uniform_int_distribution<int> aa(0,shrinking--);
       listIndex = aa(dr);
       auto pos = lis.begin();

       while ( listIndex-- > 0)
           pos++;

       lis.erase(pos);
  }

  cerr << lis.size();

}


/*
 * find - Finds an element in a sorted list.
 * params: list, target
 * return: bool for if element is in sorted list.
*/
template<typename T>
bool find(list<T>& lis, T target)
{
  return std::binary_search(lis.begin(),lis.end(),target);
}

int main() {
  int MAX = 1000000;
  int N = 10000; // Default num integers.
  unordered_set<int> rs;
  generateRandom(rs,MAX,N);
  list<int> lis;

  // Cold Cache
  auto start = system_clock::now();
  insert(rs,lis);
  find(lis.begin(),lis.end(),*rs.begin());
  erase(lis);
  auto end = system_clock::now();
  auto time_trial = duration_cast<milliseconds>(end-start).count();
  cout << "Cold Cache Time: " << time_trial << "ms\n";


   // Warm Cache
  start = system_clock::now();
  insert(rs,lis);
  find(lis.begin(),lis.end(),*rs.begin());
  erase(lis);
  end = system_clock::now();
  time_trial = duration_cast<milliseconds>(end-start).count();
  cout << "Warm Cache Time: " << time_trial << "ms\n";

	return 0;
}
