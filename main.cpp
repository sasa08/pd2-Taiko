#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QDesktopWidget wid;
    int screenW = 640;
    int screenH = 480;
    w.setGeometry(wid.screen()->width()/2 - (screenW/2) , wid.screen()->height()/2 - (screenH/2) , screenW , screenH);
    // ================= Setting Windows Title and Icon =================
    w.setWindowTitle("Taiko");
    //w.setWindowIcon(QIcon(":/new/prefix1/startbg.jpg"));
    w.setFixedSize(screenW , screenH);
    w.show();
    return a.exec();
}
