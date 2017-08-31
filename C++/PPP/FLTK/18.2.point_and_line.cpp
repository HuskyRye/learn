#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;
	constexpr Point x { 100, 100 };
	Simple_window win1 { x, 600, 400, "two lines" };

	Line horizontal { x, Point{200, 100} };
	Line vertical { Point{150, 50}, Point{150, 150} };

	win1.attach(horizontal);
	win1.attach(vertical);

	win1.wait_for_button();
}