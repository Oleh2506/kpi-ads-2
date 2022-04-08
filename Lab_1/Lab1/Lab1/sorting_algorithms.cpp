#include <algorithm>
#include "sorting_algorithms.h"

void BubbleSort(int* const arr, const int SIZE) {
	for (size_t i{ 0 }; i < SIZE - 1; ++i) {
		for (size_t j{ 0 }; j < SIZE - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void CombSort(int* const arr, const int SIZE) {
	const float shrink_factor{ 1.2473309 };
	int gap{ SIZE };
	bool swapped{ true };

	while (gap > 1 || swapped) {
		gap = static_cast <int> (static_cast <float> (gap) / shrink_factor);
		gap = gap > 1 ? gap : 1;

		swapped = false;
		for (size_t i{ 0 }; i < SIZE - gap; ++i) {
			if (arr[i] > arr[i + gap]) {
				std::swap(arr[i], arr[i + gap]);
				swapped = true;
			}
		}
	}
}

void BubbleSort(int* const arr, const int SIZE, long long& num_of_swaps, long long& num_of_comparisons) {
	num_of_swaps = 0;
	num_of_comparisons = 0;

	for (size_t i{ 0 }; i < SIZE - 1; ++i) {
		for (size_t j{ 0 }; j < SIZE - 1; ++j) {
			num_of_comparisons++;

			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);

				num_of_swaps++;
			}
		}
	}
}

void CombSort(int* const arr, const int SIZE, long long& num_of_swaps, long long& num_of_comparisons) {
	const float shrink_factor{ 1.2473309 };
	int gap{ SIZE };
	bool swapped{ true };

	num_of_swaps = 0;
	num_of_comparisons = 0;

	while (gap > 1 || swapped) {
		gap = static_cast <int> (static_cast <float> (gap) / shrink_factor);
		gap = gap > 1 ? gap : 1;

		swapped = false;
		for (size_t i{ 0 }; i < SIZE - gap; ++i) {
			num_of_comparisons++;

			if (arr[i] > arr[i + gap]) {
				std::swap(arr[i], arr[i + gap]);
				swapped = true;

				num_of_swaps++;
			}
		}
	}
}