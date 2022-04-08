#include <algorithm>
#include <iostream>
#include "testing.h"

void FillArray(int* const arr, const int SIZE) {
	for (size_t i{ 0 }; i < SIZE; ++i) {
		arr[i] = i;
	}
}

void PrintArray(const int* const arr, const int SIZE) {
	for (size_t i{ 0 }; i < SIZE; ++i) {
		std::cout << arr[i] << "\t";
	}
}

void ReverseArray(int* const arr, const int SIZE) {
	int left_flag{ 0 }, right_flag{ SIZE - 1 };

	while (left_flag < right_flag) {
		std::swap(arr[left_flag++], arr[right_flag--]);
	}
}

void TestSortingAlgorithm(const int SIZE, void (*SortingAlgorithm)(int* const, const int, long long&, long long&)) {
	int* arr = new int[SIZE] {};
	long long number_of_swaps{}, number_of_comparisons{};
	FillArray(arr, SIZE);
	SortingAlgorithm(arr, SIZE, number_of_swaps, number_of_comparisons);
	std::cout << "================================================================\n";
	std::cout << "Sorted array with " << SIZE << " elements:\n";
	std::cout << "Number of comparisons is: " << number_of_comparisons << "\n";
	std::cout << "Number of swaps is: " << number_of_swaps << "\n\n";

	ReverseArray(arr, SIZE);
	SortingAlgorithm(arr, SIZE, number_of_swaps, number_of_comparisons);
	std::cout << "Reversed array with " << SIZE << " elements:\n";
	std::cout << "Number of comparisons is: " << number_of_comparisons << "\n";
	std::cout << "Number of swaps is: " << number_of_swaps << "\n\n";

	std::random_shuffle(&arr[0], &arr[SIZE]);
	SortingAlgorithm(arr, SIZE, number_of_swaps, number_of_comparisons);
	std::cout << "Array with " << SIZE << " randomly shuffled elements:\n";
	std::cout << "Number of comparisons is: " << number_of_comparisons << "\n";
	std::cout << "Number of swaps is: " << number_of_swaps << "\n";
	std::cout << "================================================================\n\n";

	delete[] arr;
}