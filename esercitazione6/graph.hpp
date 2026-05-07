#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <set>
#include <map>
#include <stdexcept>

template <typename Node>
class unidirected_edge
{
private:
	Node _from;
	Node _to;

public:
	unidirected_edge(const Node& a, const Node& b)
	{
		if (a < b)
		{
			_from = a;
			_to = b;
		}
		else
		{
			_from = b;
			_to = a;
		}
	}
	
	Node from() const { return _from; }
	Node to() const { return _to; }
	
	bool operator<(const unidirected_edge& other) const
	{
		if (_from != other._from) return _from < other._from;
		return _to < other._to;
	}
	
	bool operator==(const unidirected_edge& other) const
	{
		return _from == other._from && _to == other._to;
	}
	
	friend std::ostream& operator<<(std::ostream& os, const unidirected_edge& e)
	{
		os << "{" << e.from() << ", " << e.to() << "}";
		return os;
	}
};

template <typename Node>
class unidirected_graph {
private:
	std::set<unidirected_edge<Node>> _edges;
	
	std::map<Node, std::set<Node>> _adj;

public:
	unidirected_graph() = default;
	unidirected_graph(const unidirected_graph& other) = default;
	
	void add_edge(const Node& a, const Node& b)
	{
		if (a == b) return;
		unidirected_edge<Node> e(a, b);
		_edges.insert(e);
		_adj[a].insert(b);
		_adj[b].insert(a);
	}
	
	std::set<Node> neighbours(const Node& n) const
	{
		auto it = _adj.find(n);
		if (it != _adj.end())
		{
			return it->second;
		}
		return {};
	}
	
	std::set<unidirected_edge<Node>> all_edges() const
	{
		return _edges;
	}
	
	std::set<Node> all_nodes() const
	{
		std::set<Node> nodes;
		for (const auto& pair : _adj)
		{
			nodes.insert(pair.first);
		}
	return nodes;
	}
	
	int edge_number(const unidirected_edge<Node>& e) const
	{
		int index = 0;
		for (const auto& current_edge : _edges)
		{
			if (current_edge == e) return index;
			index++;
		}
		return -1;
	}
	
	unidirected_edge<Node> edge_at(int number) const
	{
		if (number < 0 || number >= static_cast<int>(_edges.size()))
		{
			throw std::out_of_range("Numero arco fuori limite");
		}
		auto it = _edges.begin();
		std::advance(it, number);
		return *it;
	}
	
	unidirected_graph operator-(const unidirected_graph& other) const
	{
		unidirected_graph result;
		for (const auto& e : _edges)
		{
			if (other._edges.find(e) == other._edges.end())
			{
				result.add_edge(e.from(), e.to());
			}
		}
		return result;
	}
};

#endif