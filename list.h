#include <iostream>
#include <list>
#include <chrono>
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
