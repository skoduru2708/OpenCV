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

    Mat img, img_gray, img_blur, img_canny, img_dilation;
    img = imread(img_path);

    cvtColor(img, img_gray, COLOR_BGR2GRAY);
    GaussianBlur(img, img_blur, Size(3, 3), 3, 0);
    Canny(img_blur, img_canny, 25, 75);

    Mat kernal = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(img_canny, img_dilation, kernal);

    imshow("Image", img);
    imshow("Gray Image", img_gray);
    imshow("Blur Image", img_blur);
    imshow("Canny Image", img_canny);
    imshow("Dilate Image", img_dilation);

    waitKey(0);
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