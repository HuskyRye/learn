#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;
	constexpr Point tl { 100, 100 };
	Simple_window win1 { tl, 600, 400, "Ellipse" };

	Graph_lib::Ellipse e1 { Point { 200, 200 }, 50, 50 };
	Graph_lib::Ellipse e2 { Point { 200, 200 }, 100, 50 };
	Graph_lib::Ellipse e3 { Point { 200, 200 }, 100, 150 };
	e1.set_color(Color::black);
	e2.set_color(Color::black);
	e3.set_color(Color::black);
	win1.attach(e1);
	win1.attach(e2);
	win1.attach(e3);
	win1.wait_for_button();
}