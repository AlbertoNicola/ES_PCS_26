#pragma once

#include "graph.hpp"
#include "methods.hpp"

#include <queue>
#include <vector>
#include <map>
#include <limits>


// implemento l’algoritmo di Dijkstra utilizzando la struttura dati grafo dell’esercitazione precedente:
std::map<int, int> dijkstra(const unidirected_graph& G, int sorgente)
{
	std::map<int, int> distanze;
	for (int nodo : G.all_nodes())
	{
		distanze[nodo] = std::numeric_limits<int>::max();
	}
	
	distanze[sorgente] = 0;

	using NodoDist = std::pair<int, int>;
	
	std::priority_queue<NodoDist, std::vector<NodoDist>, std::greater<NodoDist>> pq;
	pq.push({0, sorgente});
	
	
	while (!pq.empty())
	{
		int d = pq.top().first;
		int u = pq.top().second;    
		pq.pop();
		
		if (d > distanze[u]) continue;
		
		for (int v : G.neighbours(u))
		{
			
			int weight = 1; 
			
			if (distanze[u] + weight < distanze[v])
			{
				distanze[v] = distanze[u] + weight;
				pq.push({distanze[v], v});
			}
		}
	}
	
	return distanze;
}