/*
	Date: 2018.2.20
	Author: 刘臣轩
*/

#pragma once

#include <opencv2/opencv.hpp>

class ColorDetector {
public:
    ColorDetector()
        : minDist{ 100 }
    {
        target[0] = target[1] = target[2] = 0;
    }

    // Processes the image, returns a 1-channel binary image.
    cv::Mat process(const cv::Mat& image);

    // Sets the color distance threshold.
    // Threshold must be positive,
    // otherwise distance threshold is set to 0.
    void setColorDistanceThreshold(int distance)
    {
        minDist = (distance < 0 ? 0 : distance);
    }

    // Gets the color distance threshold
    int colorDistanceThreshold() const
    {
        return minDist;
    }

    // Sets the color to be detected
    void setTargetColor(uchar red, uchar green, uchar blue)
    {
        // BGR
        target[2] = red;
        target[1] = green;
        target[0] = blue;
    }

    // Sets the color to be detected
    void setTargetColor(cv::Vec3b color)
    {
        target = color;
    }

    // Gets the color to be detected
    cv::Vec3b TargetColor() const
    {
        return target;
    }

private:
    // minimum acceptable distance
    int minDist;

    // target color
    cv::Vec3b target;

    // image containing resulting binary map
    cv::Mat result;

    // Computes the city block distance from target color.
    int getDistance(const cv::Vec3b& color) const
    {
        // Euclidean norm 欧式距离
        // return static_cast<int>(cv::norm<int, 3>(cv::Vec3i{ color[0] - target[0], color[1] - target[1], color[2] - target[2] }));
        return abs(color[0] - target[0])
            + abs(color[1] - target[1])
            + abs(color[2] - target[2]);
    }
};
