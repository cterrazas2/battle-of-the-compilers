#include <iostream>
#include <stack>
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
}

template<typename T>
void insert(const unordered_set<T> us, stack<T>& st)
{
        stack<T> tmp;
        for (auto i = us.begin(); i!=us.end(); i++) {

                if (i == us.begin()) { // push first element
                        st.push(*us.begin());
                } else {

                        if (*i > st.top() )  {
                                st.push(*i);
                        } else {

                                while ( !st.empty() ) { // shift all the way left

                                      if (*i < st.top() )
                                        tmp.push( st.top() );
                                      else
                                        break;

                                      st.pop();
                                }

                                st.push(*i);

                                while ( !tmp.empty() ) {
                                        st.push( tmp.top() );
                                        tmp.pop();
                                }

                        }

                }
        }

}

template<typename T>
void erase(stack<T>& st)
{
  while (!st.empty())
      st.pop();
}

template<typename T>
bool find(stack<T>& stk, T target)
{
  stack<T> tmp;
  bool result;

  while (!stk.empty()) {
    if (target == stk.top()) {
          result = true;
          break;
    } else {
      tmp.push( stk.top() );
    }
    stk.pop();
  }

  while (!tmp.empty()) {
     stk.push( tmp.top() );
     tmp.pop();
  }
  return result;
}

int main() {

        int MAX = 100000;
        int N = 5000; // Default num integers.
        unordered_set<int> rs;
        generateRandom(rs,MAX,N);
        stack<int> stk;

        // Discard first trial
        insert(rs,stk);
        find(stk,*rs.begin());
        erase(stk);

        //    ==================== Insert Randomly Stack =====================
        insert(rs,stk);
        find(stk,*rs.begin());
        erase(stk);

        return 0;
}
