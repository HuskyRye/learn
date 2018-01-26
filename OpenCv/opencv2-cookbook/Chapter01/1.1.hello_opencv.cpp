/*
	Date: 2018.1.20
	Author: 刘臣轩
*/

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;

int main() {
	// read an image
	cv::Mat image = cv::imread("tiger.jpg");
	// cout << image.size().height << ", " << image.size().width << endl;

	// create image window
	cv::namedWindow("My First OpenCv programe");
	// show the image on window
	cv::imshow("My First OpenCv programe", image);
	// wait key for 5s
	cv::waitKey(5000);

	cv::Mat result;
	// flip the imag: positive, 0, negative
	cv::flip(image, result, 1);
	cv::namedWindow("Output Image");
	cv::imshow("Output Image", result);
	// save the image
	cv::imwrite("result.jpg", result);
	cv::waitKey(5000);
	return 0;
}

