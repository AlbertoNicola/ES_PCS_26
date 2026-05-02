#pragma once
#include <utility>
#include <vector>


template <typename T>
bool is_sorted(const std::vector<T>& vec) 
{
	if (vec.size() <= 1)
	{
		return true;
	}
	else
	{
		for (int i = 0; i<vec.size() - 1; i++)
		{
			if (vec[i]>vec[i+1])
			{
				return false;
			}
		}
		return true;
	}

}

template <typename T>
void bubble_sort(std::vector<T>& vec)
{
	int n = vec.size();
	for (int i =0; i<n-1;i++)
	{
		for (int j =n-1; j>i;j--)
		{
			if (vec[j]<vec[j-1])
			{
				std::swap(vec[j], vec[j-1]);
			}
		}
	}
}

template <typename T>
void insertion_sort(std::vector<T>& vec) 
{
	int n = vec.size();
	for (int j = 1; j < n; j++) 
	{
		T key = vec[j]; 
		int i = j - 1;  
		
		while (i >= 0 && vec[i] > key) 
		{
			vec[i+1] = vec[i]; 
			i = i - 1;         
		}
		
	vec[i+1] = key;
	}
}

template <typename T>
void selection_sort(std::vector<T>& vec) 
{
	int n = vec.size();
	for (int i = 0; i < n - 1; i++) 
	{
		int min = i; 
		for (int j = i + 1; j < n; j++) 
		{
			if (vec[j] < vec[min]) 
			{
				min = j; 
			}
		}
		std::swap(vec[i], vec[min]); 
	}
}

template<typename T>
void merge(std::vector<T>& A, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	
	std::vector<T> L(n1);
	std::vector<T> R(n2);
	
	for (int i = 0; i < n1; i++)
		L[i] = A[p + i];
	for (int j = 0; j < n2; j++)
		R[j] = A[q + 1 + j];
		
		int i = 0, j = 0, k = p;
		
		while (i < n1 && j < n2)
		{
			if (L[i] <= R[j])
			{
				A[k] = L[i];
				
				i++;
			}
			else
			{
				A[k] = R[j];
				j++;
			}
			k++;
		}
		
		while (i < n1)
		{
			A[k] = L[i];
			i++;
			k++;
		}
		
		while (j < n2)
		{
			A[k] = R[j];
			j++;
			k++;
		}
}

template<typename T>
void merge_sort_recursive(std::vector<T>& A, int p, int r)
{
	if (p < r)
	{
		int q = p + (r - p) / 2;
		merge_sort_recursive(A, p, q);
		merge_sort_recursive(A, q + 1, r);
		merge(A, p, q, r);
	}
}

template<typename T>
void merge_sort(std::vector<T>& A)
{
	if (!A.empty())
	{
		merge_sort_recursive(A, 0, A.size() - 1);
	}
}

template<typename T>
int partition(std::vector<T>& A, int p, int r)
{
	T x = A[r];
	int i = p - 1;
	
	for (int j = p; j <= r - 1; j++)
	{
		if (A[j] <= x)
		{
			i++;
			std::swap(A[i], A[j]);
		}
	}
	std::swap(A[i + 1], A[r]);
	return i + 1;
}

template<typename T>
void quick_sort_recursive(std::vector<T>& A, int p, int r)
{
	if (p < r)
	{
		int q = partition(A, p, r);
		quick_sort_recursive(A, p, q - 1);
		quick_sort_recursive(A, q + 1, r);
	}
}

template<typename T>
void quick_sort(std::vector<T>& A)
{
	if (!A.empty())
	{
		quick_sort_recursive(A, 0, A.size() - 1);
	}
}