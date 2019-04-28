#### File - binarysearch.cpp


###### Function: insert
```cpp
template<typename T>
void insert(list<T>& lis, T MAX)
```
1) Inserts `MAX` number elements in non-decreasing order into a list.

**Parameters**
- `lis`, the list to insert elements.
- `MAX`, the maximum amount of elements to insert.

**Return Value**

1) `void`, however will output to stderr for measurements.

**Complexity:** At most `(N)` steps

###### Function: BinarySearch
```cpp
template<typename T>
bool BinarySearch(list<T>& lis, T target)
```
1) Finds a target within a list utilizing binary search.

This function will return a boolean based on whether or not target is within list.

**Parameters**
- `lis`, the list to search in.
- `target`, the desired element.

**Return Value**

1) `bool`, `1` if element is in list `0` otherwise.

**Complexity:** At most `(log N)` steps


**Example of all functions within binarysearch.cpp:**
```cpp
int main() {

  list<int> lis;
  int target = -1;
  int MAX = 10000000;
  insert(lis,MAX);
  auto start = system_clock::now();
  auto result = BinarySearch(lis,target);
  auto end = system_clock::now();
  auto time_trial = duration_cast<milliseconds>(end-start).count();
  cerr << "BinarySearch Time: " << time_trial << "ms\n";
  cerr << target << " in vector? : " << result << "\n";

	return 0;
}

```
