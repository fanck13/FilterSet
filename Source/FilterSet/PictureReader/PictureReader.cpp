#include "PictureReader.h"
#include "opencv2/opencv.hpp"

PictureReader::PictureReader()
{
    //image.reset(new QImage("D:\\FilterSet\\TestData\\elephants.jpg"));

    static cv::Mat src = cv::imread("D:\\FilterSet\\TestData\\elephants.jpg");
    static cv::Mat img;
    cvtColor(src, img, cv::COLOR_BGR2GRAY);

    image.reset(new QImage(img.data, img.cols, img.rows, img.step, QImage::Format_Grayscale8));
}

PictureReader::~PictureReader()
{
}

QImage* PictureReader::getPicture()
{
    return image.get();
}
