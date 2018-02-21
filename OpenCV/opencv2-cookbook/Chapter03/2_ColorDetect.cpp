/*
	Date: 2018.2.21
	Author: 刘臣轩
*/

#include "2_ColorDetectController.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string filename;
    cin >> filename;
    ColorDetectController cdc;
    if (!cdc.setInputImage(filename)) {
        cout << "Can't find image!\n";
        return 1;
    }
    cv::imshow("Input Image", cdc.inputImage());
    cdc.setTargetColor(130, 190, 230);
    cdc.process();
    cv::imshow("Output Image", cdc.lastResult());
    cv::waitKey(5000);
    return 0;
}
