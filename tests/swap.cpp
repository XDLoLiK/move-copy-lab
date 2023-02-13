#include "swap.hpp"

#if (TEST_LEVEL == 0)

std::pair<DemoInt, DemoInt> SwapInts(DemoInt int1, DemoInt int2)
{
	Graphviz_StartFunction(__LOCATION__);

	int1 = int1 + int2;
	int2 = -(int2 - int1);
	int1 = int1 - int2;

	Graphviz_EndFunction();

	return {int1, int2};
}

#elif (TEST_LEVEL == 1)

void SwapInts(DemoInt& int1, DemoInt& int2)
{
	Graphviz_StartFunction(__LOCATION__);

	int1 = int1 + int2;
	int2 = -(int2 - int1);
	int1 = int1 - int2;

	Graphviz_EndFunction();
}

#elif (TEST_LEVEL == 2)

void SwapInts(DemoInt& int1, DemoInt& int2)
{
	Graphviz_StartFunction(__LOCATION__);

	int1 += int2;
	int2 -= int1;
	int2 = -int2;
	int1 -= int2;

	Graphviz_EndFunction();
}

#endif
