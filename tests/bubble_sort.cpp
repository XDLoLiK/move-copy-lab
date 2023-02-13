#include "bubble_sort.hpp"

void BubbleSort(DemoInt* array, int left, int cur_pos)
{
	if (left == 1) {
		return;
	}

	if (cur_pos == left - 1) {
		BubbleSort(array, left - 1, 0);
		return;
	}

	if (array[cur_pos] > array[cur_pos + 1]) {
		DemoInt temp = array[cur_pos];
		array[cur_pos] = array[cur_pos + 1];
		array[cur_pos + 1] = temp;
	}

	BubbleSort(array, left, cur_pos + 1);
}
