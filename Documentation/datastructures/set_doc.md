#### File - set.cpp


#### Function: set_access

```cpp
void set_access(const vector<string>& rands, set<string>* set){
```

1) Fills a set with random elements and then tests deletion and swap.

**Parameters**
- `rands` , the random vector utilized to store random strings.
- `set`, the pointer to the initialized set.

**Return Value**

1) `void`, however will output to stderr for measurements.

#### Function: time

```cpp
void time(void (*fn)(const std::vector<string>&, std::set<string>*), const std::vector<string>& rands, std::set<string>* set)
```

1) Times the set access function.

**Parameters**
- `fn` , the function pointer to set_access.
- `rands` , the random vector utilized to store random strings.
- `set`, the pointer to the initialized set.

**Return Value**

1) `void`, however will output to stdout for measurements.

**Example of all functions within set.cpp:**
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
    std::set<string> set;
    time(set_access, rands, &set);
    return 0;
}
```
