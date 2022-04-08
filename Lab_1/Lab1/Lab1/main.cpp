#include <iostream>
#include "testing.h";
#include "sorting_algorithms.h";
#include <algorithm>

int main() {
	const int ARRAY_SIZES[]{ 10, 100, 1000, 5000, 10000, 20000, 50000 };

	std::cout << "================================================================\n";
	std::cout << "BUBBLE SORT:\n";
	std::cout << "================================================================\n\n";

	for (auto current_size : ARRAY_SIZES) {
		TestSortingAlgorithm(current_size, &BubbleSort);
	}

	std::cout << "================================================================\n";
	std::cout << "COMB SORT:\n";
	std::cout << "================================================================\n\n";

	for (auto current_size : ARRAY_SIZES) {
		TestSortingAlgorithm(current_size, &CombSort);
	}
	return 0;
}