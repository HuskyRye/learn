/*
	Date: 2018.1.27
	Author: 刘臣轩
*/

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

// using at and []
void colorReduce0(cv::Mat& image, int div = 64)
{
	int line = image.rows;
	int columns = image.cols;
	for (int i = 0; i < line; ++i) {
		for (int j = 0; j < columns; ++j) {
			image.at<cv::Vec3b>(i, j)[0] =
				image.at<cv::Vec3b>(i, j)[0]/div*div + div/2;
			image.at<cv::Vec3b>(i, j)[1] =
				image.at<cv::Vec3b>(i, j)[1]/div*div + div/2;
			image.at<cv::Vec3b>(i, j)[2] =
				image.at<cv::Vec3b>(i, j)[2]/div*div + div/2;
		}
	}
}

// using .ptr and []
void colorReduce1(cv::Mat& image, int div = 64)
{
	int lines = image.rows;
	int channels = image.cols*image.channels();
	for (int i = 0; i < lines; ++i) {
		// get the address of row i
		uchar* data = image.ptr<uchar>(i);
		for (int j = 0; j < channels; ++j) {
			// process each pixel
			data[j] = data[j]/div*div + div/2;
		}
	}
}

// with input/ouput images
void colorReduce2(const cv::Mat& image, cv::Mat& result, int div = 64)
{
	// allocate output image if necessary
	result.create(image.rows, image.cols, image.type());
	int lines = image.rows;
	int channels = image.cols*image.channels();

	// no padded pixels
	if (image.isContinuous()) {
		channels = lines * channels;
		lines = 1;
	}

	for (int i = 0; i < lines; ++i) {
		// get the address of row i
		const uchar* data_in = image.ptr<uchar>(i);
		uchar* date_out = result.ptr<uchar>(i);
		for (int j = 0; j < channels; ++j) {
			// process each pixel
			date_out[j] = data_in[j]/div*div + div/2;
		}
	}
}

// using iterator
void colorReduce3(const cv::Mat& image, cv::Mat& result, int div = 64)
{
	// allocate output image if necessary
	result.create(image.rows, image.cols, image.type());
	// obtain const iterator at initial position
	cv::MatConstIterator_<cv::Vec3b> begin = image.begin<cv::Vec3b>();
	// obtain end position
	cv::MatConstIterator_<cv::Vec3b> end = image.end<cv::Vec3b>();
	// obtain iterator at initial position
	cv::MatIterator_<cv::Vec3b> iter = result.begin<cv::Vec3b>();
	for (; begin != end; ++begin, ++iter) {
		(*iter)[0] = (*begin)[0]/div*div+div/2;
		(*iter)[1] = (*begin)[1]/div*div+div/2;
		(*iter)[2] = (*begin)[2]/div*div+div/2;
	}
}

void colorReduce(cv::Mat& image, int div = 64)
{
	int rows = image.rows;
	int cols = image.cols;
	if (image.isContinuous()) {
		cols = cols * rows;
		rows = 1;
	}
	int n = log(div)/log(2);
	// mask used to round the pixel value
	uchar mask = 0xFF<<n;	// e.g. for div = 16, mask = 0xF0
	for (int i = 0; i < rows; ++i) {
		uchar* data = image.ptr<uchar>(i);
		for (int j = 0; j < cols; ++j) {
			*data = (*data&mask) + div/2;
			data++;
			*data = (*data&mask) + div/2;
			data++;
			*data = (*data&mask) + div/2;
			data++;
			/*
			Dangerous, not recommended
			*data++ = *data&mask + div/2;
			*/
		}
	}
}

int main()
{
	cv::Mat image = cv::imread("boldt.jpg");
	colorReduce0(image, 16);
	cv::namedWindow("Color reduce 0");
	cv::imshow("Color reduce 0", image);

	image = cv::imread("boldt.jpg");
	colorReduce1(image, 32);
	cv::namedWindow("Color reduce 1");
	cv::imshow("Color reduce 1", image);

	image = cv::imread("boldt.jpg");
	cv::Mat result;
	colorReduce2(image, result);
	cv::namedWindow("Color reduce 2");
	cv::imshow("Color reduce 2", result);

	colorReduce3(image, result, 128);
	cv::namedWindow("Color reduce 3");
	cv::imshow("Color reduce 3", result);

	image = cv::imread("boldt.jpg");
	colorReduce(image, 128);
	cv::namedWindow("Color reduce");
	cv::imshow("Color reduce", image);
	cv::imwrite("color_reduce.jpg", image);

	cv::waitKey(10000);
	return 0;
}
