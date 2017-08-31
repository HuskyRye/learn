#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;
	constexpr Point tl { 100, 100 };
	Simple_window win1 { tl, 600, 400, "Image" };

	Image rita { Point{0, 0}, "rita.jpg" };
	Image path { Point{0, 0}, "rita_path.gif" };
	path.set_mask(Point { 50, 250 }, 600, 400);
	win1.attach(path);
	win1.attach(rita);

	win1.wait_for_button();
}