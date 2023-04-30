#include <vector>

class DirectedGraph {
public:
	Graph(int n) : adj_list{n} {} // constructor, with member filler 

	void add_edge(int u, int v) {
		// push_back() vector method to add and expand to end of vect
		adj_list[u].push_back(v); 
	}

	// the 1st const
	// the 2nd const communicates the method is not altering contents.
	// 	allows method to called on const object and helps compiler.
	//  can think read only or getter
	// & because returning reference
	const std::vector<int>& neighbours(int u) const {
		return adj_list[u];
	}

	int num_vertices() const {
		return adj_list.size();
	}

private:
	// vector of vectors with {} acting as 0 intializer i think
	std::vector<std::vector<int>> adj_list {};
};
		
