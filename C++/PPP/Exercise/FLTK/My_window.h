// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup

#pragma once

#include "Window.h"
#include "Graph.h"		// for Shapes
#include "GUI.h"		// for Widgets

namespace Graph_lib {

//------------------------------------------------------------------------------

struct Lines_window : Window {
	Lines_window(Point xy, int w, int h, const string& title);

private:
	// Data
	Open_polyline lines;

	// Widget
	Button next_botton;
	Button quit_botton;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;

	Menu color_menu;
	Button menu_botton;

	void change(Color c) { lines.set_color(c); redraw(); }
	
	void hide_menu() { color_menu.hide(); menu_botton.show(); }

	void red_pressed() { change(Color::red); hide_menu(); }
	void green_pressed() { change(Color::green); hide_menu(); }
	void blue_pressed() { change(Color::blue); hide_menu(); }
	void black_pressed() { change(Color::black); hide_menu(); }
	void menu_pressed() { menu_botton.hide(); color_menu.show(); }
	
	void next();
	void quit();
};

//------------------------------------------------------------------------------

} // of namespace Graph_lib
