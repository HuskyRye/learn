/*
	1.定义 Arc 类，绘制部分椭圆（见 Graph.h 和 Graph.cpp）
	2.定义由 4 条线和 4 个圆弧组成的 Box 类，绘制一个圆角矩形（见 Graph.h 和 Graph.cpp）
	3.定义 Arrow 类，绘制带有箭头的线（见 Graph.h 和 Graph.cpp）
	4.定义函数 n()、s()、e()、w()、center()、ne()、se()、sw()、nw()，接收一个 Rectange，返回一个 Point
	5.为 Circle 和 Ellipse 定义上述函数
	6.定义 TextBox 类，绘制一个带有文本标签的圆角矩形（见 Graph.h 和 Graph.cpp）
*/


#include "Simple_window.h"
#include "Graph.h"
#include "My_graph.h"
#include "std_lib_facilities.h"

int main()
try {
	using namespace Graph_lib;
	Point tl { 100, 100 };
	Simple_window win(tl, 800, 600, "Arc Box Arrow");

	win.wait_for_button();

	Graph_lib::Arc arc1 { Point{150, 100}, 100, 50, 45, 175 };
	win.attach(arc1);

	arc1.set_color(Color::green);
	arc1.set_fill_color(Color::red);
	arc1.set_angle(100, 200);
	arc1.set_style(Line_style { Line_style::dash, 4 });


	Box box { Point{200, 200}, 250, 100 };
	win.attach(box);

	Arrow arrow1 { Point{100, 300}, Point{100, 150} };
	win.attach(arrow1);

	win.wait_for_button();

	box.set_color(Color::red);
	box.set_fill_color(Color::green);
	box.set_height(50);
	box.set_height(100);
	box.set_radius(10);
	box.set_style(Line_style { Line_style::dash, 2 });

	arrow1.set_color(Color::red);
	arrow1.set_fill_color(Color::green);
	arrow1.set_style(Line_style { Line_style::dash, 2 });

	Graph_lib::Rectangle rect{ Point{300, 50}, 150, 100 };
	win.attach(rect);

	//Rectangle: n()、s()、e()、w()、center()、ne()、se()、sw()、nw()
	Arrow rectcn { center(rect), n(rect) };
	Arrow rectcs { center(rect), s(rect) };
	Arrow rectce { center(rect), e(rect) };
	Arrow rectcw { center(rect), w(rect) };
	Arrow rectcne { center(rect), ne(rect) };
	Arrow rectcse { center(rect), se(rect) };
	Arrow rectcsw { center(rect), sw(rect) };
	Arrow rectcnw { center(rect), nw(rect) };
	win.attach(rectcn);
	win.attach(rectcs);
	win.attach(rectce);
	win.attach(rectcw);
	win.attach(rectcne);
	win.attach(rectcse);
	win.attach(rectcsw);
	win.attach(rectcnw);

	Circle c { Point{100, 400}, 50 };
	win.attach(c);

	//Circle: n()、s()、e()、w()、center()、ne()、se()、sw()、nw()
	Arrow ccn { center(c), n(c) };
	Arrow ccs { center(c), s(c) };
	Arrow cce { center(c), e(c) };
	Arrow ccw { center(c), w(c) };
	Arrow ccne { center(c), ne(c) };
	Arrow ccse { center(c), se(c) };
	Arrow ccsw { center(c), sw(c) };
	Arrow ccnw { center(c), nw(c) };
	win.attach(ccn);
	win.attach(ccs);
	win.attach(cce);
	win.attach(ccw);
	win.attach(ccne);
	win.attach(ccse);
	win.attach(ccsw);
	win.attach(ccnw);
	Graph_lib::Rectangle crect { nw(c), se(c) };
	win.attach(crect);

	Graph_lib::Ellipse ell { Point{300, 400}, 100, 50 };
	win.attach(ell);

	//Elipse: n()、s()、e()、w()、center()、ne()、se()、sw()、nw()
	Arrow ellcn { center(ell), n(ell) };
	Arrow ellcs { center(ell), s(ell) };
	Arrow ellce { center(ell), e(ell) };
	Arrow ellcw { center(ell), w(ell) };
	Arrow ellcne { center(ell), ne(ell) };
	Arrow ellcse { center(ell), se(ell) };
	Arrow ellcsw { center(ell), sw(ell) };
	Arrow ellcnw { center(ell), nw(ell) };
	win.attach(ellcn);
	win.attach(ellcs);
	win.attach(ellce);
	win.attach(ellcw);
	win.attach(ellcne);
	win.attach(ellcse);
	win.attach(ellcsw);
	win.attach(ellcnw);
	Graph_lib::Rectangle ellrect { nw(ell), se(ell) };
	win.attach(ellrect);

	TextBox tb { Point{500, 100}, 100, 30, "Hello" };
	win.attach(tb);
	win.wait_for_button();
	tb.label.set_font(Font::courier);
	tb.label.set_font_size(25);
	tb.set_color(Color::invisible);
	tb.set_fill_color(Color::black);
	tb.label.set_color(Color::white);
	tb.set_style(Line_style { Line_style::dash, 2 });

	win.wait_for_button();
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
}
catch (...) {
	cerr << "exception\n";
	keep_window_open();
}