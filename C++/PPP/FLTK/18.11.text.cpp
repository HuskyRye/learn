#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;
	constexpr Point tl { 100, 100 };
	Simple_window win1 { tl, 600, 400, "Text" };

	Text t { Point{200, 200}, "Hello" };
	t.set_color(Color::blue);
	win1.attach(t);

	win1.wait_for_button();
}