/*
	Date: 2018.1.30
	Author: 刘臣轩
*/

#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat image = cv::imread("boldt.jpg");
	cv::Mat logo = cv::imread("logo.bmp");

	// define image region of interest
	cv::Mat imageROI = image(cv::Rect(image.cols-logo.cols, image.rows-logo.rows, logo.cols, logo.rows));
	// ROI can be defined from two ranges
	//imageROI = image(cv::Range(image.rows-logo.rows, image.rows), cv::Range(image.cols-logo.cols, image.cols));

	// possibly saturation
	// imageROI += 0.5*logo;

	// mask must be gray-level
	cv::Mat mask = cv::imread("logo.bmp", 0);
	logo.copyTo(imageROI, mask);

	cv::namedWindow("Region of interest");
	cv::imshow("Region of interest", image);
	cv::imwrite("Region_of_interest_mask.jpg", image);
	cv::waitKey(5000);
	return 0;
}
