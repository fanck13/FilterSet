#include "PicturePanelWidget.h"
#include <QLabel>
#include <QMessageBox>



//#include "opencv2/opencv.hpp"

PicturePanelWidget::PicturePanelWidget(QWidget *parent) : QWidget(parent)
{
    QLabel* pictureLabel = new QLabel(this);

    pictureLabel->setPixmap(QPixmap::fromImage(*reader.getPicture()));
}

PicturePanelWidget::~PicturePanelWidget()
{

}

void PicturePanelWidget::updatePicture(const QString& filePath )
{
    QMessageBox::information(this, tr("Test"), filePath);
}
