#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

//////// Warp Imags //////////

string getOsName();

int main()
{
    string img_path;

    if (getOsName() == "MacOSX")
    {
        img_path = "../Resources/";
    }
    else if (getOsName() == "Win")
    {
        img_path = "../../Resources/";
    }

    img_path += "cards.jpg";

    float w = 270, h = 350;
    Mat img, imgWarp, matrix;

    img = imread(img_path);

    Point2f src[4] = {{736, 381}, {1027, 433}, {643, 714}, {973, 785}};
    Point2f dest[4] = {{0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h}};

    matrix = getPerspectiveTransform(src, dest);
    warpPerspective(img, imgWarp, matrix, Point(w, h));

    imshow("Image", img);
    imshow("Image Warp", imgWarp);
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