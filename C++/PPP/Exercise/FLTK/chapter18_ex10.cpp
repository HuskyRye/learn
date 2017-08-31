/*
10.定义 Regular_polygon 类，构造函数的参数为中心、边数和中心到每个角的距离
*/

#include "Simple_window.h"
#include "Graph.h"
#include "My_graph.h"
#include "std_lib_facilities.h"

int main()
try {
	using namespace Graph_lib;
	Simple_window win { Point{0, 0}, 1440, 850, "Regular_polygon" };

	Vector_ref<Regular_polygon> vpoly;

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			vpoly.push_back(new Regular_polygon { Point{j * 100+50, i * 100+50}, i*8+j+3, 45 });
			// vpoly[vpoly.size()-1].set_style(Line_style(Line_style::dash, 2));
			vpoly[vpoly.size()-1].set_fill_color((i*8+j)*32%255);
			win.attach(vpoly[vpoly.size()-1]);
		}
	}

	// Regular_polygon fun { Point{400, 400}, 1000000, 300 };
	// win.attach(fun);

	win.wait_for_button();
}
catch (exception& e) {
	cerr << "exception: " << e.what() << '\n';
	keep_window_open();
}
catch (...) {
	cerr << "exception\n";
}