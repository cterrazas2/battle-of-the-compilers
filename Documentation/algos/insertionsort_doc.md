#### File - insertionsort.cpp

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
void insert(const unordered_set<T> us, vector<T>& vec)
```
1) Inserts elements from a randomly unsorted set into a vector.


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
