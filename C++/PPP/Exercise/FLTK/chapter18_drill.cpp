#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

int main()
try {
	
	constexpr Point tl { 100, 50 };
	Simple_window win1 { tl, 1000, 800, "chapter18 drill" };

	win1.wait_for_button();

	int x_size = 800;
	int y_size = 800;
	int x_grid = 100;
	int y_grid = 100;

	Lines grid;
	for (int x = x_grid; x < x_size; x += x_grid)
		grid.add(Point { x, 0 }, Point { x, y_size });
	for (int y = y_grid; y < y_size; y += y_grid)
		grid.add(Point { 0, y }, Point { x_size, y });
	win1.attach(grid);

	Vector_ref<Graph_lib::Rectangle> vr;
	for (int i = 0; i < 8; ++i) {
		vr.push_back(new Graph_lib::Rectangle(Point { i*100, i*100 }, 101, 101));
		vr[vr.size()-1].set_fill_color(Color::red);
		win1.attach(vr[vr.size()-1]);
	}

	Image img1 { Point{200, 0}, "image.jpg" };
	img1.set_mask(Point { 200, 0 }, 200, 200);
	win1.attach(img1);

	Image img2 { Point { 0, 200 }, "image.jpg" };
	img2.set_mask(Point { 200, 0 }, 200, 200);
	// img2.set_mask(Point { 0, 200 }, 199, 200);
	win1.attach(img2);

	Image img3 { Point { 500, 200 }, "image.jpg" };
	img3.set_mask(Point { 200, 0 }, 200, 200);
	// img3.set_mask(Point { 101, 500 }, 199, 200);
	win1.attach(img3);

	Image cpp { Point{0, 0}, "snow_cpp.gif" };
	cpp.set_mask(Point { 110, 70 }, 100, 100);
	win1.attach(cpp);
	win1.put_on_top(cpp);

	win1.wait_for_button();

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 7; ++j) {
			cpp.move(100, 0);
			win1.wait_for_button();
		}
		cpp.move(-800, 100);
	}

	win1.wait_for_button();

}
catch (exception& e) {
	cerr << "exception: " << e.what() << '\n';
	keep_window_open();
}
catch (...) {
	cerr << "exception\n";
	keep_window_open();
}