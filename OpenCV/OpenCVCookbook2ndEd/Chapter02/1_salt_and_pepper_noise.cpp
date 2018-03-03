/*
	Date: 2018.3.3
	Author: 刘臣轩
*/

#include <iostream>
#include <opencv2/opencv.hpp>

void salt(cv::Mat& image, int n)
{
    for (int k = 0; k < n; ++k) {
        int i = std::rand() % image.cols; // column-列
        int j = std::rand() % image.rows; // row-行
        if (image.channels() == 1) {
            image.at<uchar>(j, i) = 255; // unsined char
        } else if (image.channels() == 3) {
            image.at<cv::Vec3b>(j, i)[0] = 255; // Vec<unsined char, 3>
            image.at<cv::Vec3b>(j, i)[1] = 255;
            image.at<cv::Vec3b>(j, i)[2] = 255;
        }
    }
}

int main()
{
    cv::Mat image = cv::imread("../boldt.jpg");
    salt(image, 3000);
    cv::imwrite("../salt_and_pepper_noise.jpg", image);
    return 0;
}
