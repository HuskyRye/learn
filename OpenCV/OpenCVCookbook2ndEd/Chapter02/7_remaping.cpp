/*
	Date: 2018.3.6
	Author: 刘臣轩
*/

#include <iostream>
#include <opencv2/opencv.hpp>

void wave(const cv::Mat& image, cv::Mat& result)
{
    // the map functions
    cv::Mat srcX(image.rows, image.cols, CV_32F);
    cv::Mat srcY(image.rows, image.cols, CV_32F);

    // creating the mapping
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            srcX.at<float>(i, j) = j;
            srcY.at<float>(i, j) = i + 5 * sin(j / 10.0);
        }
    }

    // applying the mapping
    cv::remap(image, result, srcX, srcY, cv::INTER_LINEAR);
}

int main()
{
    cv::Mat image = cv::imread("../boldt.jpg");
    cv::Mat result;
    wave(image, result);
    cv::namedWindow("Remaping");
    cv::imshow("Remaping", result);
    cv::imwrite("../remaping.jpg", result);
    cv::waitKey();
    return 0;
}
