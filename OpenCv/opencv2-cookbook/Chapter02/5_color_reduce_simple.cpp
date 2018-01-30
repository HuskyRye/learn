/*
	Date: 2018.1.30
	Author: 刘臣轩
*/

#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat image = cv::imread("boldt.jpg");
	cv::Mat result;
	const int div = 128;
	int n = log(div)/log(2);
	uchar mask = 0xFF<<n;
	result = (image&cv::Scalar(mask, mask, mask)) + cv::Scalar(div/2, div/2, div/2);
	cv::namedWindow("Color Reduce");
	cv::imshow("Color Reduce", result);
	cv::waitKey(5000);
	return 0;
}