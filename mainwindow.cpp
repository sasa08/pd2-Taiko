#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new Scene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,640,480); // change the value to fit
    settingBg();
    ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow :: settingBg(){
    QImage bg;
    bg.load(":/new/prefix1/startbg.jpg");
    bg = bg.scaled(660,500);
    scene->setBackgroundBrush(bg);
    /* Goto setting the initial page for bbtan */
    scene->Init();
}
