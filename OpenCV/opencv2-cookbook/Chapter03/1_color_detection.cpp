#include "1_ColorDetector.h"
#include <iostream>

int main()
{
	// create image processor object
	ColorDetector cd;
	cd.setTargetColor(130, 190, 230);

	cv::Mat image = cv::imread("../boldt.jpg");
	cv::namedWindow("boldt");
	cv::imshow("boldt", image);

	cv::namedWindow("result");
	cv::imshow("result", cd.process(image));

	cv::waitKey(5000);
	return 0;
}
