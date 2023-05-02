#include "graph_classes.hpp"
#include <vector>
#include <utility>

// DirectedGraph
DirectedGraph::DirectedGraph(int n) : adj_list(n) {}

void DirectedGraph::add_edge(int u, int v) {
    adj_list[u].push_back(v);
}

const std::vector<int>& DirectedGraph::neighbours(int u) const {
    return adj_list[u];
}

int DirectedGraph::num_vertices() const {
    return adj_list.size();
}

void DirectedGraph::print_nodes() const {
    for (int i = 0; i < num_vertices(); ++i) {
        std::cout << "Node " << i << ": ";
        const std::vector<int>& neighbours = this->neighbours(i);
        for (int j = 0; j < neighbours.size(); ++j) {
            std::cout << neighbours[j];
            if (j < neighbours.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
}

// UndirectedGraph
UndirectedGraph::UndirectedGraph(int n) : adj_list(n) {}

void UndirectedGraph::add_edge(int u, int v) {
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}

const std::vector<int>& UndirectedGraph::neighbours(int u) const {
    return adj_list[u];
}

int UndirectedGraph::num_vertices() const {
    return adj_list.size();
}

void UndirectedGraph::print_nodes() const {
    for (int i = 0; i < num_vertices(); ++i) {
        std::cout << "Node " << i << ": ";
        const std::vector<int>& neighbours = this->neighbours(i);
        for (int j = 0; j < neighbours.size(); ++j) {
            std::cout << neighbours[j];
            if (j < neighbours.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
}
// WeightedDirectedGraph
WeightedDirectedGraph::WeightedDirectedGraph(int n) : adj_list(n) {}

void WeightedDirectedGraph::add_edge(int u, int v, int weight) {
    adj_list[u].push_back({v, weight});
}

const std::vector<std::pair<int, int>>& WeightedDirectedGraph::neighbours(int u) const {
    return adj_list[u];
}

int WeightedDirectedGraph::num_vertices() const {
    return adj_list.size();
}

int WeightedDirectedGraph::get_weight(int u, int v) const {
    for (auto p : adj_list[u]) {
        if (p.first == v) {
            return p.second;
        }
    }
    return -1;
}

// WeightedUndirectedGraph
WeightedUndirectedGraph::WeightedUndirectedGraph(int n) : adj_list(n) {}

void WeightedUndirectedGraph::add_edge(int u, int v, int weight) {
    adj_list[u].push_back({v, weight});
    adj_list[v].push_back({u, weight});
}

const std::vector<std::pair<int, int>>& WeightedUndirectedGraph::neighbours(int u) const {
    return adj_list[u];
}

int WeightedUndirectedGraph::num_vertices() const {
    return adj_list.size();
}

int WeightedUndirectedGraph::get_weight(int u, int v) const {
    for (auto p : adj_list[u]) {
        if (p.first == v) {
            return p.second;
        }
    }
    return -1;
}

