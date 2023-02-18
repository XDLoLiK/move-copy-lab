#include "move_semantics_test.hpp"

#if (TEST_LEVEL == 0)

static std::pair<DemoInt, DemoInt> SwapInts(DemoInt int1, DemoInt int2)
{
	Graphviz_StartFunction(__LOCATION__);

	int1 = int1 + int2;
	int2 = -(int2 - int1);
	int1 = int1 - int2;

	Graphviz_EndFunction();

	return {int1, int2};
}

#elif (TEST_LEVEL == 1)

static void SwapInts(DemoInt& int1, DemoInt& int2)
{
	Graphviz_StartFunction(__LOCATION__);

	int1 = int1 + int2;
	int2 = -(int2 - int1);
	int1 = int1 - int2;

	Graphviz_EndFunction();
}

#elif (TEST_LEVEL == 2)

static void SwapInts(DemoInt& int1, DemoInt& int2)
{
	Graphviz_StartFunction(__LOCATION__);

	int1 += int2;
	int2 -= int1;
	int2 = -int2;
	int1 -= int2;

	Graphviz_EndFunction();
}

void MoveSemanticsTest() {
	DEMO_INT(test_int_1, 5);
	DEMO_INT(test_int_2, 6);

#if (TEST_LEVEL == 0)
	std::pair<DemoInt, DemoInt> swapped = SwapInts(test_int_1, test_int_2);
#else
	SwapInts(test_int_1, test_int_2);
#endif
}

#endif
