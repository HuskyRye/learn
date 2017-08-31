#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

int main()
{
	using namespace Graph_lib;
	constexpr Point tl { 100, 100 };
	Simple_window win1 { tl, 600, 400, "Open polyline" };

	/*
	Open_polyline opl;
	opl.add(Point { 100, 100 });
	opl.add(Point { 150, 200 });
	opl.add(Point { 250, 250 });
	opl.add(Point { 300, 200 });
	*/
	Open_polyline opl = {
		Point{100, 100}, Point {150, 200}, Point {250, 250}, Point {300, 200}
	};

	opl.set_color(Color::black);
	win1.attach(opl);

	Closed_polyline cpl = {
		{ 200, 200 }, { 250, 300 }, { 350, 350 }, { 400, 300 }
	};
	// cpl.add(Point { 200, 200 });
	// cpl.add(Point { 250, 300 });
	// cpl.add(Point { 350, 350 });
	// cpl.add(Point { 400, 300 });
	cpl.set_color(Color::black);
	win1.attach(cpl);

	win1.wait_for_button();
}