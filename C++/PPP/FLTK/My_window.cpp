// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup

#include "My_window.h"

namespace Graph_lib {

//------------------------------------------------------------------------------

Lines_window::Lines_window(Point xy, int w, int h, const string & title)
	:Window(xy, w, h, title),
	next_botton { Point{x_max()-150, 0}, 70, 20, "Next point",
		[](Address, Address pw) {reference_to<Lines_window>(pw).next(); } },
	quit_botton { Point{x_max()-70, 0}, 70, 20, "Quit",
		[](Address, Address pw) {reference_to<Lines_window>(pw).quit(); } },
	next_x { Point{x_max()-310, 0}, 50, 20, "next x:" },
	next_y { Point{x_max()-210, 0}, 50, 20, "next y:" },
	xy_out { Point{100, 0}, 100, 20, "current (x,y):" },
	color_menu{Point{x_max()-70, 40}, 70, 20, Menu::vertical, "color"},
	menu_botton{Point{x_max()-80, 30}, 80, 20, "color menu",
	[](Address, Address pw) {reference_to<Lines_window>(pw).menu_pressed(); } }
{
	lines.set_color(Color::black);
	attach(next_botton);
	attach(quit_botton);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	xy_out.put("no point");
	color_menu.attach(new Button { Point{0, 0}, 0, 0, "red",
		[](Address, Address pw) {reference_to<Lines_window>(pw).red_pressed(); } });
	color_menu.attach(new Button { Point { 0, 0 }, 0, 0, "green",
		[](Address, Address pw) {reference_to<Lines_window>(pw).green_pressed(); } });
	color_menu.attach(new Button { Point{0, 0}, 0, 0, "blue",
		[](Address, Address pw) {reference_to<Lines_window>(pw).blue_pressed(); } });
	color_menu.attach(new Button { Point{0, 0}, 0, 0, "black",
		[](Address, Address pw) {reference_to<Lines_window>(pw).black_pressed(); } });
	attach(color_menu);
	color_menu.hide();
	attach(menu_botton);
	attach(lines);
}

//------------------------------------------------------------------------------

void Lines_window::quit()
{
	hide();
}

//------------------------------------------------------------------------------

void Lines_window::next()
{
	int x = next_x.get_int();
	int y = next_y.get_int();
	lines.add(Point { x, y });

	ostringstream ss;
	ss << '(' << x << ',' << y << ')';
	xy_out.put(ss.str());

	redraw();
}

//------------------------------------------------------------------------------

} // of namespace Graph_lib

