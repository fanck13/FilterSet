#include "MainWindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPixmap>
#include <QMenu>
#include <QMessageBox>
#include <QToolBar>
#include <QFileDialog>
#include <QStandardPaths>

#include "LineChartView.h"
#include "DataGridView.h"

#include "CommandPrompt.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    picturePanel = new PicturePanelWidget(this);
    this->setCentralWidget(picturePanel);
    this->initActions();
    this->initMenu();
    this->initToolBar();
    this->initStatusBar();
    this->initDockWidgets();
    connect(this, &MainWindow::openFileChosen, picturePanel, &PicturePanelWidget::updatePicture);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMenu()
{
    auto menuBar = this->menuBar();

    auto fileMenu = menuBar->addMenu(tr("&File"));
    auto openAction = actionMap[QString("Open")];
    fileMenu->addAction(openAction);
    auto saveAction = actionMap[QString("Save")];
    fileMenu->addAction(saveAction);

    auto editMenu = menuBar->addMenu(tr("&Edit"));
    auto copyAction = actionMap[QString("Copy")];
    editMenu->addAction(copyAction);
    auto pasteAction = actionMap[QString("Paste")];
    editMenu->addAction(pasteAction);

    auto helpMenu = menuBar->addMenu(tr("&Help"));
    auto aboutAction = actionMap[QString("About")];
    helpMenu->addAction(aboutAction);

    connect(openAction, &QAction::triggered, this, &MainWindow::onActionOpen);
    connect(saveAction, &QAction::triggered, this, &MainWindow::onActionSave);
    connect(copyAction, &QAction::triggered, this, &MainWindow::onActionCopy);
    connect(pasteAction, &QAction::triggered, this, &MainWindow::onActionPaste);
    connect(aboutAction, &QAction::triggered, this, &MainWindow::onActionAbout);
}

void MainWindow::initToolBar()
{
    auto openAction = actionMap[QString("Open")];
    auto saveAction = actionMap[QString("Save")];

    auto openToolBar = this->addToolBar(tr("&Open"));
    openToolBar->addAction(openAction);

    auto saveToolBar = this->addToolBar(tr("&Save"));
    saveToolBar->addAction(saveAction);

    openToolBar->setMovable(true);
}

void MainWindow::initStatusBar()
{
    auto statusLabel = new QLabel(tr("status"));
    this->statusBar()->addWidget(statusLabel);
}

void MainWindow::initActions()
{
    QAction* openAction = new QAction(tr("&Open"), this);
    actionMap.insert(QString("Open"),openAction);
    openAction->setStatusTip(tr("Open a picture."));
    //openAction.setIcon();

    QAction* saveAction = new QAction(tr("&Save"), this);
    actionMap.insert(QString("Save"),saveAction);

    QAction* copyAction = new QAction(tr("&Copy"), this);
    actionMap.insert(QString("Copy"), copyAction);

    QAction* pasteAction = new QAction(tr("&Paste"), this);
    actionMap.insert(QString("Paste"), pasteAction);

    QAction* aboutAction = new QAction(tr("About"), this);
    actionMap.insert(QString("About"), aboutAction);
}

void MainWindow::initDockWidgets()
{
    auto dock1 = new DataGridView(this);
    dock1->setWindowTitle(tr("line graph"));
    //QDockWidget* dock1 = new QDockWidget(tr("Dock1"), this);
    dock1->setFeatures(QDockWidget::AllDockWidgetFeatures);
    dock1->setAllowedAreas(Qt::AllDockWidgetAreas);
    //dock1->setMinimumSize(600, 600);
    dock1->setMinimumWidth(200);
    dockWidgetMap.insert(QString("Dock1"), dock1);

    this->addDockWidget(Qt::LeftDockWidgetArea, dock1);

    auto commandPrompt = new CommandPrompt(this);
    commandPrompt->setFeatures(QDockWidget::AllDockWidgetFeatures);
    commandPrompt->setAllowedAreas(Qt::AllDockWidgetAreas);

    dockWidgetMap.insert(QString("CommandPrompt"), commandPrompt);
    this->addDockWidget(Qt::BottomDockWidgetArea, commandPrompt);

}

void MainWindow::onActionOpen()
{

    auto filePath = QFileDialog::getOpenFileName(this, tr("Please select the picture"),
                                                 QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
                                                 tr("Picture Files(*.jpg)"));

    if(filePath.isEmpty()) return;

    emit openFileChosen(filePath);
}

void MainWindow::onActionSave()
{
    QMessageBox::information(this, tr("Test"), tr("Save"));
}

void MainWindow::onActionCopy()
{
    QMessageBox::information(this, tr("Test"), tr("Copy"));
}

void MainWindow::onActionPaste()
{
    QMessageBox::information(this, tr("Test"), tr("Paste"));
}

void MainWindow::onActionAbout()
{
    QMessageBox::information(this, tr("Test"), tr("About"));
}

