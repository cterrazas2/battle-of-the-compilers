#### File - unordered_set.cpp


#### Function: set_access

```cpp
void set_access(const vector<string>& rands, unordered_set<string>* unordered_set){
```

1) Fills a unordered_set with random elements and then tests deletion and swap.

**Parameters**
- `rands` , the random vector utilized to store random strings.
- `unordered_set`, the pointer to the initialized unordered_set.

**Return Value**

1) `void`, however will output to stderr for measurements.

#### Function: time

```cpp
void time(void (*fn)(const std::vector<string>&, std::unordered_set<string>*), const std::vector<string>& rands, std::unordered_set<string>* unordered_set)
```

1) Times the unordered_set access function.

**Parameters**
- `fn` , the function pointer to set_access.
- `rands` , the random vector utilized to store random strings.
- `unordered_set`, the pointer to the initialized unordered_set.

**Return Value**

1) `void`, however will output to stdout for measurements.

**Example of all functions within unordered_set.cpp:**
```cpp
int main() {
   default_random_engine re(0); 
    uniform_int_distribution<int> dist(0, 100000000);
    int size = 5000;
    std::vector<string> rands(size);
    for (int i=0; i < size; ++i){
        rands.push_back(to_string(dist(re)));
    }
    std::cout << rands[0];
    std::unordered_set<string> unordered_set;
    time(set_access, rands, &unordered_set);
    return 0;
}
```
