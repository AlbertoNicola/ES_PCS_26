#include <iostream>
#include <cassert>
#include "graph.hpp"

int main()
{
	std::cout << " Inizio Test \n";
	
	unidirected_edge<int> e1(5, 2);
	assert(e1.from() == 2 && e1.to() == 5);
	std::cout << "OK, test superato. Arco creato: " << e1 << "\n";
	
	unidirected_graph<char> g1;
	
	g1.add_edge('A', 'B');
	g1.add_edge('B', 'C');
	g1.add_edge('C', 'A');
	g1.add_edge('C', 'D');
	
	assert(g1.all_nodes().size() == 4);
	assert(g1.all_edges().size() == 4);
	std::cout << "OK, test all_nodes() e all_edges() superaton \n";
	
	std::set<char> vicini_di_c = g1.neighbours('C');
	assert(vicini_di_c.size() == 3);
	std::cout << "OK, test neighbours() superato \n";
	
	unidirected_edge<char> test_edge('A', 'C');
	int indice = g1.edge_number(test_edge);
	assert(indice != -1);
	unidirected_edge<char> retrieved_edge = g1.edge_at(indice);
	assert(retrieved_edge == test_edge);
	std::cout << "OK, test edge_number() e edge_at() superato \n";
	
	unidirected_graph<char> g2(g1);
	assert(g2.all_edges().size() == 4);
	std::cout << "OK, test costruttore di copia superato \n";
	
	unidirected_graph<char> g3;
	g3.add_edge('A', 'B');
	g3.add_edge('B', 'C');
	
	unidirected_graph<char> diff = g1 - g3;
	assert(diff.all_edges().size() == 2);
	std::cout << "OK, test differenza grafi (G - G') superato \n";
	
	std::cout << " Test superati \n";
	return 0;
}