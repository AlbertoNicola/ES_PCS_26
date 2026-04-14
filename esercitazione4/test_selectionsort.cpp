#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 
#include "randfiller.h"
#include "sort_algos.hpp"

std::vector<int> random_number(randfiller& rf)
{
	std::vector<int> dim_vec;
	dim_vec.resize(1); 
	rf.fill(dim_vec, 1, 1000); 
	return dim_vec;
}

int main(void)
{
	randfiller rf; 
	for (size_t i=0; i < 100; i++)
	{
		std::vector<int> dim_vec = random_number(rf);
		std::vector<int> vi;
		vi.resize(dim_vec.at(0)); 
		rf.fill(vi, -500, 500);   
		
		selection_sort(vi); // Test specifico
		
		if (!is_sorted(vi))
		{
			std::cout << "Test Fallito: il valore " << i << " non è stato sistemato (SelectionSort). \n";
			return EXIT_FAILURE;
		}
	}
	
	std::vector<std::string> vs = {"mela", "computer", "palla" , "corsa", "noia", "luce"};
	vs.push_back("salvezza");
	
	selection_sort(vs);
	
	if (!is_sorted(vs))
	{
		std::cout << "Test Fallito: la stringa non è stata sistemata \n";
		return EXIT_FAILURE;
	}
	
	std::cout << "SelectionSort: Test andato a buon fino \n";
	return EXIT_SUCCESS;
}