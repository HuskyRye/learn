// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup

#pragma once
#include "My_graph.h"

namespace Graph_lib {

//------------------------------------------------------------------------------

const double pi = 3.14159265357;

//------------------------------------------------------------------------------

Arc::Arc(Point p, int ww, int hh, double aa1, double aa2)
	:w(ww), h(hh), a1(aa1), a2(aa2)
{
	add(Point(p.x-w, p.y-h));
}

//------------------------------------------------------------------------------

void Arc::draw_lines() const
{
	if (fill_color().visibility()) {	// fill
		fl_color(fill_color().as_int());
		fl_pie(point(0).x, point(0).y, w+w-1, h+h-1, a1, a2);
		fl_color(color().as_int());	// reset color
	}

	if (color().visibility()) {
		fl_color(color().as_int());
		fl_arc(point(0).x, point(0).y, w+w, h+h, a1, a2);
	}
}

//------------------------------------------------------------------------------

void Box::draw_lines() const
{
	if (fill_color().visibility()) {    // fill
		fl_color(fill_color().as_int());

		// rectangles
		fl_rectf(point(0).x+r, point(0).y, w-2*r, r);
		fl_rectf(point(0).x, point(0).y+r, w, h-2*r);
		fl_rectf(point(0).x+r, point(0).y+h-r, w-2*r, r);

		// corners
		fl_pie(point(0).x, point(0).y, r+r-1, r+r-1, 90, 180);
		fl_pie(point(0).x, point(0).y+h-2*r, r+r-1, r+r-1, 180, 270);
		fl_pie(point(0).x+w-2*r, point(0).y, r+r-1, r+r-1, 0, 90);
		fl_pie(point(0).x+w-2*r, point(0).y+h-2*r, r+r-1, r+r-1, 270, 0);

		fl_color(color().as_int());	// reset color		
	}

	if (color().visibility()) {    // lines on top of fill
		fl_color(color().as_int());

		// draw lines
		fl_line(point(0).x+r, point(0).y,
			point(0).x+w-r-1, point(0).y);
		fl_line(point(0).x, point(0).y+r,
			point(0).x, point(0).y+h-r-1);
		fl_line(point(0).x+r, point(0).y+h-1,
			point(0).x+w-r, point(0).y+h-1);
		fl_line(point(0).x+w-1, point(0).y+r,
			point(0).x+w-1, point(0).y+h-r);

		// corners
		fl_arc(point(0).x, point(0).y, r+r, r+r, 90, 180);
		fl_arc(point(0).x, point(0).y+h-2*r, r+r, r+r, 180, 270);
		fl_arc(point(0).x+w-2*r, point(0).y, r+r, r+r, 0, 90);
		fl_arc(point(0).x+w-2*r, point(0).y+h-2*r, r+r, r+r, 270, 0);
	}
}

//------------------------------------------------------------------------------

void TextBox::draw_lines() const
{
	Box::draw_lines();
	label.draw();
}

//------------------------------------------------------------------------------

void Arrow::draw_lines() const
{
	Line::draw_lines();

	// add arrowhead: p2 and two points
	double line_len =
		sqrt(double(pow(point(1).x-point(0).x, 2) + pow(point(1).y-point(0).y, 2)));  // length of p1p2

																					  // coordinates of the a point on p1p2 with distance 8 from p2
	double pol_x = 8/line_len*point(0).x + (1-8/line_len)*point(1).x;
	double pol_y = 8/line_len*point(0).y + (1-8/line_len)*point(1).y;

	// pl is 4 away from p1p2 on the "left", pl_pol is orthogonal to p1p2
	double pl_x = pol_x + 4/line_len*(point(1).y-point(0).y);
	double pl_y = pol_y + 4/line_len*(point(0).x-point(1).x);

	// pr is 4 away from p1p2 on the "right", pr_pol is orthogonal to p1p2
	double pr_x = pol_x + 4/line_len*(point(0).y-point(1).y);
	double pr_y = pol_y + 4/line_len*(point(1).x-point(0).x);

	// draw arrowhead - is always filled in line color
	if (color().visibility()) {
		fl_begin_complex_polygon();
		fl_vertex(point(1).x, point(1).y);
		fl_vertex(pl_x, pl_y);
		fl_vertex(pr_x, pr_y);
		fl_end_complex_polygon();
	}
}

//------------------------------------------------------------------------------

Point n(const Rectangle& rect)
{
	return Point { rect.point(0).x+rect.width()/2, rect.point(0).y };
}
Point s(const Rectangle& rect)
{
	return Point { rect.point(0).x+rect.width()/2, rect.point(0).y+rect.height() };
}
Point e(const Rectangle& rect)
{
	return Point { rect.point(0).x+rect.width(), rect.point(0).y+rect.height()/2 };
}
Point w(const Rectangle& rect)
{
	return Point { rect.point(0).x, rect.point(0).y+rect.height()/2 };

}
Point center(const Rectangle& rect)
{
	return Point { rect.point(0).x+rect.width()/2, rect.point(0).y+rect.height()/2 };
}
Point ne(const Rectangle& rect)
{
	return Point { rect.point(0).x+rect.width(), rect.point(0).y };
}
Point se(const Rectangle& rect)
{
	return Point { rect.point(0).x+rect.width(), rect.point(0).y+rect.height() };
}
Point sw(const Rectangle& rect)
{
	return Point { rect.point(0).x, rect.point(0).y+rect.height() };
}
Point nw(const Rectangle& rect)
{
	return rect.point(0);
}

//------------------------------------------------------------------------------

Point n(const Circle& c)
{
	return Point { c.center().x, c.center().y-c.radius() };
}
Point s(const Circle& c)
{
	return Point { c.center().x, c.center().y+c.radius() };
}
Point e(const Circle& c)
{
	return Point { c.center().x+c.radius(), c.center().y };
}
Point w(const Circle& c)
{
	return Point { c.center().x-c.radius(), c.center().y };
}
Point center(const Circle& c)
{
	return c.center();
}
Point ne(const Circle& c)
{
	return Point { c.center().x+c.radius(), c.center().y-c.radius() };
}
Point se(const Circle& c)
{
	return Point { c.center().x+c.radius(), c.center().y+c.radius() };
}
Point sw(const Circle& c)
{
	return Point { c.center().x-c.radius(), c.center().y+c.radius() };
}
Point nw(const Circle& c)
{
	return Point { c.point(0).x, c.point(0).y };
}

//------------------------------------------------------------------------------

Point n(const Ellipse& e)
{
	return Point { e.center().x, e.center().y-e.minor() };
}
Point s(const Ellipse& e)
{
	return Point { e.center().x, e.center().y+e.minor() };
}
Point e(const Ellipse& e)
{
	return Point { e.center().x+e.major(), e.center().y };
}
Point w(const Ellipse& e)
{
	return Point { e.center().x-e.major(), e.center().y };
}
Point center(const Ellipse& e)
{
	return e.center();
}
Point ne(const Ellipse& e)
{
	return Point { e.center().x+e.major(), e.center().y-e.minor() };
}
Point se(const Ellipse& e)
{
	return Point { e.center().x+e.major(), e.center().y+e.minor() };
}
Point sw(const Ellipse& e)
{
	return Point { e.center().x-e.major(), e.center().y+e.minor() };
}
Point nw(const Ellipse& e)
{
	return Point { e.point(0).x, e.point(0).y };
}

//------------------------------------------------------------------------------

Regular_hexagon::Regular_hexagon(Point xy, int rr)
	:r(rr)
{
	add(xy);
	for (int i = 0; i < 6; ++i)
		add(Point());
	set_points(rr);
}

//------------------------------------------------------------------------------

void Regular_hexagon::set_points(int r)
{
	set_point(1, Point { static_cast<int>(point(0).x), static_cast<int>(point(0).y-r) });
	set_point(2, Point { static_cast<int>(point(0).x+sqrt(3)/2.0*r), static_cast<int>(point(0).y-r/2.0) });
	set_point(3, Point { static_cast<int>(point(0).x+sqrt(3)/2.0*r), static_cast<int>(point(0).y+r/2.0) });
	set_point(4, Point { static_cast<int>(point(0).x), static_cast<int>(point(0).y+r) });
	set_point(5, Point { static_cast<int>(point(0).x-sqrt(3)/2.0*r), static_cast<int>(point(0).y+r/2.0) });
	set_point(6, Point { static_cast<int>(point(0).x-sqrt(3)/2.0*r), static_cast<int>(point(0).y-r/2.0) });
}

//------------------------------------------------------------------------------

void Regular_hexagon::draw_lines() const
{
	if (fill_color().visibility()) {
		fl_color(fill_color().as_int());
		fl_begin_complex_polygon();
		for (int i = 1; i < number_of_points(); ++i) {
			fl_vertex(point(i).x, point(i).y);
		}
		fl_end_complex_polygon();
		fl_color(color().as_int());
	}
	if (color().visibility()) {
		for (int i = 1; i < number_of_points()-1; ++i) {
			fl_line(point(i).x, point(i).y, point(i+1).x, point(i+1).y);
		}
		fl_line(point(6).x, point(6).y, point(1).x, point(1).y);
	}
}

//------------------------------------------------------------------------------

Regular_polygon::Regular_polygon(Point xy, int nn, int rr)
	:n { nn }, r { rr }
{
	add(xy);

	for (int i = 0; i < n; ++i) {
		add(Point {});
	}
	set_points(n, r);
}

//------------------------------------------------------------------------------

void Regular_polygon::set_points(int n, int r)
{
	double rotate = 2*pi/n;
	double current = pi/n-pi/2;
	for (int i = 1; i < number_of_points(); ++i)
		set_point(i, Point { point(0).x+static_cast<int>(cos(current+i*rotate)*r), point(0).y-static_cast<int>(sin(current+i*rotate)*r) });
}

//------------------------------------------------------------------------------

void Regular_polygon::draw_lines() const
{
	if (fill_color().visibility()) {
		fl_color(fill_color().as_int());
		fl_begin_complex_polygon();
		for (int i = 1; i<number_of_points(); ++i)  // point(0) is center
			fl_vertex(point(i).x, point(i).y);
		fl_end_complex_polygon();
		fl_color(color().as_int());    // reset color
	}

	if (color().visibility()) {
		for (int i = 1; i<number_of_points()-1; ++i)
			fl_line(point(i).x, point(i).y, point(i+1).x, point(i+1).y);
		fl_line(point(number_of_points()-1).x,
			point(number_of_points()-1).y,
			point(1).x,
			point(1).y);   // close polygon
	}
}

//------------------------------------------------------------------------------

Smiley::Smiley(Point p, int rr)
	:Circle(p, rr),
	l_eye { Point { p.x-static_cast<int>(rr*0.45), p.y-static_cast<int>(rr*0.25) }, static_cast<int>(rr*0.1) },
	r_eye { Point { p.x+static_cast<int>(rr*0.45), p.y-static_cast<int>(rr*0.25) }, static_cast<int>(rr*0.1) },
	mouth { p, static_cast<int>(0.66*rr), static_cast<int>(0.66*rr), 200, 340 }
{
	l_eye.set_fill_color(color());
	r_eye.set_fill_color(color());
}

//------------------------------------------------------------------------------

void Smiley::draw_lines() const
{
	Circle::draw_lines();
	l_eye.draw();
	r_eye.draw();
	mouth.draw();
}

//------------------------------------------------------------------------------

void Smiley::move(int dx, int dy)
{
	Shape::move(dx, dy);
	l_eye.move(dx, dy);
	r_eye.move(dx, dy);
	mouth.move(dx, dy);
}

//------------------------------------------------------------------------------

void Smiley::set_eye_color(Color c)
{
	l_eye.set_fill_color(c);
	l_eye.set_color(c);
	r_eye.set_fill_color(c);
	r_eye.set_fill_color(c);
}

//------------------------------------------------------------------------------

void Smiley::set_mouth_color(Color c)
{
	mouth.set_color(c);
}

//------------------------------------------------------------------------------

void Smiley::set_style(Line_style ls)
{
	Circle::set_style(ls);
	l_eye.set_style(ls);
	r_eye.set_style(ls);
	mouth.set_style(ls);
}

//------------------------------------------------------------------------------

Frowny::Frowny(Point p, int rr)
	:Circle(p, rr),
	l_eye { Point { p.x-static_cast<int>(rr*0.45), p.y-static_cast<int>(rr*0.25) }, static_cast<int>(rr*0.1) },
	r_eye { Point { p.x+static_cast<int>(rr*0.45), p.y-static_cast<int>(rr*0.25) }, static_cast<int>(rr*0.1) },
	mouth { Point{p.x, p.y+static_cast<int>(0.8*rr) }, static_cast<int>(0.66*rr), static_cast<int>(0.66*rr), 20, 160 }
{
	l_eye.set_fill_color(color());
	r_eye.set_fill_color(color());
}

//------------------------------------------------------------------------------

void Frowny::draw_lines() const
{
	Circle::draw_lines();
	l_eye.draw();
	r_eye.draw();
	mouth.draw();
}

//------------------------------------------------------------------------------

void Frowny::move(int dx, int dy)
{
	Shape::move(dx, dy);
	l_eye.move(dx, dy);
	r_eye.move(dx, dy);
	mouth.move(dx, dy);
}

//------------------------------------------------------------------------------

void Frowny::set_eye_color(Color c)
{
	l_eye.set_fill_color(c);
	l_eye.set_color(c);
	r_eye.set_fill_color(c);
	r_eye.set_color(c);
}

void Frowny::set_mouth_color(Color c)
{
	mouth.set_color(c);
}

void Frowny::set_style(Line_style ls)
{
	Circle::set_style(ls);
	l_eye.set_style(ls);
	r_eye.set_style(ls);
	mouth.set_style(ls);
}

} // of namespace Graph_lib