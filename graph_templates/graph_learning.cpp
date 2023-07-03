// i did this wrong, i should use header for class declarations

#include <vector>
#include <utility> // for std::pair

class DirectedGraph {
public:
	DirectedGraph(int n) : adj_list{n} {} // constructor, w/ member intit 

	void add_edge(int u, int v) {
		// push_back() vector method to add and expand to end of vect
		adj_list[u].push_back(v); 
	}

	// the 1st const, usually paired with &, since & means passing by
	// ref and not value means working on og so don't want to change it.
	// the 2nd const communicates the method is not altering contents.
	// 	allows method to called on const object and helps compiler.
	//  can think read only or getter
	// & because returning c++ reference/alias
	const std::vector<int>& neighbours(int u) const {
		return adj_list[u];
	}

	int num_vertices() const {
		return adj_list.size();
	}

private:
	// vector of vectors with {} acting as 0 intializer i think
	// not strictly needed
	std::vector<std::vector<int>> adj_list {};
};
		

class UndirectedGraph {
public:
	UndirectedGraph(int n) : adj_list{n} {} 

	void add_edge(int u, int v) {
		adj_list[u].push_back(v); 
		adj_list[v].push_back(u); 
	}

	const std::vector<int>& neighbours(int u) const {
		return adj_list[u];
	}

	int num_vertices() const {
		return adj_list.size();
	}

private:
	std::vector<std::vector<int>> adj_list {};
};


class WeightedDirectedGraph {
public:
    WeightedDirectedGraph(int n) : adj_list{n} {}

    void add_edge(int u, int v, int weight) {
        adj_list[u].push_back({v, weight});
    }

    const std::vector<std::pair<int, int>>& neighbours(int u) const {
        return adj_list[u];
    }

    int num_vertices() const {
        return adj_list.size();
    }

	int get_weight(int u, int v) const {
		// should prob use const and & for p, but not fully necessary
        for (auto p : adj_list[u]) {
			// first and second are refering to utility pair (first, sec)
            if (p.first == v) {
                return p.second;
            }
        }
        return -1; // return -1 if edge not found
    }

private:
    std::vector<std::vector<std::pair<int, int>>> adj_list;
};


class WeightedUndirectedGraph {
public:
    WeightedUndirectedGraph(int n) : adj_list{n} {}

    void add_edge(int u, int v, int weight) {
        adj_list[u].push_back({v, weight});
        adj_list[v].push_back({u, weight});
    }

    const std::vector<std::pair<int, int>>& neighbours(int u) const {
        return adj_list[u];
    }

    int num_vertices() const {
        return adj_list.size();
    }

	int get_weight(int u, int v) const {
        for (auto p : adj_list[u]) {
            if (p.first == v) {
                return p.second;
            }
        }
        return -1; 
    }

private:
    std::vector<std::vector<std::pair<int, int>>> adj_list;
};
