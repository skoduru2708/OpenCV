#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#ifdef _WIN32
#include <windows.h>
#elif __APPLE__ || __MACH__
// include Apple related
#endif

using namespace cv;
using namespace std;

string getOsName();

/// Color detection /////
int main(int Args, char *Arguments[], char *Env[])
{
    string os_name = getOsName();

    string img_path;
    img_path = (os_name == "MacOSX") ? "/Users/srinivas.koduru/Dev/opencv/learn/test/OpenCV/Resources/" : "../../Resources/";
    img_path += "/shapes.png";

    int hmin = 0, smin = 0, vmin = 0;
    int hmax = 179, smax = 240, vmax = 255;

    bool cont = true;

    Mat img, img_HSV, img_mask;

    img = imread(img_path);
    cvtColor(img, img_HSV, COLOR_BGR2HSV);

    namedWindow("Trackbars", (640, 200));
    createTrackbar("Hue Min", "Trackbars", &hmin, 179);
    createTrackbar("Hue Max", "Trackbars", &hmax, 179);
    createTrackbar("Sat Min", "Trackbars", &smin, 255);
    createTrackbar("Sat Max", "Trackbars", &smax, 255);
    createTrackbar("Val Min", "Trackbars", &vmin, 255);
    createTrackbar("Val Max", "Trackbars", &vmax, 255);

    while (cont)
    {
        if (GetKeyState(VK_ESCAPE) & 0x8000)
            cont = false;

        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);
        inRange(img_HSV, lower, upper, img_mask);

        imshow("Image", img);
        imshow("HSV Image", img_HSV);
        imshow("Masked Image", img_mask);
        waitKey(1);
    }
    return 0;
}

string getOsName()
{
#ifdef _WIN32
    return "Win";
#elif _WIN64
    return "Win";
#elif __APPLE__ || __MACH__
    return "MacOSX";
#elif __linux__
    return "Linux";
#elif __FreeBSD__
    return "FreeBSD";
#elif __unix || __unix__
    return "Unix";
#else
    return "Other";
#endif
}