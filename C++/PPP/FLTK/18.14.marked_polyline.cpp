#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;
	constexpr Point tl { 100, 100 };
	Simple_window win1 { tl, 600, 400, "Marked polyline" };

	Marked_polyline mpl { "1234" };
	mpl.add(Point { 100, 100 });
	mpl.add(Point { 150, 200 });
	mpl.add(Point { 250, 250 });
	mpl.add(Point { 300, 200 });
	mpl.set_color(Color::black);
	win1.attach(mpl);

	win1.wait_for_button();
}