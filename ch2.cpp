#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

/// Basic Imag Functions /////

int main()
{
    string img_path = "../Resources/mountain.jpg";
    Mat img = imread(img_path);
    Mat img_gray, img_blur, img_canny, img_dilation, img_erode;

    cvtColor(img, img_gray, COLOR_BGR2GRAY);
    GaussianBlur(img, img_blur, Size(3, 3), 3, 0);
    Canny(img_blur, img_canny, 25, 75);

    Mat kernal = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(img_canny, img_dilation, kernal);
    erode(img_dilation, img_erode, kernal);

    imshow("Image", img);
    imshow("Gray Image", img_gray);
    imshow("Blur Image", img_blur);
    imshow("Canny Image", img_canny);
    imshow("Dilate Image", img_dilation);
    imshow("Erode Image", img_erode);

    waitKey(0);
    return 0;
}