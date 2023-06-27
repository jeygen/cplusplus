// dfs

vector<vector<int>> adj;  // adjacency list representation
vector<bool> visited;
void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
}

// bfs

vector<vector<int>> adj;  // adjacency list representation
vector<bool> visited;
void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!visited[u]) {
                q.push(u);
                visited[u] = true;
            }
        }
    }
}

// bfs alt 

#include <iostream>
#include <queue>
#include <vector>

void bfs(std::vector<std::vector<int>>& matrix, int start) {
    int n = matrix.size();
	// initialize vector to track visit status, all to false initially
    std::vector<bool> visited(n, false);
	// bfs leverages queues
    std::queue<int> q;

	// after visited add to queue general app
	// add start to get it going
    visited[start] = true;
    q.push(start);

	// while loop to add the remaining
	// run until queue is empty
    while (!q.empty()) {
		// save the current node then pop it
        int current = q.front();
        q.pop();

        std::cout << current << " ";

		// itereate through size of matrix
        for (int i = 0; i < n; ++i) {
			// 1 means the nodes are connected
			// if connected and not visisted add to queue
            if (matrix[current][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

// bellman ford

#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b, weight;
};

void BellmanFord(int V, vector<Edge>& edges, int src) {
    // Initialize distance from src to all other vertices as INFINITE
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges |V| - 1 times to get shortest path
    for (int i = 1; i <= V - 1; i++) {
        for (Edge e : edges) {
            int u = e.a;
            int v = e.b;
            int weight = e.weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Check for negative-weight cycles.
    for (Edge e : edges) {
        int u = e.a;
        int v = e.b;
        int weight = e.weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; ++i)
        cout << i << "\t\t" << dist[i] << endl;
}

// union find

vector<int> parent;
vector<int> rank;

void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);  // path compression
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

 
