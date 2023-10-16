#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

/// Color detection /////
int main(int Args, char *Arguments[], char *Env[])
{
    int Index = 0;
    cout << "SK Debug: Start" << endl;
    while (Env[Index] != NULL)
    {
        cout << Env[Index] << endl;
        Index++;
    }
    cout << "SK Debug: End" << endl;
    string img_path = "../../Resources/lambo.png";
    int hmin = 0, smin = 110, vmin = 153;
    int hmax = 19, smax = 240, vmax = 255;
    Mat img, img_HSV, img_mask;
    Scalar lower(hmin, smin, vmin);
    Scalar upper(hmax, smax, vmax);

    img = imread(img_path);
    cvtColor(img, img_HSV, COLOR_BGR2HSV);

    inRange(img_HSV, lower, upper, img_mask);

    imshow("Image", img);
    imshow("HSV Image", img_HSV);
    imshow("Masked Image", img_mask);
    waitKey(0);
    return 0;
}