#pragma once

#include "methods.hpp"
#include "graph.hpp"
#include "graph_visit.hpp"


void recursive(const unidirected_graph& G, int u, std::set<int>& visited, unidirected_graph& tree) {
	
	visited.insert(u);
	
	for (int v : G.neighbours(u))
	{
		if (visited.find(v) == visited.end())
		{
			tree.add_edges(u, v);
			recursive(G, v, visited, tree);
		}
	}
}


unidirected_graph recursive_dfs(const unidirected_graph& G, int node)
{
	unidirected_graph tree;
	std::set<int> visited;       
	
	recursive(G, node, visited, tree);
	
	return tree;
}