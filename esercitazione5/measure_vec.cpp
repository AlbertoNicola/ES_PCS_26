#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include "randfiller.h"
#include "timecounter.h"
#include "sort_algos.hpp"

int main()
{
	randfiller rf;
	timecounter tc;
	
	int num_vectors = 100;
	
	std::cout << "Dim\tBubble\t\tSelection\tInsertion\tMerge\t\tQuick\n";
	std::cout << "--------------------------------------------------------------------------------------\n";
	
	for (int size = 5; size <= 100; size += 5)
	{
		std::vector<std::vector<int>> base_vectors(num_vectors, std::vector<int>(size));
		for (int i = 0; i < num_vectors; i++)
		{
			rf.fill(base_vectors[i], -1000, 1000);
		}
		
		double time_bubble, time_selection, time_insertion, time_merge, time_quick;
		
		std::vector<std::vector<int>> vecs = base_vectors;
		tc.tic();
		for (int i = 0; i < num_vectors; i++) bubble_sort(vecs[i]);
		time_bubble = tc.toc() / num_vectors;
		
		// Selection sort
		vecs = base_vectors;
		tc.tic();
		for (int i = 0; i < num_vectors; i++) selection_sort(vecs[i]);
		time_selection = tc.toc() / num_vectors;
		
		// Insertion sort
		vecs = base_vectors;
		tc.tic();
		for (int i = 0; i < num_vectors; i++) insertion_sort(vecs[i]);
		time_insertion = tc.toc() / num_vectors;
		
		// Merge sort
		vecs = base_vectors;
		tc.tic();
		for (int i = 0; i < num_vectors; i++) merge_sort(vecs[i]);
		time_merge = tc.toc() / num_vectors;
		
		// Quick sort
		vecs = base_vectors;
		tc.tic();
		for (int i = 0; i < num_vectors; i++) quick_sort(vecs[i]);
		time_quick = tc.toc() / num_vectors;
		
		// Risultati
		std::cout << size << "\t"
			<< std::scientific << std::setprecision(3)
			<< time_bubble << "\t"
			<< time_selection << "\t"
			<< time_insertion << "\t"
			<< time_merge << "\t"
			<< time_quick << "\n";
		}
		
		return EXIT_SUCCESS;
}