#include "Simple_window.h"
#include "Graph.h"

struct Distribution {
	int year, young, middle, old;
};

istream& operator>>(istream& is, Distribution& d)
{
	char ch1 = 0;
	char ch2 = 0;
	char ch3 = 0;
	Distribution dd;
	if (is >> ch1 >> dd.year >> ch2 >> dd.young >> dd.middle >> dd.old >> ch3) {
		if (ch1 != '(' || ch2 != ':' || ch3 != ')') {
			is.clear(ios_base::failbit);
			return is;
		}
	}
	else
		return is;
	d = dd;
	return is;
}

class Scale {		// 数据值转化为坐标值
	int cbase;		// 坐标基准
	int vbase;		// 基准值
	double scale;
public:
	Scale(int b, int vb, double s) : cbase{b}, vbase{vb}, scale{s}{}
	int operator()(int v) const { return cbase+(v-vbase)*scale; }
};

int main()
try {

	constexpr int xmax = 600;
	constexpr int ymax = 400;

	constexpr int xoffset = 100;	// 窗口左边到 y 轴的距离
	constexpr int yoffset = 60;		// 窗口底部到 x 轴的距离

	constexpr int xspace = 40;		// 坐标轴上方的空间
	constexpr int yspace = 40;

	constexpr int xlength = xmax-xoffset-xspace;
	constexpr int ylength = ymax-yoffset-yspace;

	constexpr int base_year = 1960;
	constexpr int end_year = 2040;

	constexpr double xscale = double(xlength)/(end_year-base_year);
	constexpr double yscale = double(ylength)/100;

	Simple_window win { Point { 100, 100 }, xmax, ymax, "Aging Japan" };
	Axis x { Axis::x, Point{xoffset, ymax-yoffset}, xlength, (end_year-base_year)/10,
		"year    1960    1970    1980    1990     "
		"2000     2010     2020     2030     2040"};
	x.set_color(Color::black);
	x.label.move(-100, 0);
	win.attach(x);

	Axis y { Axis::y, Point{xoffset, ymax-yoffset}, ylength, 10, "% of population" };
	y.set_color(Color::black);
	win.attach(y);

	Scale xs { xoffset, base_year, xscale };
	Scale ys { ymax-yoffset, 0, -yscale };

	Line current_year { Point {xs(2008), ys(0)}, Point{xs(2008), ys(100)} };
	current_year.set_color(Color::black);
	current_year.set_style(Line_style::dash);
	win.attach(current_year);
	
	string file_name = "japanese-age-data.txt";
	ifstream ifs { file_name };
	if (!ifs)
		error("can't open ", file_name);

	Open_polyline children;
	Open_polyline adults;
	Open_polyline aged;

	for (Distribution d; ifs >> d; ) {
		if (d.year<base_year || d.year > end_year)
			error("year out of range");
		if (d.young+d.middle+d.old != 100)
			error("percentages don't add up");
		const int x = xs(d.year);
		children.add(Point { x, ys(d.young) });
		adults.add(Point { x, ys(d.middle) });
		aged.add(Point { x, ys(d.old) });
	}

	Text children_label { Point { 20, children.point(0).y+5 }, "  age 0-14" };
	children.set_color(Color::red);
	children_label.set_color(Color::red);

	Text adults_label { Point { 20, adults.point(0).y+5 }, "age 15-64" };
	adults.set_color(Color::blue);
	adults_label.set_color(Color::blue);

	Text aged_label { Point { 20, aged.point(0).y+5 }, "    age 65+" };
	aged.set_color(Color::dark_green);
	aged_label.set_color(Color::dark_green);

	win.attach(children);
	win.attach(adults);
	win.attach(aged);

	win.attach(children_label);
	win.attach(adults_label);
	win.attach(aged_label);

	win.wait_for_button();
}
catch (exception& e) {
	cerr << "exception: " << e.what() << '\n';
}
catch (...) {
	cerr << "exception\n";
}