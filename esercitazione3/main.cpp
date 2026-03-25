#include <iostream>
#include "rational.hpp"


int main(void)
{
	rational<int> r(3, 6);
	std::cout << "Test semplificazione: " << r << "\n";
	
	rational<int> a(1, 2);
	rational<int> b(1, 3);
	rational<int> c = a + b;
	std::cout << "Somma (1/2 + 1/3): " << c << "\n";
	
	rational<int> inf(5, 0);
	rational<int> zero(0, 1);
	rational<int> nan(0, 0);
	
	std::cout << "Test divisione per zero positiva: " << inf << "\n";
	std::cout << "Test Inf + 1/2: " << (inf + a) << "\n";
	std::cout << "Test NaN: " << nan << "\n";
	
	return 0;
}