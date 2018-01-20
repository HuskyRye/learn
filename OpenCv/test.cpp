/*
	Date: 2018.1.20
	Author: 刘臣轩
*/

#include <opencv2/opencv.hpp>
using namespace std;

int main() {
	const char* ImageName = "avatar.jpg";
	const char* WindowsTitle = "My first OpenCv programe";

	// 读取图象
	IplImage* Image = cvLoadImage(ImageName, CV_LOAD_IMAGE_UNCHANGED);

	// 创建窗口
	cvNamedWindow(WindowsTitle);

	// 在指定窗口显示图片
	cvShowImage(WindowsTitle, Image);

	// 等待按钮事件
	cvWaitKey();

	cvDestroyWindow(WindowsTitle);
	cvReleaseImage(&Image);
	return 0;
}

