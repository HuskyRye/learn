/*
	Date: 2018.2.20
	Author: 刘臣轩
*/

#include "1_ColorDetector.h"

cv::Mat ColorDetector::process(const cv::Mat& image)
{

    // re-allocate binary map if necessary
    result.create(image.size(), CV_8U);

    // get the iterators
    cv::Mat_<cv::Vec3b>::const_iterator begin = image.begin<cv::Vec3b>();
    cv::Mat_<cv::Vec3b>::const_iterator end = image.end<cv::Vec3b>();
    cv::Mat_<uchar>::iterator iter = result.begin<uchar>();

    // for each pixel
    for (; begin != end; ++begin, ++iter)
        *iter = getDistance(*begin) < minDist ? 255 : 0;

    /*
	cv::absdiff(image, cv::Scalar{ target }, result);
	std::vector<cv::Mat> images;
	cv::split(result, images);
	result = images[0] + images[1] + images[2];
	cv::threshold(result, result, minDist, 255, cv::THRESH_BINARY_INV);
	*/

    return result;
}
