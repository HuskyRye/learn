/*
	Date: 2018.3.3
	Author: 刘臣轩
*/

#include <iostream>
#include <opencv2/opencv.hpp>

void onMouse(int event, int x, int y, int flags, void* param);

int main()
{
    // read an image
    // cv::imread(const cv::String &filename, optional int flags = IMREAD_COLOR)
    cv::Mat image = cv::imread("../tiger.jpg"); // cv::IMREAD_COLOR, cv::IMREAD_GRAYSCALE
    // std::cout << image.size().width << " x " << image.size().height << std::endl;
    std::cout << image.cols << " x " << image.rows << std::endl;
    if (image.empty()) {
        std::cout << "Failed to open the image" << std::endl;
        return 1;
    }

    // create image window
    cv::namedWindow("Hello OpenCV");
    // show the image on window
    cv::imshow("Hello OpenCV", image);

    // set the mouse callback for this image
    cv::setMouseCallback("Hello OpenCV", onMouse, reinterpret_cast<void*>(&image));

    cv::waitKey();

    cv::Mat result;
    // flip the imag, flip code: positive, zero, negative
    cv::flip(image, result, 1);
    cv::namedWindow("Output Image");
    cv::imshow("Output Image", result);
    // save the image
    cv::imwrite("../result.jpg", result);
    // wait key for 3s
    cv::waitKey(3000);

    cv::namedWindow("Drawing on an image");
    // cv::circle(cv::InputOutputArray img, cv::Point center, int radius, const cv::Scalar &color, optional int thickness = 1, optional int lineType = LINE_8, optional int shift = 0)
    cv::circle(image, cv::Point(240, 150), 75, 0, 3);
    // cv::putText(cv::InputOutputArray img, const cv::String &text, cv::Point org, int fontFace, double fontScale, cv::Scalar color, optional int thickness = 1, optional int lineType = LINE_8, optional bool bottomLeftOrigin = false)
    cv::putText(image, "This is a tiger.", cv::Point(130, 250), cv::FONT_HERSHEY_PLAIN, 2.0, cv::Scalar(255, 255, 255), 2);
    cv::imshow("Drawing on an image", image); // show the image
    cv::waitKey();

    return 0;
}

void onMouse(int event, int x, int y, int flags, void* param)
{
    cv::Mat* im = reinterpret_cast<cv::Mat*>(param);
    switch (event) {
    case cv::EVENT_FLAG_LBUTTON:
        if (im->channels() == 1) {
            std::cout << "GRAY value at (" << x << ", " << y << ") is: "
                      << static_cast<int>(im->at<unsigned char>(cv::Point(x, y))) << std::endl;
        } else if (im->channels() == 3) {
            std::cout << "BGR value at (" << x << ", " << y << ") is: "
                      << static_cast<int>(im->at<cv::Vec3b>(cv::Point(x, y))[0]) << ", "
                      << static_cast<int>(im->at<cv::Vec3b>(cv::Point(x, y))[1]) << ", "
                      << static_cast<int>(im->at<cv::Vec3b>(cv::Point(x, y))[2]) << std::endl;
        }
        break;
    }
}
