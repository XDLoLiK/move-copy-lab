#ifndef SWAP_HPP
#define SWAP_HPP

#include "demo_int.hpp"
#include "graphviz.hpp"	

#define TEST_LEVEL 2

#if (TEST_LEVEL == 0)
	std::pair<DemoInt, DemoInt> SwapInts(DemoInt int1, DemoInt int2);
#elif (TEST_LEVEL == 1 || TEST_LEVEL == 2)
	void SwapInts(DemoInt& int1, DemoInt& int2);
#endif

#endif // SWAP_HPP
