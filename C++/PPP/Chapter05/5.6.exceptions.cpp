#include "std_lib_facilities.h"

class Bad_area {};	// 专门报告 area() 错误的类

int area(int length, int width)
// preconditon: length, width 大于零
// postcondition: 返回正数，表示矩形面积
{
	if (length <= 0 || width <= 0)
		throw Bad_area {};
	return length * width;
}

int framed_area(int x, int y)
{
	constexpr int frame_width = 2;
	if (x-frame_width <= 0 || y-frame_width <= 0)
		error("non-positive area() argument called by framed_area()");
	return area(x-frame_width, y-frame_width);
}

int main1()
try {
	int x = -1;
	int y = 2;
	int z = 4;

	int area1 = area(x, y);
	int area2 = framed_area(1, z);
	int area3 = framed_area(y, z);
	double ratio = double(area1)/area3;
	return 0;
}
catch (Bad_area) {
	cout << "bad arguments to area()\n";
}

int main2()
try {
	vector<int> v;
	for (int x; cin >> x; )
		v.push_back(x);
	for (int i = 0; i <= v.size(); ++i)
		cout << "v[" << i << "] == " << v[i] << '\n';
	return 0;
}
catch (out_of_range) {
	cerr << "Range error\n";
	return 1;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Exception: something went wrong\n";
	keep_window_open();
	return 2;
}

int main3()
try {
	int x1 = narrow_cast<int>(2.9);
	int x2 = narrow_cast<int>(2.0);
	char c1 = narrow_cast<char>(1066);
	char c2 = narrow_cast<char>(85);
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}

int my_complicated_function(int a, int b, int c)
// precondition: 参数为正整数且 a<b<c
{
	if (!(0<a && a<b && b<c))
		error("bad arguments for mcf");
}
