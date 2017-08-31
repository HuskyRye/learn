#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;
	constexpr Point tl { 100, 100 };
	Simple_window win1 { tl, 600, 400, "Open polyline" };

	Graph_lib::Polygon poly;
	poly.add(Point { 100, 100 });
	poly.add(Point { 150, 200 });
	poly.add(Point { 250, 250 });
	poly.add(Point { 300, 200 });
	poly.set_color(Color::black);
	win1.attach(poly);

	win1.wait_for_button();
}