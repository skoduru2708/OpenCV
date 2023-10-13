#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

/// Basic Imag Functions - Resize and Crop/////

int main()
{
    string img_path = "../../Resources/mountain.jpg";

    Mat img, img_resize, img_region_of_interest;

    img = imread(img_path);

    // Resize
    resize(img, img_resize, Size(), 0.5, 0.5);

    // Crop for ROI
    Rect roi(100, 100, 200, 200);
    img_region_of_interest = img(roi);

    imshow("Image", img);
    imshow("Image Resized", img_resize);
    imshow("Image ROI", img_region_of_interest);

    waitKey(0);
    return 0;
}