#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

/// Draw shapes and text /////

int main()
{
    /*Blank Image*/
    Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));
    circle(img, Point(256, 256), 155, Scalar(0, 70, 210), FILLED);
    rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);
    line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);
    putText(img, "Om Jai Saibaba", Point(27, 262), FONT_HERSHEY_SCRIPT_COMPLEX, 2, Scalar(255, 0, 0), 2);
    imshow("Image", img);

    waitKey(0);
    return 0;
}