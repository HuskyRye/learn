#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

int main()
{
	using namespace Graph_lib;
	constexpr Point tl { 100, 100 };
	Simple_window win1 { tl, 600, 400, "16*16 color matrix" };

	Vector_ref<Graph_lib::Rectangle> vr;
	for (int i = 0; i < 16; ++i)
		for (int j = 0; j < 16; ++j) {
			vr.push_back(new Graph_lib::Rectangle { Point{i*20, j*20}, 20, 20 });
			vr[vr.size()-1].set_fill_color(Color { i*16+j });
			vr[vr.size()-1].set_color(Color::black);
			win1.attach(vr[vr.size()-1]);
		}

	win1.wait_for_button();
}