/*
 * author: Christopher Terrazas
 * uni: ct2856
 * queue.cpp: file for insert, access and erase for queue data structure.
 * Used following resources:
 *  Tour of C++ - Bjarne Stroustrup
 *  https://en.cppreference.com
 */
#include <iostream>
#include <queue>
#include <random>
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

        for (int i=0; i<N; i++) {
                rando = ud(dr);
                auto f = rs.find(rando);

                if (f != rs.end()) { // found a duplicate
                        int tmp = rando;

                        for (int i = 0; i<MAX; i++) {
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
 * insert - inserts elements in non-decreasing order into a queue.
 * params: unordered set, queue
 * return: void
*/
template<typename T>
void insert(const unordered_set<T> us, queue<T>& q)
{
        queue<T> grtr;
        queue<T> smlr;

        for (auto i = us.begin(); i!=us.end(); i++) {

                if (i == us.begin()) { // push first element
                        q.push(*us.begin());
                } else {

                        if (*i > q.back() )  {
                                q.push(*i);
                        } else {

                                while ( !q.empty() ) {

                                      if ( *i < q.front() )
                                        grtr.push( q.front() );
                                      else
                                        smlr.push( q.front() );

                                      q.pop();

                                }

                                while ( !smlr.empty() ) {
                                        q.push( smlr.front() );
                                        smlr.pop();
                                }

                                q.push(*i);

                                while ( !grtr.empty() ) {
                                        q.push( grtr.front() );
                                        grtr.pop();
                                }

                        }

                }
        }
          	cerr << q.size();

}

/*
 * erase - Erases all elements in a queue.
 * params: queue
 * return: void
*/
template<typename T>
void erase(queue<T>& q)
{
  while (!q.empty())
      q.pop();

  cerr << q.size();
}

/*
 * find - Finds an element in a sorted queue.
 * params: queue, target
 * return: bool for if element is in sorted queue.
*/
template<typename T>
bool find(queue<T>& q, T target)
{
  queue<T> tmp;
  bool result;

  while (!q.empty()) {
    if (target == q.front() || target == q.back()) {
          result = true;
          break;
    } else {
      tmp.push( q.front() );
    }
    q.pop();
  }

  while (!tmp.empty()) {
     q.push( tmp.front() );
     tmp.pop();
  }
  return result;
}

int main() {

        int MAX = 100000000;
        int N = 5000; // Default num integers.
        unordered_set<int> rs;
        generateRandom(rs,MAX,N);
        queue<int> q;

        // Cold Cache
        auto start = system_clock::now();
        insert(rs,q);
        find(q,*rs.begin());
        erase(q);
        auto end = system_clock::now();
        auto time_trial = duration_cast<milliseconds>(end-start).count();
        cout << "Cold Cache Time: " << time_trial << "ms\n";

        // Warm Cache
        start = system_clock::now();
        insert(rs,q);
        find(q,*rs.begin());
        erase(q);
        end = system_clock::now();
        time_trial = duration_cast<milliseconds>(end-start).count();
        cout << "Warm Cache Time: " << time_trial << "ms\n";

        return 0;
}
