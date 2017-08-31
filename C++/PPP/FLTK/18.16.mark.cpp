#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;
	constexpr Point tl { 100, 100 };
	Simple_window win1 { tl, 600, 400, "Mark" };

	Mark m1 { Point{100, 200}, 'x' };
	Mark m2 { Point{150, 200}, 'y' };
	Mark m3 { Point {200, 200}, 'z' };
	win1.attach(m1);
	win1.attach(m2);
	win1.attach(m3);

	win1.wait_for_button();
}