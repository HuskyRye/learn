// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup

#pragma once

#include "Graph.h"
#include "Point.h"
#include "std_lib_facilities.h"

namespace Graph_lib {

//------------------------------------------------------------------------------

struct Arc : Shape {
	Arc(Point p, int ww, int hh, double aa1, double aa2);

	void draw_lines() const;

	Point center() const { return Point(point(0).x+w, point(0).y+h); }
	Point focus1() const { return Point(center().x+int(sqrt(double(w*w-h*h))), center().y); }
	Point focus2() const { return Point(center().x-int(sqrt(double(w*w-h*h))), center().y); }

	void set_major(int ww) { w = ww; }
	int major() const { return w; }
	void set_minor(int hh) { h = hh; }
	int minor() const { return h; }

	void set_angle(double d1, double d2) { a1 = d1; a2 = d2; }


private:
	int w;
	int h;
	double a1;
	double a2;
};

//------------------------------------------------------------------------------

struct Box : Shape {
	Box(Point xy, int ww, int hh) : w(ww), h(hh)
	{
		add(xy);
		if (h<=0 || w<=0) error("Bad Box: non-positive side");
		r = w < h ? w/4 : h/4;
	}
	Box(Point xy, int ww, int hh, int rr)
		: w(ww), h(hh), r(rr)
	{
		add(xy);
		if (h<=0 || w<=0) error("Bad Box: non-positive side");
		if (r >(w > h ? h : w) / 2) error("Bad Box: corner radius too largs");
	}
	Box(Point x, Point y)
		: w(y.x-x.x), h(y.y-x.y)
	{
		if (h<=0 || w<=0) error("Bad Box: non-positive side");
		r = w < h ? w/4 : h/4;
	}
	Box(Point x, Point y, int rr)
		: w(y.x-x.x), h(y.y-x.y), r(rr)
	{
		if (h<=0 || w<=0) error("Bad Box: non-positive side");
		if (r >(w > h ? h : w) / 2) error("Bad Box: corner radius too largs");
	}

	void draw_lines() const;

	int height() const { return h; }
	int width() const { return w; }
	int radius() const { return r; }

	void set_height(int hh) { h = hh; }
	void set_width(int ww) { w = ww; }
	void set_radius(int rr) { r = rr; }
private:
	int h;		// height
	int w;		// width
	int  r;		// radius
};

//------------------------------------------------------------------------------

struct TextBox : Box {
	TextBox(Point xy, int ww, int hh, const string& s)
		:Box(xy, ww, hh), label(Point { xy.x+5, xy.y+20 }, s) {}
	TextBox(Point x, Point y, const string& s)
		:Box(x, y), label(Point { x.x+4, x.y+17 }, s) {}

	void draw_lines() const;
	Text label;
};

//------------------------------------------------------------------------------

struct Arrow : Line {
	Arrow(Point p1, Point p2) : Line(p1, p2) {}
	void draw_lines() const;
};

//------------------------------------------------------------------------------

Point n(const Rectangle& rect);
Point s(const Rectangle& rect);
Point e(const Rectangle& rect);
Point w(const Rectangle& rect);
Point center(const Rectangle& rect);
Point ne(const Rectangle& rect);
Point se(const Rectangle& rect);
Point sw(const Rectangle& rect);
Point nw(const Rectangle& rect);

//------------------------------------------------------------------------------

Point n(const Circle& c);
Point s(const Circle& c);
Point e(const Circle& c);
Point w(const Circle& c);
Point center(const Circle& c);
Point ne(const Circle& c);
Point se(const Circle& c);
Point sw(const Circle& c);
Point nw(const Circle& c);

//------------------------------------------------------------------------------

Point n(const Ellipse& e);
Point s(const Ellipse& e);
Point e(const Ellipse& e);
Point w(const Ellipse& e);
Point center(const Ellipse& e);
Point ne(const Ellipse& e);
Point se(const Ellipse& e);
Point sw(const Ellipse& e);
Point nw(const Ellipse& e);

//------------------------------------------------------------------------------

struct Regular_hexagon : Shape {
	Regular_hexagon(Point xy, int rr);

	void draw_lines() const;

	Point center() const { return point(0); }
	int radius() const { return r; }
	void set_radius(int rr) { set_points(rr); }
private:
	int r;		// radius;
	void set_points(int r);
};

//------------------------------------------------------------------------------

struct Regular_polygon : Shape {
	Regular_polygon(Point xy, int nn, int rr);

	void draw_lines() const;

	Point center() const { return point(0); }
	int radius() const { return r; }
	int n_edge() const { return n; }

	void set_radius(int rr) { set_points(n, rr); }
protected:
	void set_points(int nn, int rr);
private:
	int r;
	int n;
};

//------------------------------------------------------------------------------

struct Smiley : Circle {
	Smiley(Point p, int rr);
	void draw_lines() const override ;
	void move(int dx, int dy) override;
	void set_eye_color(Color c);
	void set_mouth_color(Color c);
	void set_style(Line_style ls);
private:
	Arc mouth;
	Circle l_eye;
	Circle r_eye;
};

//------------------------------------------------------------------------------

struct Frowny : Circle {
	Frowny(Point p, int rr);
	void draw_lines() const override;
	void move(int dx, int dy) override;
	void set_eye_color(Color c);
	void set_mouth_color(Color c);
	void set_style(Line_style ls);
private:
	Arc mouth;
	Circle l_eye;
	Circle r_eye;
};

} // of namespace Graph_lib