#include <iostream>
#include <algorithm> 
#include <cmath>

int main()
{
	static const int N = 10;
	double arr[N] = {2.5, 4.1, 7.3, 1.2, 9.8, 5.5, 3.0, 6.2, 8.4, 0.9};
	
	double min_val = arr[0];
	double max_val = arr[0];
	double somma = 0.0;
	
	for(int i = 0; i < N; ++i)
	{
		min_val = std::min(min_val, arr[i]);
		max_val = std::max(max_val, arr[i]);
		somma += arr[i];
	}
	
	double media = somma / N;
	
	double somma_scarti_quadrati = 0.0;
	for(int i = 0; i < N; ++i)
	{
		double scarto = arr[i] - media;
		somma_scarti_quadrati += scarto * scarto;
	}
	double deviazione_standard = std::sqrt(somma_scarti_quadrati / N);
	
	std::cout << "Minimo: " << min_val << "\n";
	std::cout << "Massimo: " << max_val << "\n";
	std::cout << "Media: " << media << "\n";
	std::cout << "Deviazione standard: " << deviazione_standard << "\n";
	
	return 0;
}