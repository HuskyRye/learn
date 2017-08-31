#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x)+slope(x); }

int main()
{
	constexpr int xmax = 600;
	constexpr int ymax = 400;
	
	constexpr Point orig { xmax/2, ymax/2 };

	constexpr double r_min = -10;
	constexpr double r_max = 11;

	constexpr int n_points = 400;

	constexpr double x_scale = 30;
	constexpr double y_scale = 30;

	Simple_window win{ Point{100, 100}, xmax, ymax, "Function graphing" };

	Function f { one, r_min, r_max, orig, n_points, x_scale, y_scale };
	f.set_color(Color::black);
	Function f2 { slope, r_min, r_max, orig, n_points, x_scale, y_scale };
	f2.set_color(Color::black);
	Function f3 { square, r_min, r_max, orig, n_points, x_scale, y_scale };
	f3.set_color(Color::black);
	Function f4 { cos, r_min, r_max, orig, n_points, x_scale, y_scale };
	f4.set_color(Color::blue);
	Function f5 { sloping_cos, r_min, r_max, orig, n_points, x_scale, y_scale };
	f5.set_color(Color::black);

	win.attach(f);
	win.attach(f2);
	win.attach(f3);
	win.attach(f4);
	win.attach(f5);

	Text ts { Point{100, orig.y-40}, "one" };
	Text ts2 { Point{100, orig.y+orig.y/2-20}, "x/2" };
	Text ts3 { Point{orig.x-100, 20}, "x*x" };
	ts.set_color(Color::black);
	ts2.set_color(Color::black);
	ts3.set_color(Color::black);
	win.attach(ts);
	win.attach(ts2);
	win.attach(ts3);
	win.set_label("Function graphing: label functions");

	constexpr int xlength = xmax-40;
	constexpr int ylength = ymax-40;

	Axis x { Axis::x, Point{20, orig.y}, xlength, static_cast<int>(xlength/x_scale), "one notch == 1" };
	Axis y { Axis::y, Point { orig.x, ylength+20 }, ylength, static_cast<int>(ylength/y_scale), "one notch == 1" };
	x.set_color(Color::red);
	x.label.move(-160, 0);
	x.notches.set_color(Color::dark_red);
	y.set_color(Color::red);
	win.attach(x);
	win.attach(y);

	Function s1 { log, 0.000001, r_max, orig, n_points, x_scale, y_scale };
	s1.set_color(Color::black);
	Function s2 { sin, r_min, r_max, orig, n_points, x_scale, y_scale };
	s2.set_color(Color::blue);
	Function s3 { exp, r_min, r_max, orig, n_points, x_scale, y_scale };
	s3.set_color(Color::green);

	win.attach(s1);
	win.attach(s2);
	win.attach(s3);

	// lambda ±í´ïÊ½
	// Function s5 {[](double x) -> double {return cos(x)+slope(x); },
	//	r_min, r_max, orig, n_points, x_scale, y_scale };

	win.wait_for_button();
}