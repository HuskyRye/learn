/*
	Date: 2018.1.30
	Author: 刘臣轩
*/

#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat image1 = cv::imread("../boldt.jpg");
    cv::Mat image2 = cv::imread("../rain.jpg", 0);
    cv::Mat result;
    std::vector<cv::Mat> planes;
    // split a 3-channel image into three 1-channel imgaes
    cv::split(image1, planes);
    // add to green channel (BGR)
    planes[1] += image2;
    // merge the three 1-channel images into a 3-channel image
    cv::merge(planes, result);
    cv::namedWindow("Split Channels");
    cv::imshow("Split Channels", result);
    cv::imwrite("../split_channels.jpg", result);
    cv::waitKey();
    return 0;
}
