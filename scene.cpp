#include "scene.h"
#include <QKeyEvent>
#include <QApplication>
#include <QPainter>
#include <QString>
#include <iostream>
Scene::Scene(QObject *parent)
{
    screenMode = 0;
}

void Scene::Init(){
    //start
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    starttxt = new QGraphicsTextItem("Press Y to play");
    starttxt->setPos(QPointF(100, 250));
    starttxt->setScale(2.0);
    this->addItem(starttxt);
}

void Scene::keyPressEvent(QKeyEvent *event){
    if(screenMode ==0){
        if(event ->key() ==Qt::Key_Y ){
            this->removeItem(starttxt);
            //score
            sco = new QGraphicsTextItem("Score:");
            sco->setPos(QPointF(80, 40));
            sco->setScale(2.0);
            this->addItem(sco);

            //showtime

            ti = new QGraphicsTextItem("Time:");
            ti->setPos(QPointF(400, 40));
            ti->setScale(2.0);
            this->addItem(ti);
            counterTime();

            screenMode = 1;

            //set checkbox
            checkBox = new Face();
            check.load(":/new/prefix1/checkbox.png");
            check = check.scaled(140,140,Qt::KeepAspectRatio);
            checkBox -> setPixmap(check);

            checkBox -> setPos(0,120);
            addItem(checkBox);

            //set anim
            special = new Face();
            special2.load(":/new/prefix1/sexy.jpg");
            special2 = special2.scaled(400,230,Qt::KeepAspectRatio);
            special -> setPixmap(special2);

            special -> setPos(300,250);
            addItem(special);

            //generate a face per second
            init_timer = new QTimer(this);
            connect(init_timer,SIGNAL(timeout()),this,SLOT(GenerateFace()));
            init_timer -> start(500);
            showScore();
            bgChange();

            //how to play

            h1 = new Face();
            ho1.load(":/new/prefix1/LFace.png");
            ho1 = ho1.scaled(80,80,Qt::KeepAspectRatio);
            h1 -> setPixmap(ho1);

            h1 -> setPos(50,300);
            addItem(h1);

            how1 = new QGraphicsTextItem("Press J");
            how1->setPos(QPointF(50, 380));
            how1->setScale(1.5);
            this->addItem(how1);

            /////
            h2 = new Face();
            ho2.load(":/new/prefix1/RFace.png");
            ho2 = ho2.scaled(80,80,Qt::KeepAspectRatio);
            h2 -> setPixmap(ho2);

            h2 -> setPos(150,300);
            addItem(h2);


            how2 = new QGraphicsTextItem("Press K");
            how2->setPos(QPointF(150, 380));
            how2->setScale(1.5);
            this->addItem(how2);



        }
        if(event ->key() ==Qt::Key_N ){

        }
    }
     else if(screenMode ==1){
        if(event ->key() ==Qt::Key_J){
            openAnim(2);
            openAnim(4);

            if((Tface1->x()) > -20 && (Tface1->x()) < 20&& t1 ==1){
                  this->removeItem(Tface1);
                  score++;
                  this -> removeItem(txtitem);
                  showScore();
                  openAnim(3);
            }

            if((Tface2->x()) > -20 && (Tface2->x()) < 20&& t2 ==1){
                 this->removeItem(Tface2);
                 score++;
                 this -> removeItem(txtitem);
                 showScore();
                 openAnim(3);
            }
            if((Tface3->x()) > -20 && (Tface3->x()) < 20&& t3 ==1){
                 this->removeItem(Tface3);
                 score++;
                 this -> removeItem(txtitem);
                 showScore();
                 openAnim(3);
            }

            if((Tface4->x()) > -20 && (Tface4->x()) < 20&& t4 ==1){
                  this->removeItem(Tface4);
                 score++;
                 this -> removeItem(txtitem);
                 showScore();
                 openAnim(3);
            }

            if((Tface5->x()) > -20 && (Tface5->x()) < 20 && t5 ==1){
                  this->removeItem(Tface5);
                  score++;
                  this -> removeItem(txtitem);
                  showScore();
                  openAnim(3);
            }
        }

        if(event ->key() == Qt::Key_K){
            openAnim(2);
            openAnim(4);

            if((Tface1->x()) > -20 && (Tface1->x()) < 20&& t1 ==0){
                  this->removeItem(Tface1);
                  score++;
                  this -> removeItem(txtitem);
                  showScore();
                  openAnim(3);
            }

            if((Tface2->x()) > -20 && (Tface2->x()) < 20&& t2 ==0){
                 this->removeItem(Tface2);
                 score++;
                 this -> removeItem(txtitem);
                 showScore();
                 openAnim(3);
            }


            if((Tface3->x()) > -20 && (Tface3->x()) < 20&& t3 ==0){
                 this->removeItem(Tface3);
                 score++;
                 this -> removeItem(txtitem);
                 showScore();
                 openAnim(3);
            }


            if((Tface4->x()) > -20 && (Tface4->x()) < 20&& t4 ==0){
                 this->removeItem(Tface4);
                 score++;
                 this -> removeItem(txtitem);
                 showScore();
                 openAnim(3);
            }


            if((Tface5->x()) > -20 && (Tface5->x()) < 20 && t5 ==0){
                  this->removeItem(Tface5);
                  score++;
                  this ->removeItem(txtitem);
                  openAnim(3);
            }

        }
    }
    else{
        if(event ->key() ==Qt::Key_D){

        }

        if(event ->key() == Qt::Key_M){

        }
   }
}
//速度不該由按鍵控制
void Scene::keyReleaseEvent(QKeyEvent *event){
     if(event ->key() == Qt::Key_K){
           openAnim(1);
     }
     if(event ->key() == Qt::Key_J){
           openAnim(1);
     }
}

void Scene::bgChange(){
    if(tim ==0){
        QImage bg;
        bg.load(":/new/prefix1/endbg.jpg");
        bg = bg.scaled(640,480);
        this->setBackgroundBrush(bg);
    }
    else{
     QImage bg;
     bg.load(":/new/prefix1/bg_clear.jpg");
     bg = bg.scaled(640,480);
     this->setBackgroundBrush(bg);
    }
}

void Scene::MoveFace(){
    if(p>=1){
        x1-=2;
        Tface1 -> setPos(x1,y);

        if((Tface1->x()) == -100){

             this->removeItem(Tface1);
            /*
             score++;
             this -> removeItem(txtitem);
             showScore();
             */
             x1 = 650;
             timer1->stop();
        }

    }
    if(p>=2){
        x2-=2;
        Tface2 -> setPos(x2,y);
//change to -100
        if((Tface2->x()) == -100){

                    this->removeItem(Tface2);
            /*
                     score++;
                     this -> removeItem(txtitem);
                     showScore();
                     */
                     x2 = 650;
                     timer2->stop();
            }

    }
    if(p>=3){
        x3-=2;
        Tface3 -> setPos(x3,y);

        if((Tface3->x()) == -100){

             this->removeItem(Tface3);
            /*
             score++;
             this -> removeItem(txtitem);
             showScore();
             */
             x3 = 650;
             timer3->stop();
        }

    }
    if(p>=4){
        x4-=2;
        Tface4 -> setPos(x4,y);

        if((Tface4->x()) == -100){

                   this->removeItem(Tface4);
            /*
                    score++;
                    this -> removeItem(txtitem);
                    showScore();
                    */
                   x4 = 650;
                   timer4->stop();//Very Important!!!
        }

    }
    if(p>=5){
        x5-=2;
        Tface5 -> setPos(x5,y);

        if((Tface5->x()) == -100){

                   this->removeItem(Tface5);
            /*
                    score++;
                    this -> removeItem(txtitem);
                    showScore();
                    */
                   x5 = 650;
                   timer5->stop();//Very Important!!!
        }

    }

}

void Scene::GenerateFace(){
    p++;
    QPixmap TpFace;
    rand = qrand()%3;
    if(rand ==0){
        TpFace.load(":/new/prefix1/RFace.png");
    }

    else if( rand==1){
        TpFace.load(":/new/prefix1/LFace.png");
    }

    else{
        TpFace.load("");
    }
     TpFace = TpFace.scaled(90,90,Qt::KeepAspectRatio);

    if((p%5)==1){
        t1 = rand;
        x1 = 650;//initial x site
        y = 150;//initial y site
    Tface1 = new Face();
    Tface1 -> setPixmap(TpFace);
    Tface1 -> setPos(x1,y);
    addItem(Tface1);
    GenerateAnim();
    }

    if((p%5)==2){
        t2 = rand;
        x2 = 650;//initial x site
        y = 150;//initial y site
    Tface2 = new Face();
    Tface2 -> setPixmap(TpFace);
    Tface2 -> setPos(x2,y);
    addItem(Tface2);
    GenerateAnim();
    }

    if((p%5)==3){
        t3 = rand;
        x3 = 650;//initial x site
        y = 150;//initial y site
    Tface3 = new Face();
    Tface3 -> setPixmap(TpFace);
    Tface3 -> setPos(x3,y);
    addItem(Tface3);
    GenerateAnim();
    }

    if((p%5)==4){
        t4 = rand;
        x4 = 650;//initial x site
        y = 150;//initial y site
    Tface4 = new Face();
    Tface4 -> setPixmap(TpFace);
    Tface4 -> setPos(x4,y);
    addItem(Tface4);
    GenerateAnim();

}
    if((p%5)==0){
        t5 = rand;
        x5 = 650;//initial x site
        y = 150;//initial y site
    Tface5 = new Face();
    Tface5 -> setPixmap(TpFace);
    Tface5 -> setPos(x5,y);
    addItem(Tface5);
    GenerateAnim();
    }
}

void Scene::GenerateAnim(){
    if((p%5)==1){
     timer1 = new QTimer(this);
     connect(timer1,SIGNAL(timeout()),this,SLOT(MoveFace()));
     timer1 -> start(10);
    }
    if((p%5)==2){
     timer2 = new QTimer(this);
     connect(timer2,SIGNAL(timeout()),this,SLOT(MoveFace()));
     timer2 -> start(10);
    }

    if((p%5)==3){
     timer3 = new QTimer(this);
     connect(timer3,SIGNAL(timeout()),this,SLOT(MoveFace()));
     timer3 -> start(10);
    }
    if((p%5)==4){
     timer4 = new QTimer(this);
     connect(timer4,SIGNAL(timeout()),this,SLOT(MoveFace()));
     timer4 -> start(10);
    }
    if((p%5)==0){
     timer5 = new QTimer(this);
     connect(timer5,SIGNAL(timeout()),this,SLOT(MoveFace()));
     timer5 -> start(10);
    }
}

void Scene::OutResult(){

}


void Scene::showScore(){

    QString s = QString::number(score);
    txtitem = new QGraphicsTextItem(s);
    txtitem->setPos(QPointF(200,40));
    txtitem->setScale(2.0);
    this->addItem(txtitem);

}

void Scene::showTime(){
    this->removeItem(time);
    QString s = QString::number(tim);
    time = new QGraphicsTextItem(s);
    time->setPos(QPointF(520,40));
    time->setScale(2.0);
    this->addItem(time);

    if(tim==0){
        init_timer -> stop();
        ctime-> stop();
        bgChange();
        this->removeItem(checkBox);
        this->removeItem(ti);
        this->removeItem(time);
         this->removeItem(Tface1);
         this->removeItem(Tface2);
         this->removeItem(Tface3);
         this->removeItem(Tface4);
         this->removeItem(Tface5);
        this->removeItem(how1);
        this->removeItem(how2);
        this->removeItem(h1);
        this->removeItem(h2);
        sco -> setPos(QPointF(200, 150));
        txtitem-> setPos(QPointF(300, 150));

        re = new QGraphicsTextItem("Play Again?");
        re->setPos(QPointF(200,250));
        re->setScale(2.0);
        this->addItem(re);
        sta = new QGraphicsTextItem("Press D to restart");
        sta->setPos(QPointF(200,300));
        sta->setScale(2.0);
        this->addItem(sta);
    }
    else{
      tim--;
    }
}

void Scene::counterTime(){

    ctime = new QTimer(this);
    connect(ctime,SIGNAL(timeout()),this,SLOT(showTime()));
    ctime -> start(1000);

}

void Scene::openAnim(int k){
    if(k ==2){
      removeItem(checkBox);
      check.load(":/new/prefix1/checkbox2.png");
      check = check.scaled(140,140,Qt::KeepAspectRatio);
      checkBox -> setPixmap(check);
      addItem(checkBox);
    }
    else if(k==1){
        removeItem(checkBox);
        check.load(":/new/prefix1/checkbox.png");
        check = check.scaled(140,140,Qt::KeepAspectRatio);
        checkBox -> setPixmap(check);
        addItem(checkBox);
    }

    else if(k==3){
        removeItem(special);
        special2.load(":/new/prefix1/sexy.jpg");
        special2 = special2.scaled(400,230,Qt::KeepAspectRatio);
        special -> setPixmap(special2);

        special -> setPos(300,250);
        addItem(special);

    }
    else{
        removeItem(special);
        special2.load("");
        special2 = special2.scaled(400,230,Qt::KeepAspectRatio);
        special -> setPixmap(special2);

        special -> setPos(300,250);
        addItem(special);
    }
}
