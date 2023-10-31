#include <iostream>
#include <pthread.h>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

/// Color detection /////
int main(int Args, char *Arguments[], char *Env[])
{

    string img_path = "/Users/srinivas.koduru/Dev/opencv/learn/test/OpenCV/Resources/";
    img_path += "shapes.png";

    bool contd = true;

    int hmin = 0, smin = 0, vmin = 0;
    int hmax = 179, smax = 240, vmax = 255;

    Mat img, img_HSV, img_mask;

    img = imread(img_path);
    cvtColor(img, img_HSV, COLOR_BGR2HSV);

    namedWindow("Trackbars", 1);
    createTrackbar("Hue Min", "Trackbars", &hmin, 179);
    createTrackbar("Hue Max", "Trackbars", &hmax, 179);
    createTrackbar("Sat Min", "Trackbars", &smin, 255);
    createTrackbar("Sat Max", "Trackbars", &smax, 255);
    createTrackbar("Val Min", "Trackbars", &vmin, 255);
    createTrackbar("Val Max", "Trackbars", &vmax, 255);

    while (contd)
    {
        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);
        inRange(img_HSV, lower, upper, img_mask);

        imshow("Image", img);
        imshow("HSV Image", img_HSV);
        imshow("Masked Image", img_mask);
        waitKey(2);
    }

    return 0;
}