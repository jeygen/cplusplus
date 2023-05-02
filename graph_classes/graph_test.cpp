#include "graph_classes.hpp"
#include <iostream>

int main() {
    DirectedGraph dg(4);

    dg.add_edge(0, 1);
    dg.add_edge(0, 2);
    dg.add_edge(1, 2);
    dg.add_edge(1, 3);
    dg.add_edge(2, 3);

	dg.print_nodes();
/*
    for (int i = 0; i < dg.num_vertices(); ++i) {
        std::cout << "Node " << i << ": ";
        const std::vector<int>& neighbours = dg.neighbours(i);
        for (int j = 0; j < neighbours.size(); ++j) {
            std::cout << neighbours[j];
            if (j < neighbours.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
*/
	

    return 0;
}

