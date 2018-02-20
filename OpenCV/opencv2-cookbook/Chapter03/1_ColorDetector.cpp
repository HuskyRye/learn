#include "1_ColorDetector.h"

cv::Mat ColorDetector::process(const cv::Mat& image)
{
    // re-allocate binary map if necessary
    result.create(image.rows, image.cols, CV_8U);

    // get the iterators
    cv::Mat_<cv::Vec3b>::const_iterator begin = image.begin<cv::Vec3b>();
    cv::Mat_<cv::Vec3b>::const_iterator end = image.end<cv::Vec3b>();
    cv::Mat_<uchar>::iterator iter = result.begin<uchar>();

    // for each pixel
    for (; begin != end; ++begin, ++iter)
		*iter = getDistance(*begin) < minDist ? 255 : 0;

    return result;
}
