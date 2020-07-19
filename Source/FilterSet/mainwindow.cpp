#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLabel* pictureLabel = new QLabel(ui->centralwidget);

    QImage *image= new QImage("D:\\FilterSet\\TestData\\elephants.jpg");
    pictureLabel->setPixmap(QPixmap::fromImage(*image));
}



MainWindow::~MainWindow()
{
    delete ui;
}

