#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;
	constexpr Point tl { 100, 100 };
	Simple_window win1 { tl, 600, 400, "rectangles" };

	Graph_lib::Rectangle rect00 { Point{150, 100}, 200, 100 };
	Graph_lib::Rectangle rect11 { Point{50, 50}, Point{250, 150} };
	Graph_lib::Rectangle rect12 { Point { 50, 150 }, Point { 250, 250 } };
	Graph_lib::Rectangle rect21 { Point { 250, 50 }, 200, 100 };
	Graph_lib::Rectangle rect22 { Point { 250, 150 }, 200, 100 };

	rect00.set_fill_color(Color::yellow);
	rect11.set_fill_color(Color::blue);
	rect12.set_fill_color(Color::red);
	rect21.set_fill_color(Color::green);

	win1.attach(rect00);
	win1.attach(rect11);
	win1.attach(rect12);
	win1.attach(rect21);
	win1.attach(rect22);

	rect11.move(400, 0);
	rect11.set_fill_color(Color::white);
	win1.set_label("rectangles 2");

	win1.put_on_top(rect00);
	win1.set_label("rectangles 3");

	rect00.set_color(Color::invisible);
	rect11.set_color(Color::invisible);
	rect12.set_color(Color::invisible);
	rect21.set_color(Color::invisible);
	rect22.set_color(Color::invisible);

	win1.wait_for_button();
}