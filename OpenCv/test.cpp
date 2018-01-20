/*
	Date: 2018.1.20
	Author: 刘臣轩
*/

#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
	// read an image
	Mat image = imread("avatar.jpg");
	// create image window
	namedWindow("My First OpenCv programe");
	// show the image on window
	imshow("My First OpenCv programe", image);
	waitKey(5000);
	return 0;
}

