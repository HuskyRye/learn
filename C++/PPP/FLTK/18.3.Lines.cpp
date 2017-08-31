#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

int main()
{
	using namespace Graph_lib;
	constexpr Point tl { 100, 100 };
	Simple_window win1 { tl, 600, 400, "Lines +" };

	Lines x;
	x.add(Point { 100, 100 }, Point { 200, 100 });
	x.add(Point { 150, 50 }, Point { 150, 150 });
	x.set_color(Color::black);
	win1.attach(x);

	int x_size = win1.x_max();
	int y_size = win1.y_max();
	int x_grid = 80;
	int y_grid = 40;

	Lines grid;
	for (int x = x_grid; x < x_size; x += x_grid)
		grid.add(Point { x, 0 }, Point { x, y_size });
	for (int y = y_grid; y < y_size; y += y_grid)
		grid.add(Point { 0, y }, Point { x_size, y });
	grid.set_color(Color::red);
	grid.set_style(Line_style {Line_style::dash,2});
	win1.attach(grid);

	Lines y = {
		{Point {200, 200}, Point{300, 200}},
		{Point {250, 150}, Point{250, 250}}
	};
	y.set_color(Color::green);
	win1.attach(y);

	win1.wait_for_button();
}