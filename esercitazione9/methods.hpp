#pragma once

#include <queue> 
#include <stack>  


template <typename T>
class fifo
{
	std::queue<T> q;
public:
fifo() = default;
	  
	void put(const T& element)
	{
		q.push(element); 
	}
	
	T get() {
		T element = q.front();  
		q.pop();
		return element;
	}

	bool empty() const {
		return q.empty();
	}
};


template <typename T>
class lifo {
	std::stack<T> s;
public: 
	lifo() = default;
	
	void put(const T& element)
	{
		s.push(element);
	}
	
	T get()
	{
		T element = s.top();
		s.pop();
		return element;
	}
	
	bool empty() const
	{
		return s.empty();
	}
};