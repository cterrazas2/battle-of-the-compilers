#include <iostream>
#include <list>
#include <chrono>
#include <random>
#include <unordered_set>
using namespace std;


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
}

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
}

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
    //   int target = listIndex;
       while ( listIndex-- > 0)
           pos++;

    //   cout << "Deleting: list[" << target << "] = " << *pos << "\n";
       lis.erase(pos);
  }

}

template<typename T>
void print(T v)
{
  if (v.size()) {
      cout << "[";
      for (auto n: v) {
            cout << n << "," ;
          }
          cout <<  "]\n";
  } else { cout << "[]\n"; }
}

int main() {

  int MAX = 1000;
  int N = 100; // Default num integers.
  unordered_set<int> rs; // for checking if rand num is in set already, O(1) cost on avg.
  generateRandom(rs,MAX,N);
  list<int> lis;
  //    ==================== Insert Randomly List =====================
  auto begin = std::chrono::high_resolution_clock::now();
  insert(rs,lis);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> time_trial = end-begin;
  cout << "TIME: In Place List Sequence: " << time_trial.count() << " ms\n";
  cout << "List Sequence SIZE: " << lis.size() <<"\n";
  cout << "====================\n";
  cout << "Sorted In Place List Sequence: ";
  print(lis);
  cout << "====================\n";

  //    ==================== Remove Randomly List =====================
  cout << "Deleting random indexes in List...\n";
  print(lis);
  begin = std::chrono::high_resolution_clock::now();
  erase(lis);
  end = std::chrono::high_resolution_clock::now();
  time_trial = end-begin;
  cout << "TIME: Random List Deletion: " << time_trial.count() << " ms\n";
  cout << "List Sequence SIZE: " << lis.size() <<"\n";
  cout << "====================\n";
  cout << "After Random Deletion, List: ";
  print(lis);

	return 0;
}
