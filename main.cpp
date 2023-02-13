#include "swap.hpp"

/*
 * move
 * forward
 * show cases where move can't be used (3 examples, 2 counter-examples)
 * show cases where forward can't be used (3 examples, 2 counter-examples)
 */

int main()
{
	Graphviz_SetFile("lab.dot");
	Graphviz_Init();
	Graphviz_StartFunction(__LOCATION__);

	DEMO_INT(test_int_1, 5);
	DEMO_INT(test_int_2, 6);

#if (TEST_LEVEL == 0)
	std::pair<DemoInt, DemoInt> swapped = SwapInts(test_int_1, test_int_2);
#else
	SwapInts(test_int_1, test_int_2);
#endif

	Graphviz_EndFunction();
	Graphviz_Quit();
	return 0;
}
