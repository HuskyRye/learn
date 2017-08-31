#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;

int main()
try {
	Point tl { 100, 100 };
	Simple_window win { tl, 600, 400, "Canvas" };

	Axis xa { Axis::x, Point{20, 300}, 280, 10, "x axis" };
	// Axis::x 水平，从(20, 300)开始，280个像素长，10个刻度，标签为"x axis"
	xa.set_color(Color::black);
	win.attach(xa);

	Axis ya { Axis::y, Point{20, 300}, 280, 10, "y axis" };
	ya.set_color(Color::black);
	ya.label.set_color(Color::dark_red);
	win.attach(ya);

	Function sine { sin, 0, 100, Point{20, 150}, 1000, 50, 50 };
	// sin函数，[0, 100)区间的sin函数，点(20,150)为原点，1000个点，x值比例乘50，y值比例乘50
	sine.set_color(Color::black);
	win.attach(sine);

	// Polygon
	Graph_lib::Polygon poly;
	poly.add(Point { 300, 200 });
	poly.add(Point { 350, 100 });
	poly.add(Point { 400, 200 });
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);

	// Rectangle
	Graph_lib::Rectangle r { Point{200, 200}, 100, 50 };
	r.set_color(Color::black);
	win.attach(r);

	Closed_polyline poly_rect;
	poly_rect.add(Point { 100, 50 });
	poly_rect.add(Point { 200, 50 });
	poly_rect.add(Point { 200, 100 });
	poly_rect.add(Point { 100, 100 });
	poly_rect.add(Point { 50, 75 });
	poly_rect.set_color(Color::black);
	win.attach(poly_rect);

	r.set_fill_color(Color::yellow);
	poly.set_style(Line_style(Line_style::dash, 4));
	poly_rect.set_style(Line_style(Line_style::dash, 2));
	poly_rect.set_fill_color(Color::green);

	// Text
	Text t { Point{150, 150}, "Hello world!" };
	t.set_color(Color::black);
	t.set_font(Font::times_bold);
	t.set_font_size(20);
	win.attach(t);

	// Image
	Image ii { Point{100, 50}, "image.jpg" };
	win.attach(ii);
	ii.move(100, 200);

	Circle c { Point{100, 200}, 50 };
	c.set_color(Color::black);
	win.attach(c);

	Graph_lib::Ellipse e { Point{100, 200}, 75, 25 };
	e.set_color(Color::black);
	win.attach(e);

	Mark m { Point{100, 200}, 'x' };
	win.attach(m);

	ostringstream oss;
	oss << "screen size: " << x_max() << '*' << y_max()
		<< "; window size: " << win.x_max() << '*' << win.y_max();
	Text sizes { Point{100, 20}, oss.str() };
	sizes.set_color(Color::black);
	win.attach(sizes);

	Image cal { Point{225, 225}, "snow_cpp.gif" };
	cal.set_mask(Point { 40, 40 }, 200, 150);		// 显示图片中间部分
	win.attach(cal);

	win.set_label("Canvas #12");
	win.wait_for_button();
}
catch (exception& e) {
	return 1;
}
catch (...) {
	return 2;
}