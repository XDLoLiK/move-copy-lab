#include "move_semantics_test.hpp"
#include "std_move_test.hpp"
#include "std_forward_test.hpp"

int main()
{
	Graphviz_SetFile("lab.dot");
	Graphviz_Init();
	Graphviz_StartFunction(__LOCATION__);

	MoveSemanticsTest();
	StdMoveTest();
	StdForwardTest();

	Graphviz_EndFunction();
	Graphviz_Quit();
	return 0;
}
