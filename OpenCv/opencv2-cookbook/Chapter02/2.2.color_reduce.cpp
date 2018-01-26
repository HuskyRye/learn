/*
	Date: 2018.1.26
	Author: Áõ³¼Ðù
*/

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

void colorReduce(cv::Mat &image, int div = 64)
{
	int lines = image.rows;
	int channels = image.cols*image.channels();
	for (int i = 0; i < lines; ++i) {
		// get the address of row i
		uchar* data = image.ptr<uchar>(i);
		for (int j = 0; j < channels; ++j) {
			// process each pixel
			data[j] = data[j]/div*div + div/2;
		}
	}
}

int main()
{
	cv::Mat image = cv::imread("boldt.jpg");

	// clone the image
	cv::Mat clone = image.clone();

	colorReduce(clone);
	cv::imwrite("color_reduce.jpg", clone);
	return 0;
}