Rabia Akhtar 
#### File - dfs.cpp

#### Class - Graph


#### Class Helper Functions: 
```cpp
Graph::Graph(int num_vertices);
void Graph::addEdge(int v, int w); 
```
Adjacency list Graph representation where adj_list[v] is the list of vertex v. 

#### Function: DFSHelper
```cpp
void Graph::DFSHelper(int start, std::vector<bool>* visited)
```
1) Helper function marks the current node as visited and recurs for all the vertices adjacent to start

**Parameters**
- `start`, the vertex to begin the search at.
- `visited`, Pointer to vector<bool> of visited nodes. visited[v] is true if vertex v has been visited.

**Return Value**

1) `void`, Function recurses until all vertices have been visited.

**Complexity:** `O(V+E)` where V is number of vertices in the graph and E is number of edges.


#### Function: 
```cpp
void Graph::DFS(int start) 
```
1) Depth First Traversal of a graph. Calls DFSHelper to recurse.

**Parameters**
- `start`, the vertex to begin the search at.

**Return Value**

1) `void`, prints nodes as they are visited. 

**Example of all functions within dfs.cpp:**
```cpp

int main() { 
  	int max_vertices = 3000;
	// Create a random graph.
	default_random_engine re(0); 
	uniform_int_distribution<int> vertices_dist(10, max_vertices);
    
    int num_vertices = vertices_dist(re);
    int max_edges = (num_vertices * (num_vertices - 1)) / 2;

    // Initialize graph.
    Graph graph(num_vertices);

    uniform_int_distribution<int> gen_edges_dist(0, num_vertices - 1);
    for (int i = 0; i < max_edges; i++) {
    	int v = gen_edges_dist(re);
    	int w = gen_edges_dist(re);
    	graph.addEdge(v, w);
    }

    graph.DFS(0);
	return 0; 
} 

``