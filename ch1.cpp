#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

/// Imags /////

/*int main() {
    string img_path = "Resources/mountain.jpg";
    Mat img = imread(img_path);
    imshow("Image", img);
    waitKey(0);
    return 0;
}*/

/* we are working on the video */

/*int main() {
    string video_path = "Resources/test_video.mp4";
    VideoCapture video_capture(video_path);
    Mat img;

    while (true) {
        video_capture.read(img);
        imshow("Showing Video", img);
        waitKey(20);

    }
    return 0;
}*/

/* we are working on the webcam */

int main()
{
    VideoCapture video_capture(0);
    Mat img;

    while (true)
    {
        video_capture.read(img);
        imshow("Showing Video", img);
        waitKey(20);
    }
    return 0;
}