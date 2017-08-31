/*
8.定义 Regular_hexagon（正六边形），构造函数的参数为中心和从中心到每个角的距离
9.用 Regular_hexagon铺贴窗口的一部分区域
*/

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

int main()
{
	using namespace Graph_lib;
	Point tl { 100, 100 };
	Simple_window win { tl, 800, 600, "Regular_hexagon" };
	
	win.wait_for_button();
	const int r = 50;
	Vector_ref<Regular_hexagon> vhex;
	for (int i = 0; i < 11; ++i) {
		for (int j = 0; j < 20; ++j) {
			vhex.push_back(new Regular_hexagon { Point { static_cast<int>((i%2*0.5+j)*(sqrt(3)*r)), static_cast<int>((1+1.5*i)*r)}, r });
			vhex[vhex.size()-1].set_fill_color(Color::invisible);
			vhex[vhex.size()-1].set_color(Color::red);
			win.attach(vhex[vhex.size()-1]);
		}
	}


	win.wait_for_button();
}

