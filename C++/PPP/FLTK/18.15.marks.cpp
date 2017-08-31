#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;
	constexpr Point tl { 100, 100 };
	Simple_window win1 { tl, 600, 400, "Marks" };

	Marks pp { "x" };
	pp.add(Point { 100, 100 });
	pp.add(Point { 150, 200 });
	pp.add(Point { 250, 250 });
	pp.add(Point { 300, 200 });
	win1.attach(pp);

	win1.wait_for_button();
}