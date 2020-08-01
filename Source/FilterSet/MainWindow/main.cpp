#include "MainWindow.h"

#include <QApplication>
#include <qsplashscreen.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    QPixmap pixmap(":/images/splash/splash");
    QSplashScreen *splash = new QSplashScreen(pixmap);
    splash->show();
    splash->showMessage("splash");
    qApp->processEvents();

    MainWindow w;
    splash->finish(&w);
    w.show();
    return a.exec();
}
