/* Author: Rabia Akhtar

Partially based on https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

*/

#include<iostream> 
#include <list> 
#include <chrono>
#include <random>

using namespace std; 

class Graph 
{ 
	int num_vertices;
	list<int>* adj_list; 

public: 
	Graph(int num_vertices);
	void addEdge(int v, int w); 
	bool BFS(int start, int end); 
}; 

// Constructor intializes the Graph with the number of vertices.
Graph::Graph(int num_vertices) 
{ 
	this->num_vertices = num_vertices; 
	adj_list = new list<int>[num_vertices]; 
} 

// Adds an edge to the Graph.
void Graph::addEdge(int v, int w) 
{ 
	adj_list[v].push_back(w);
} 

// Breadth First Search Algorithm 
bool Graph::BFS(int start, int end) 
{ 
	bool *visited = new bool[num_vertices]; 
	for(int i = 0; i < num_vertices; i++) 
		visited[i] = false; 

	list<int> queue; 

	// Mark the current node as visited and push it onto the queue
	visited[start] = true; 
	queue.push_back(start); 
	list<int>::iterator it; 

	// Traverse graph and mark adjacent nodes as visited.
	while(!queue.empty()) 
	{ 
		start = queue.front(); 
		if (start == end && end != -1){
			return true; 
		}
		std::cerr << start << endl; 
		queue.pop_front(); 

		for (it = adj_list[start].begin(); it != adj_list[start].end(); it++) 
		{ 
			if (!visited[*it]) 
			{ 
				visited[*it] = true; 
				queue.push_back(*it); 
			} 
		} 
	}
	return true;
} 

int main() 
{ 
	auto start = chrono::high_resolution_clock::now();
	int max_vertices = 3000;
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
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	cout << "Random graph generation took time: " << duration << " milliseconds" << endl;

    start = chrono::high_resolution_clock::now();
    graph.BFS(1, -1);
    end = chrono::high_resolution_clock::now();
	duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	cout << "BFS entire graph traversal took time: " << duration << " milliseconds" << endl;

	start = chrono::high_resolution_clock::now();
    bool value = graph.BFS(0, num_vertices-1);
    end = chrono::high_resolution_clock::now();
	duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	cout << "Breadth First Search took time: " << duration << " milliseconds and found value: " << (value ? "true" : "false") << endl;
	return 0; 
} 