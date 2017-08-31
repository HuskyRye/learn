#include "Simple_window.h"
#include "Graph.h"

double fac(int n)		// factorinal(n); n!
{
	double r = 1;
	while (n > 1) {
		r *= n;
		--n;
	}
	return r;
}

double term(double x, int n)
{
	return pow(x, n)/fac(n);	//µЪ n По
}

double expe(double x, int n)
{
	double sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += term(x, i);
	}
	return sum;
}

int expN_number_of_terms { 0 };

double expN(double x)
{
	return expe(x, expN_number_of_terms);
}

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

	Simple_window win { Point { 100, 100 }, xmax, ymax, "Function graphing" };

	constexpr int xlength = xmax-40;
	constexpr int ylength = ymax-40;

	Axis x { Axis::x, Point { 20, orig.y }, xlength, static_cast<int>(xlength/x_scale), "one notch == 1" };
	Axis y { Axis::y, Point { orig.x, ylength+20 }, ylength, static_cast<int>(ylength/y_scale), "one notch == 1" };
	x.set_color(Color::red);
	y.set_color(Color::red);
	win.attach(x);
	win.attach(y);

	Function f { exp, r_min, r_max, orig, n_points, x_scale, y_scale };
	f.set_color(Color::blue);
	win.attach(f);

	for (int n = 0; n < 50; ++n) {
		ostringstream ss;
		ss << "exp approximation; n==" << n;
		win.set_label(ss.str());
		expN_number_of_terms = n;
		Function e { expN, r_min, r_max, orig, n_points, x_scale, y_scale };
		e.set_color(Color::green);
		win.attach(e);
		win.wait_for_button();
		win.detach(e);
	}
}