#### File - bfs.cpp

#### Class - Graph



#### Class Helper Functions: 
```cpp
Graph::Graph(int num_vertices);
void Graph::addEdge(int v, int w); 
int Graph::getNumVertices();
```
Adjacency list Graph representation where adj_list[v] is the list of vertex v. 

#### Function: BFS
```cpp
bool Graph::BFS(int start, int end)
```
1) Traverses through entire graph if end = -1 and returns false. 
If end is not -1, returns true if end is found or false if not found.

**Parameters**
- `start`, the vertex to begin the search at.
- `end`, the vertex to end the search at. If -1, BFS traverses entire graph.

**Return Value**

1) `bool`, returns true if end is found, false otherwise.

**Complexity:** `O(V+E)` where V is number of vertices in the graph and E is number of edges.


#### Function: 
```cpp
Graph genRandomGraph()
```
1) Returns a random Graph of 3000 vertices or less.

**Return Value**

1) `Graph`, returns a random graph.

**Example of all functions within bfs.cpp:**
```cpp

int main() 
{ 
  int max_vertices = 30;
  // Create a random graph.
  default_random_engine re(0); 
  uniform_int_distribution<int> vertices_dist(10, max_vertices);
    
    int num_vertices = vertices_dist(re);
    // A dense graph can have N(N-1)/2 edges.
    int max_edges = (num_vertices * (num_vertices - 1)) / 2;

    // Initialize graph.
    Graph graph(num_vertices);

    uniform_int_distribution<int> gen_edges_dist(0, num_vertices - 1);
    for (int i = 0; i < max_edges; i++) {
      int v = gen_edges_dist(re);
      int w = gen_edges_dist(re);
      graph.addEdge(v, w);
    }

    graph.BFS(1, -1);
    bool value = graph.BFS(0, num_vertices-1);
    cout << (value ? "true" : "false") << endl;
  return 0; 
} 

```