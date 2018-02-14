/*
	Date: 2018.1.30
	Author: 刘臣轩
*/

#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat image1 = cv::imread("boldt.jpg");
	cv::Mat image2 = cv::imread("rain.jpg");
	cv::Mat result;
	// cv::addWeighted(image1, 0.7, image2, 0.9, 0, result);
	// dst = src1*alpha + src2*beta + gamma;
	result = 0.7*image1+0.9*image2;
	cv::namedWindow("add images");
	cv::imshow("add images", result);
	cv::imwrite("add_images.jpg", result);
	cv::waitKey(5000);
	return 0;
}
