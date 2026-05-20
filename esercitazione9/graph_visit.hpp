#pragma once

#include "methods.hpp"   
#include "graph.hpp"     
#include <map>
#include <set>


template <typename Container>
unidirected_graph graph_visit(const unidirected_graph& G, int node, Container& C)
{   
	
	unidirected_graph tree;
	std::set<int> visited; 
	std::map<int, int> padri;
	
	C.put(node);
	padri[node] = node;
	
	while (!C.empty())
	{
		int u = C.get();
		
		if (visited.find(u) == visited.end())
		{
			visited.insert(u);
			
			if (u != node)
			{
				tree.add_edges(padri[u], u);
			}
			
			for (int v : G.neighbours(u))
			{ 
				if (visited.find(v) == visited.end())
				{
					padri[v] = u;
					C.put(v);
				}
			}
		}
	}
	
	return tree;
}