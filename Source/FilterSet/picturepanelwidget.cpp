#include "picturepanelwidget.h"
#include <QLabel>
#include <QMessageBox>

#include "opencv2/opencv.hpp"

PicturePanelWidget::PicturePanelWidget(QWidget *parent) : QWidget(parent)
{
    QLabel* pictureLabel = new QLabel(this);

    //QImage *image= new QImage();
    //pictureLabel->setPixmap(QPixmap::fromImage(*image));

    cv::Mat src = cv::imread("D:\\FilterSet\\TestData\\elephants.jpg");
    cv::Mat img;
    cvtColor(src, img, cv::COLOR_BGR2RGB);
    pictureLabel->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888)));
}

PicturePanelWidget::~PicturePanelWidget()
{

}

void PicturePanelWidget::updatePicture(const QString& filePath )
{
    QMessageBox::information(this, tr("Test"), filePath);
}
