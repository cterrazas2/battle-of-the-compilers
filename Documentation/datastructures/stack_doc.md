#### File - stack.cpp


#### Function: generateRandom

```cpp
template<typename T>
void generateRandom(unordered_set<T>& rs, const int MAX, const int N)
```

1) Generates a unique set of random integers.

This function will utilize an unordered set for generating
unique random integers. The find operation will be useful due to
constant time on average.

**Parameters**
- `rs` , the random set utilized to store random integers.
- `MAX` bound, the value set for the highest range for the distribution.
- `N` bound, the value set for the number of random integers to generate.

**Return Value**

1) `void`, however will output to stderr for measurements.

**Complexity:** At most `(N*MAX)` steps

#### Function: insert
```cpp
template<typename T>
void insert(const unordered_set<T> us, stack<T>& st)
```
1) Inserts elements from a randomly unsorted set in non-decreasing order into a stack.

This function will iterate over an unordered set and sorting in place in non-decreasing order into a stack.

**Parameters**
- `us`, the random set iterated on.
- `st`, the stack to be inserted into.

**Return Value**

1) `void`, however will output to stderr for measurements.

**Complexity:** At most `(N*M)` steps

#### Function: erase
```cpp
template<typename T>
void erase(stack<T>& st)
```
1) Erases all elements within a stack.

**Parameters**
- `st`, the stack to be used to delete elements until empty.

**Return Value**

1) `void`, however will output to stderr for measurements.

**Complexity:** At most `(N)` steps

#### Function: find

```cpp
template<typename T>
bool find(stack<T>& stk, T target)
```

1) Finds a target within a sorted non-decreasing stack utilizing a second temporary stack.

This function will return a boolean based on whether or not target is within stack. Note that the original stack size will remain unchanged.

**Parameters**
- `stk`, the stack to search in.
- `target`, the desired element.

**Return Value**

1) `bool`, `1` if element is in queue `0` otherwise.

**Complexity:** At most `(N)` steps

**Example of all functions within stack.cpp:**
```cpp
int main() {

    int MAX = 100000000;
    int N = 10000; // Default num integers.
    unordered_set<int> rs;
    generateRandom(rs,MAX,N);
    stack<int> stk;

    auto start = system_clock::now();
    insert(rs,stk);
    find(stk,*rs.begin());
    erase(stk);
    auto end = system_clock::now();
    auto time_trial = duration_cast<milliseconds>(end-start).count();
    cerr << "Stack Time: " << time_trial << "ms\n";

    return 0;
}
```
