#include "3_ColorDetectController.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string filename;
    cin >> filename;
    if (!ColorDetectController::instance()->setInputImage(filename)) {
        cout << "Can't find image!\n";
        return 1;
    }
    cv::imshow("Input Image", ColorDetectController::instance()->inputImage());
    ColorDetectController::instance()->setTargetColor(130, 190, 230);
    ColorDetectController::instance()->process();
    cv::imshow("Output Image", ColorDetectController::instance()->lastResult());
    cv::waitKey(5000);
    ColorDetectController::instance()->destroy();
    return 0;
}
