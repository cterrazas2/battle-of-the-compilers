#### File - vector.cpp


#### Function: testVec

```cpp
void testVec(int* a, int* x, int n)
```

1) Tests multiple insertions and deletions in a vector.

**Parameters**
- `a` , array of random integers.
- `x` , pointer to array of random indices to remove
- `n` bound, the size of the vector .

**Return Value**

1) `void`, however will output to stderr for measurements.

**Example of all functions within vector.cpp:**

```cpp
int main() {
    for (int seed=0; seed<2; seed++) {
        default_random_engine re(seed);
        uniform_real_distribution<double> dist(0.0, 100000000); 

    int a[10000];
    for (int i = 0; i < 10000; i++) {
      a[i] = dist(re);
    }
    int x[10000];
        for (int i=0; i<10000; i++) {
            uniform_real_distribution<double> dist2(0,10000-i);
            x[i] = dist2(re);
        }
        testVec(a,x,10000);
    }

	return 0;
}
```
