#include "My_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;
	Lines_window win { Point{100, 100}, 600, 400, "Lines_window" };
	return gui_main();
}