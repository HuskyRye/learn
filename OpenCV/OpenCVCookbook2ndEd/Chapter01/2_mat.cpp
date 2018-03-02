/*
    Date: 2018.3.3
    Author: 刘臣轩
*/

#include <iostream>
#include <opencv2/opencv.hpp>

// test function that creates an image
cv::Mat function()
{
    cv::Mat ima(500, 500, CV_8U, 50);
    return ima;
}

int main()
{
    cv::namedWindow("Image");

    cv::Mat image1(240, 320, CV_8U, 100);
    // cv::Mat image1(240,320,CV_8U,cv::Scalar(100));
    cv::imshow("Image", image1);
    cv::waitKey(0);

    // re-allocate a new image
    // (only if size or type are different)
    image1.create(200, 200, CV_8U);
    image1 = 200;
    cv::imshow("Image", image1);
    cv::waitKey(0);

    // cv::Scalar(int blue, int green, int red)
    cv::Mat image2(240, 320, CV_8UC3, cv::Scalar(0, 0, 255));
    // cv::Mat image2(cv::Size(320,240),CV_8UC3);
    // image2= cv::Scalar(0,0,255);
    cv::imshow("Image", image2);
    cv::waitKey(0);

    cv::Mat image3 = cv::imread("../tiger.jpg");
    image1 = image3;
    image3.copyTo(image2);
    cv::Mat image4(image3);
    cv::Mat image5 = image3.clone();

    cv::flip(image3, image3, 1); // l -> r
    cv::imshow("Image 1", image1); // r
    cv::imshow("Image 2", image2); // l
    cv::imshow("Image 3", image3); // r
    cv::imshow("Image 4", image4); // r
    cv::imshow("Image 5", image5); // l
    cv::waitKey(0);

    cv::Mat gray = function();
    cv::imshow("Image", gray);
    cv::waitKey(0);

    image1 = cv::imread("../tiger.jpg", CV_LOAD_IMAGE_GRAYSCALE);
    // convert the image into a floating point image [0,1]
    image1.convertTo(image2, CV_32F, 1.0 / 255.0, 0.0);
    cv::imshow("Image", image2);
    cv::waitKey(0);

    return 0;
}
