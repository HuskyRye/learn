/*
	Date: 2018.1.27
	Author: 刘臣轩
*/

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;

void sharpen(const cv::Mat& image, cv::Mat& result)
{
	// allocate if necessary
	result.create(image.size(), image.type());
	// result.create(image.rows, image.cols, image.type());

	for (int i = 1; i < image.rows-1; ++i) {
		const uchar* previous = image.ptr<const uchar>(i-1);	// previous row
		const uchar* current = image.ptr<const uchar>(i);		// current row
		const uchar* next = image.ptr<const uchar>(i+1);		// next row
		uchar* output = result.ptr<uchar>(i);
		for (int j = 1; j < image.cols-1; ++j) {
			output[j] = cv::saturate_cast<uchar>(5*current[j]-current[j-1]-current[j+1]-previous[j]-next[j]);
		}
	}
	// set the unprocess pixels to 0
	result.row(0).setTo(cv::Scalar(0));
	result.row(result.rows-1).setTo(cv::Scalar(0));
	result.col(0).setTo(cv::Scalar(0));
	result.col(result.cols-1).setTo(cv::Scalar(0));
}

int main()
{
	// convert image to the single channel grayscale image
	cv::Mat image = cv::imread("boldt.jpg", 0);
	cv::Mat result;
	sharpen(image, result);
	cv::namedWindow("boldt.jpg");
	cv::imshow("boldt.jpg", image);
	cv::namedWindow("sharpen.jpg");
	cv::imshow("sharpen.jpg", result);
	cv::imwrite("sharpen.jpg", result);
	cv::waitKey(5000);
	return 0;
}