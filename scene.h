
#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QTime>
#include "face.h"

class Scene:public QGraphicsScene
{
  Q_OBJECT

public:
    Scene(QObject *parent = 0);
    void Init();

    int screenMode;
    int x1 , x2 ,x3 ,x4,x5;
    int y ;
    int p = 0;
    int t1,t2,t3,t4,t5;
    int rand;
    int cnt = 0;
    int score = 0;
    int tim = 31;
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void bgChange();
    void openAnim(int k);
    void GenerateAnim();
    void OutResult();
    void showScore();
    void counterTime();

    QPixmap check;
    QPixmap ho1;
    QPixmap ho2;
    QPixmap special2;
    Face *Tface1;
    Face *Tface2;
    Face *Tface3;
    Face *Tface4;
    Face *Tface5;
    Face *checkBox;
    Face *Rface;
    Face *h1;
    Face *h2;
    Face *special;

    QTimer *init_timer;
    QTimer *timer1;
    QTimer *timer2;
    QTimer *timer3;
    QTimer *timer4;
    QTimer *timer5;
    QTimer *ctime;
    QGraphicsTextItem *sco;
    QGraphicsTextItem *ti;
    QGraphicsTextItem *txtitem;
    QGraphicsTextItem *time;
    QGraphicsTextItem *re;
    QGraphicsTextItem *sta;
    QGraphicsTextItem *starttxt;
    QGraphicsTextItem *how2;
    QGraphicsTextItem *how1;

public slots:
  //   void bgChange();
     void MoveFace();
     void GenerateFace();
     void showTime();

    };


#endif // SCENE_H
