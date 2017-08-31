/*
	7.创建一个RGB比色图表
*/

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

struct RGB {
	int r, g, b;
};

RGB colorConverter(int hexValue)
{
	RGB rgbColor;
	rgbColor.r = ((hexValue >> 16) & 0xFF) / 255.0;  // Extract the RR byte
	rgbColor.g = ((hexValue >> 8) & 0xFF) / 255.0;   // Extract the GG byte
	rgbColor.b = ((hexValue) & 0xFF) / 255.0;        // Extract the BB byte

	return rgbColor;
}

int main()
{
	using namespace Graph_lib;
	Point tl { 100, 100 };
	Simple_window win { tl, 800, 600, "RGB" };
	
	const int width { 12 };

	Vector_ref<Graph_lib::Rectangle> rect;
	
	for (int i1 = 0; i1 < 4; ++i1) {
		for (int i2 = 0; i2 < 4; ++i2) {
			for (int j = 0; j < 16; ++j) {
				for (int k = 0; k < 16; ++k) {
					rect.push_back(new Graph_lib::Rectangle { Point{i2*16*width+k*width, i1*16*width+j*width }, width, width });
					rect[rect.size()-1].set_fill_color(fl_rgb_color(16*(4*i1+i2), 16*j, 16*k));
					rect[rect.size()-1].set_color(Color::invisible);
					win.attach(rect[rect.size()-1]);
				}
			}
		}
	}
	
	win.wait_for_button();
	for (int i = 0; i<rect.size(); ++i)
		win.detach(rect[i]);

	const int box_h = 22;
	const int box_w = 88;
	Vector_ref<Graph_lib::Rectangle> boxes;
	Vector_ref<Text> labels;

	for (int i = 0; i<6; ++i) {
		for (int j = 0; j<6; ++j) {
			for (int k = 0; k<6; ++k) {
				boxes.push_back(new Graph_lib::Rectangle { Point { k*box_w, i*6*box_h+j*box_h }, box_w, box_h });
				boxes[boxes.size()-1].set_fill_color(fl_rgb_color(51*i, 51*j, 51*k));
				boxes[boxes.size()-1].set_color(Color { Color::invisible });
				win.attach(boxes[boxes.size()-1]);
				ostringstream oss;
				oss << hex << uppercase << setfill('0')
					<< setw(2) << 51*i << setw(2) << 51*j << setw(2) << 51*k;
				labels.push_back(new Text { Point{k*box_w+20, i*6*box_h+j*box_h+16}, oss.str() });
				if (j < 3)
					labels[labels.size()-1].set_color(Color::white);
				win.attach(labels[labels.size()-1]);
			}
		}
	}

	win.wait_for_button();
}

