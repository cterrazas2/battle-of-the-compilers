#### File - threading.cpp

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

#### Function: print
```cpp
template<typename T>
void print(T v)
```
1) Prints all elements from a container.


**Parameters**
- `v`, the container to print.

**Return Value**

1) `void`, however will output to stderr for measurements.

**Complexity:** At most `(N)` steps

**Example of all functions within threading.cpp (#includes excluded):**
```cpp
int main() {
  int MAX = 1000000;
  int N = 100000; // Default num integers.
  unordered_set<int> rs;
  vector<int> vec;

  std::thread t1(generateRandom<int>, std::ref(rs), std::ref(MAX), std::ref(N) );
  t1.join();

  std::thread t2(insert<int>, std::ref(rs), std::ref(vec) );
  t2.join();

  std::thread t3(InsertionSort<int>, std::ref(vec) );
  t3.join();

  print(vec);

  std::thread t4(erase<int>, std::ref(vec) );
  t4.join();


	return 0;
}
```
