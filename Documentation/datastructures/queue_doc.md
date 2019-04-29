#### File - queue.cpp



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
void insert(const unordered_set<T> us, queue<T>& q)
```
1) Inserts elements from a randomly unsorted set in non-decreasing order into a queue.

This function will iterate over an unordered set and sorting in place in non-decreasing order into a queue.

**Parameters**
- `us`, the random set iterated on.
- `q`, the queue to be inserted into.

**Return Value**

1) `void`, however will output to stderr for measurements.

**Complexity:** At most `(N*M)` steps

#### Function: erase
```cpp
template<typename T>
void erase(queue<T>& q)
```
1) Erases all elements within a queue.

**Parameters**
- `q`, the queue used to delete elements until empty.

**Return Value**

1) `void`, however will output to stderr for measurements.

**Complexity:** At most `(N)` steps

#### Function: find

```cpp
template<typename T>
bool find(queue<T>& q, T target)
```

1)  Finds a target within a sorted non-decreasing queue utilizing a second temporary queue.

This function will return a boolean based on whether or not target is within queue. Note that the original queue size will remain unchanged.

**Parameters**
- `q`, the queue to search in.
- `target`, the desired element.

**Return Value**

1) `bool`, `1` if element is in queue `0` otherwise.

**Complexity:** At most `(N)` steps

**Example of all functions within queue.cpp (#includes excluded):**
```cpp
int main() {

    int MAX = 100000000;
    int N = 5000; // Default num integers.
    unordered_set<int> rs;
    generateRandom(rs,MAX,N);
    queue<int> q;

    auto start = system_clock::now();
    insert(rs,q);
    find(q,*rs.begin());
    erase(q);
    auto end = system_clock::now();
    auto time_trial = duration_cast<milliseconds>(end-start).count();
    cerr << "Queue Time: " << time_trial << "ms\n";

    return 0;
}
```
