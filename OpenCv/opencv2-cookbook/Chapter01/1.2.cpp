/*
	Date: 2018.1.21
	Author: 刘臣轩
*/

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;

int main(int argc, char *argv[]) {
	if (argc != 3) {
		cout << "Usage: flip_image ImageToFlip PathToSave";
		return -1;
	}
	cv::Mat image = cv::imread(argv[1]);
	if (image.empty()) {
		cout << "Could not open or find " << argv[1];
		return -1;
	}
	cv::Mat result;
	cv::flip(image, result, 1);
	cv::imwrite(argv[2], result);
	return 0;
}