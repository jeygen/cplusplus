// try making directed graph class
// constructor, add_edge(), neighbours(), num_vertices()

#include <vector>

Class DP {
public:
	DP(int n) : adj_list{n} {}

	void add_edge(int u) {
		adj_list(n).push_back(u);
	}

// just do neighbours

	const int num_vertices(int u) const {
		return adj_list(n).size();
	}
private:
	std::vector<std::vector<int>> adj_list;
}	

		


	
