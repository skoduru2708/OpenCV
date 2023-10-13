#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

//////// Warp Imags //////////

/*int main()
{
    float w = 270, h = 350;
    Mat img, imgWarp, matrix;
    string img_path = "../../Resources/cards.jpg";
    img = imread(img_path);

    Point2f src[4] = {{529, 142}, {771, 190}, {405, 395}, {674, 457}};
    Point2f dest[4] = {{0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h}};

    matrix = getPerspectiveTransform(src, dest);
    warpPerspective(img, imgWarp, matrix, Point(w, h));

    imshow("Image", img);
    imshow("Image Warp", imgWarp);
    waitKey(0);
    return 0;
}*/

int main()
{
    float w = 270, h = 350;
    Mat img, imgWarp, matrix;
    string img_path = "../../Resources/cards.jpg";
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
