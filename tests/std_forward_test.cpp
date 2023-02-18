#include "std_forward_test.hpp"

#define USE_MOVE 0
#define USE_FRWD 1

#if (USE_MOVE == 1)

static void Swap(std::vector<int>& first, std::vector<int>& second) {
	std::vector<int> temp = stdlike::move(first);
	first = stdlike::move(second);
	second = stdlike::move(temp);
}

#elif (USE_FRWD == 1)

static void Swap(std::vector<int>& first, std::vector<int>& second) {
	std::vector<int> temp = stdlike::forward<std::vector<int>&>(first);
	first = stdlike::forward<std::vector<int>&>(second);
	second = stdlike::forward<std::vector<int>&>(temp);
}

#endif

static void VectorBubbleSort(std::vector<std::vector<int>>& vec)
{
	for (size_t i = 0; i < vec.size(); i++) {
		for (size_t j = i + 1; j < vec.size(); j++) {
			Swap(vec[i], vec[j]);
		}
	}
}

void StdForwardTest() {
	std::vector<std::vector<int>> test_vec(1000, std::vector<int>(100000, 5));

	/* Measure the time */
	auto start = std::chrono::high_resolution_clock::now();
	
	VectorBubbleSort(test_vec);
	
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << duration.count() << std::endl;
}
