#ifndef GRAPH_CLASSES_HPP
#define GRAPH_CLASSES_HPP

#include <vector>
#include <utility>

// ifndef checks for duplicates
// to use: #include "graph_classes.hpp"

class DirectedGraph {
public:
    DirectedGraph(int n);

    void add_edge(int u, int v);

    const std::vector<int>& neighbours(int u) const;

    int num_vertices() const;

private:
    std::vector<std::vector<int>> adj_list;
};

class UndirectedGraph {
public:
    UndirectedGraph(int n);

    void add_edge(int u, int v);

    const std::vector<int>& neighbours(int u) const;

    int num_vertices() const;

private:
    std::vector<std::vector<int>> adj_list;
};

class WeightedDirectedGraph {
public:
    WeightedDirectedGraph(int n);

    void add_edge(int u, int v, int weight);

    const std::vector<std::pair<int, int>>& neighbours(int u) const;

    int num_vertices() const;

    int get_weight(int u, int v) const;

private:
    std::vector<std::vector<std::pair<int, int>>> adj_list;
};

class WeightedUndirectedGraph {
public:
    WeightedUndirectedGraph(int n);

    void add_edge(int u, int v, int weight);

    const std::vector<std::pair<int, int>>& neighbours(int u) const;

    int num_vertices() const;

    int get_weight(int u, int v) const;

private:
    std::vector<std::vector<std::pair<int, int>>> adj_list;
};

#endif // GRAPH_CLASSES_HPP

