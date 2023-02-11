#include "demo_int.hpp"
#include "graphviz.hpp"

void BubbleSort(DemoInt* array, int left, int cur_pos = 0);

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

void SwapInts(DemoInt& int1, DemoInt& int2);

void SwapInts(DemoInt& int1, DemoInt& int2)
{
	Graphviz_StartFunction(__LOCATION__);

	int1 += int2;
	int2 -= int1;
	int2 = -int2;
	int1 -= int2;

	Graphviz_EndFunction();
}

int main()
{
	Graphviz_SetFile("lab.dot");
	Graphviz_Init();

	Graphviz_StartFunction(__LOCATION__);

	DEMO_INT(test_int_1, 5);
	DEMO_INT(test_int_2, 6);
	SwapInts(test_int_1, test_int_2);

	Graphviz_EndFunction();

	Graphviz_Quit();

	return 0;
}
