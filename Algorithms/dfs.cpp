/* Author: Rabia Akhtar

*/

#include<iostream> 
#include <list> 
#include <chrono>
#include <vector>
#include <random>

using namespace std; 

class Graph 
{ 
	int num_vertices;
	list<int>* adj_list; 

public: 
	Graph(int num_vertices);
	void addEdge(int v, int w); 
	void DFS(int start); 
	void DFSHelper(int start, std::vector<bool>* visited);
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

void Graph::DFSHelper(int start, std::vector<bool>* visited) 
{ 
	(*visited)[start] = true; 
	std::cerr << start << endl; 
	list<int>::iterator it; 
	for (it = adj_list[start].begin(); it != adj_list[start].end(); it++) 
		if (!(*visited)[*it]) 
			DFSHelper(*it, visited); 
} 

// DFS traversal of the vertices.
void Graph::DFS(int start) 
{ 
	// Mark all the vertices as not visited 
	std::vector<bool> visited(num_vertices); 
	for (int i = 0; i < num_vertices; i++){
		visited[i] = false; 
	}
	// recurse
	DFSHelper(start, &visited); 
} 

int main() 
{ 
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

    auto start = chrono::high_resolution_clock::now();
    graph.DFS(0);
    auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	cout << "DFS entire graph traversal took time: " << duration << " milliseconds" << endl;

	return 0; 
} 