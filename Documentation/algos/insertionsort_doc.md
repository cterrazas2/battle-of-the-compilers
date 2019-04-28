#### File - insertionsort.cpp

#### Function: generateRandom

See list.cpp for documentation.

#### Function: insert
```cpp
template<typename T>
void insert(const unordered_set<T> us, vector<T>& vec)
```
1) Inserts elements from a randomly unsorted set in non-decreasing order into a vector.

This function will iterate over an unordered set and place in non-decreasing order into a vector.

**Parameters**
- `us`, the random set to be iterated on.
- `vec`, the vector to be inserted into.

**Return Value**

1) `void`, however will output to stderr for measurements.

**Complexity:** At most `(N)` steps

#### Function: InsertionSort
```cpp
template<typename T>
void InsertionSort(vector<T>& vec)
```
1) Sorts a vector of elements utilizing insertion sort.

This function will sort all elements within a vector and utilizes `auto` to handle multiple types such as integers and strings.

**Parameters**
- `vec`, the vector to sort.

**Return Value**

1) `void`, however will output to stderr for measurements.

**Complexity:** At most `(N^2)` steps

**Example of all functions within insertionsort.cpp (#includes excluded):**
```cpp
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

```
