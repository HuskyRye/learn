/*
	Date: 2018.2.20
	Author: 刘臣轩
*/

#include "1_ColorDetector.h"
#include <iostream>

int main()
{
    // create image processor object
    ColorDetector cd(230, 190, 130);

    cv::Mat image = cv::imread("../boldt.jpg");
    cv::namedWindow("boldt");
    cv::imshow("boldt", image);

    cv::namedWindow("Color Detector");
    cv::Mat result = cd.process(image);
    cv::imshow("Color Detector", result);
    cv::imwrite("../color_detector.jpg", result);

    cv::waitKey();
    return 0;
}
