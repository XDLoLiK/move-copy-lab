#include "std_move_test.hpp"

#define USE_MOVE 0
#define USE_FRWD 1

static void CreateLocalCopy(std::vector<int>& vec) {
#if (USE_MOVE == 1)
	std::vector<int> temp = stdlike::move(vec);
#elif (USE_FRWD == 1)
	std::vector<int> temp = stdlike::forward<std::vector<int>&>(vec);
#endif
}

void StdMoveTest() {
	std::vector<int> test_vec(100, 5);
	CreateLocalCopy(test_vec);
	int var = test_vec[50];
	(void)var;
}

