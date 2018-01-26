/*
	Date: 2018.1.26
	Author: Áõ³¼Ðù
*/

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

void colorReduce(const cv::Mat& image, cv::Mat& result, int div = 64)
{
	result.create(image.rows, image.cols, image.type());
	int lines = image.rows;
	int channels = image.cols*image.channels();
	for (int i = 0; i < lines; ++i) {
		// get the address of row i
		const uchar* data_in = image.ptr<uchar>(i);
		uchar* date_out = result.ptr<uchar>(i);
		for (int j = 0; j < channels; ++j) {
			// process each pixel
			date_out[j] = data_in[j]/div*div + div/2;
		}
	}
}

int main()
{
	cv::Mat image = cv::imread("boldt.jpg");
	cv::Mat result;
	colorReduce(image, result);
	cv::namedWindow("Color reduce");
	cv::imshow("Color reduce", result);
	cv::waitKey(5000);
	return 0;
}