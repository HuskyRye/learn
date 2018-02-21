/*
	Date: 2018.2.21
	Author: 刘臣轩
*/

#pragma once

#include "1_ColorDetector.h"

class ColorDetectController {
public:
    // Sets the color distance threshold.
    // Threshold must be positive,
    // otherwise distance threshold is set to 0.
    void setColorDistanceThreshold(int distance)
    {
        cd->setColorDistanceThreshold(distance);
    }

    // Gets the color distance threshold
    int colorDistanceThreshold() const
    {
        return cd->colorDistanceThreshold();
    }

    // Sets the color to be detected
    void setTargetColor(uchar red, uchar green, uchar blue)
    {
        cd->setTargetColor(red, green, blue);
    }

    // Sets the color to be detected
    void setTargetColor(cv::Vec3b color)
    {
        cd->setTargetColor(color);
    }

    // Gets the color to be detected
    void TargetColor(uchar& red, uchar& green, uchar& blue) const
    {
        cv::Vec3b color = cd->TargetColor();
        // BGR
        red = color[2];
        green = color[1];
        blue = color[0];
    }

    // Sets the input image. Reads it from file.
    bool setInputImage(std::string filename)
    {
        image = cv::imread(filename);
        return image.data;
    }

    // Returns the current input image.
    const cv::Mat inputImage() const
    {
        return image;
    }

    // Performs image processing.
    void process()
    {
        result = cd->process(image);
    }

    // Returns the image result from the latest processing.
    const cv::Mat lastResult() const
    {
        return result;
    }

    // Deletes processor objects created by the controller
    ~ColorDetectController()
    {
        delete cd;
    }

    // Singleton static members
    static ColorDetectController* instance()
    {
        if (singleton == nullptr)
            singleton = new ColorDetectController;
        return singleton;
    }

    // Release the singlton instance of this controller.
    static void destroy()
    {
        if (singleton != nullptr) {
            delete singleton;
            singleton = nullptr;
        }
    }

private:
    static ColorDetectController* singleton;
    ColorDetector* cd;
    // private constructor
    ColorDetectController()
    {
        cd = new ColorDetector();
    }
    cv::Mat image;
    cv::Mat result;
};
