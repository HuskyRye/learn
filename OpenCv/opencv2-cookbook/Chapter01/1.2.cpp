/*
	Date: 2018.1.21
	Author: 刘臣轩
*/

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;

int main(int argc, char *argv[]) {
	if (argc != 3) {
		cout << "usage: flip.exe source.jpg result.jpg";
		return 1;
	}
	cv::Mat image = cv::imread(argv[1]);
	if (image.data == NULL) {
		cout << "fail to open " << argv[1];
		return 2;
	}
	cv::Mat result;
	cv::flip(image, result, 1);
	cv::imwrite(argv[2], result);
}