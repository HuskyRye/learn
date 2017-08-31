#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;
	constexpr Point tl { 100, 100 };
	Simple_window win1 { tl, 600, 400, "Circles" };

	Circle c1 { Point{100, 200}, 50 };
	Circle c2 { Point { 150, 200 }, 100 };
	Circle c3 { Point { 200, 200 }, 150 };
	c1.set_color(Color::black);
	c2.set_color(Color::black);
	c3.set_color(Color::black);
	win1.attach(c1);
	win1.attach(c2);
	win1.attach(c3);

	win1.wait_for_button();
}