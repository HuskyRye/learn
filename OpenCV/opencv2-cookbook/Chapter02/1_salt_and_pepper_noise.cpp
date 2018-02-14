/*
	Date: 2018.1.26
	Author: 刘臣轩
*/

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

void salt(cv::Mat& image, int n)
{
	for (int k = 0; k < n; ++k) {
		int i = rand()%image.rows;		// row-行
		int j = rand()%image.cols;		// column-列

		// gray-level image
		if (image.channels() == 1) {
			image.at<uchar>(i, j) = 255;		// unsined char
		}
		// color image
		else if (image.channels() == 3) {
			image.at<cv::Vec3b>(i, j)[0] = 255;	// Vec<unsined char, 3>
			image.at<cv::Vec3b>(i, j)[1] = 255;
			image.at<cv::Vec3b>(i, j)[2] = 255;
		}
	}
}

int main()
{
	cv::Mat image = cv::imread("boldt.jpg");
	salt(image, 3000);
	cv::imwrite("result.jpg", image);
	return 0;
}
