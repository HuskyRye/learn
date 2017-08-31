#include "std_lib_facilities.h"

int area(int x, int y)
{
	if (x <= 0 || y <= 0)
		error("non-positive area() argument");
	return x * y;
}

constexpr int frame_width = 2;

int framed_area(int x, int y)
{
	constexpr int frame_width = 2;
	if (x-frame_width <= 0 || y-frame_width <= 0)
		error("non-positive area() argument called by framed_area()");
	return area(x-frame_width, y-frame_width);
}

// 调用者处理错误
int main1()
{
	int x = -1;
	int y = 2;
	int z = 4;

	if (x <=0)
		error("non-positive x");
	if (y <= 0)
		error("non-positive y");

	if (x <= 0 || y <= 0)
		error("non-positive area() argument");

	int area1 = area(x, y);

	if (1-frame_width <= 0 || z-frame_width <= 0)
		error("non-positive 2nd area() argument called by framed_area()");
	int area2 = framed_area(1, z);

	if (y - frame_width <= 0 || z - frame_width <= 0)
		error("non-positive area() argument called by framed_area()");
	int area3 = framed_area(y, z);

	double ratio = double(area1)/area3;

	return 0;
}

// 被调用者处理错误，在 framed_area() 内部
int main2()
{
	int x = -1;
	int y = 2;
	int z = 4;

	int area1 = area(x, y);
	int area2 = framed_area(1, z);
	int area3 = framed_area(y, z);

	double ratio = double(area1)/area3;

	return 0;
}