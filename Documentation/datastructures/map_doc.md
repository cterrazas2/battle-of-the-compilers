#### File - map.cpp


#### Function: map_access

```cpp
void map_access(const std::vector<int>& rands, std::map<int, int>* map)
```

1) Fills a map with random elements and then tests deletion and lookup.

**Parameters**
- `rands` , the random vector utilized to store random integers.
- `map`, the pointer to the initialized map.

**Return Value**

1) `void`, however will output to stderr for measurements.

#### Function: time

```cpp
void time(void (*fn)(const std::vector<int>&, std::map<int, int>*), const std::vector<int>& rands, std::map<int, int>*map)
```

1) Times the map access function.

**Parameters**
- `fn` , the function pointer to map_access.
- `rands` , the random vector utilized to store random integers.
- `map`, the pointer to the initialized map.

**Return Value**

1) `void`, however will output to stdout for measurements.

**Example of all functions within map.cpp:**
```cpp
int main() {
    default_random_engine re(0); 
    uniform_int_distribution<int> dist(0, 100000000);
    int size = 10000;
    std::vector<int> rands(size);
    for (int i=0; i < size; ++i){
        rands.push_back(dist(re));
    }
    std::map<int, int> map;
    time(map_access, rands, &map);
    return 0;
}
```
