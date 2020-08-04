#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QDockWidget>

#include "Components/PicturePanelWidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initMenu();
    void initToolBar();
    void initStatusBar();
    void initDockWidgets();
    void initActions();

private slots:
    void onActionOpen();
    void onActionSave();
    void onActionCopy();
    void onActionPaste();
    void onActionAbout();

signals:
    void openFileChosen(const QString& filePath);

private:
    Ui::MainWindow *ui;
    PicturePanelWidget *picturePanel;
    QMap<QString, QAction*> actionMap;
    QMap<QString, QDockWidget*> dockWidgetMap;
};
#endif // MAINWINDOW_H
