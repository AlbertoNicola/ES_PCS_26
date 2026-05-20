#pragma once

#include <iostream>
#include <algorithm>  
#include <set>
#include <map>
#include <stdexcept>   // per out_of_range

class unidirected_edge
{
	int nodo_a, nodo_b;

public: 
	unidirected_edge(int u, int v)
{
	nodo_a = std::min(u, v);
	nodo_b = std::max(u, v);
}
	
	int from() const { return nodo_a; }
	int to() const { return nodo_b; }
	
	bool operator<(const unidirected_edge& other) const
	{
		if (nodo_a != other.nodo_a)
		{ 
			return nodo_a < other.nodo_a;
		}
		return nodo_b < other.nodo_b;  
	}	
	
	bool operator==(const unidirected_edge& other) const
	{
		return nodo_a == other.nodo_a && nodo_b == other.nodo_b; 
	}
	
	friend std::ostream& operator<<(std::ostream& os, const unidirected_edge& edge)
	{   
		os << "(" << edge.nodo_a << ")--(" << edge.nodo_b << ")";
		return os;
	}
};


class unidirected_graph
{
	std::map<int, std::set<int>> vicini;
	std::set<unidirected_edge> edges;
	
public:
	unidirected_graph() = default; 
	unidirected_graph(const unidirected_graph& other) = default;
 
	std::set<int> neighbours(int nodo) const {
		if (vicini.count(nodo)) { 
			return vicini.at(nodo); 
		}
		return {}; 
	}
	
	void add_edges(int u, int v)
	{
		unidirected_edge new_edge(u, v); 
		
		if (edges.find(new_edge) == edges.end())
		{
			edges.insert(new_edge);  
			vicini[u].insert(v);
			vicini[v].insert(u);
		}
	}
	
	std::set<unidirected_edge> all_edges() const
	{
		return edges;
	}
	
	std::set<int> all_nodes() const
	{
		std::set<int> nodes; 
		for (const auto& element : vicini)
		{  
			nodes.insert(element.first); 
		}
		return nodes;
	}
	
	int edge_number(const unidirected_edge& edge) const
	{
		int i = 0;
		for (const auto& e : edges)
		{
			if (e == edge) return i;
			i++;
		}
		return -1; 
	}
	
	unidirected_edge edge_at(size_t indice) const
	{
		if (indice >= edges.size())
		{
			throw std::out_of_range("Indice non valido!");
		}
		auto it = edges.begin();
		std::advance(it, indice);
		return *it;
	}
	
	unidirected_graph operator-(const unidirected_graph& other) const
	{
		unidirected_graph risultato;  
		auto other_edges = other.all_edges();
		
		for (const auto& edge : edges)
		{
			if (other_edges.find(edge) == other_edges.end())
			{
				risultato.add_edges(edge.from(), edge.to());
			}
		}
		return risultato;
	}
};