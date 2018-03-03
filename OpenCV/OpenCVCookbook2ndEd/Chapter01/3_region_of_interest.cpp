/*
	Date: 2018.3.3
	Author: 刘臣轩
*/

#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat image = cv::imread("../boldt.jpg");
    cv::Mat logo = cv::imread("../logo.bmp");

    // define image region of interest
    cv::Mat imageROI(image, cv::Rect(image.cols - logo.cols, image.rows - logo.rows, logo.cols, logo.rows));

    // logo.copyTo(imageROI);

    // saturation
    // imageROI += 0.5 * logo;

    // mask must be gray-level
    cv::Mat mask = cv::imread("../logo.bmp", cv::IMREAD_GRAYSCALE);
    logo.copyTo(imageROI, mask);

    cv::namedWindow("Region of interest");
    cv::imshow("Region of interest", image);
    cv::imwrite("../region_of_interest.jpg", image);
    cv::waitKey();
    return 0;
}
