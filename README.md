# pd2-Taiko - Report

UML class diagram:

screen shot:
http://ppt.cc/aQIHj
http://ppt.cc/CzSqf
http://ppt.cc/Wd2vn
http://ppt.cc/vCKgy
http://ppt.cc/FeKgp

how to play:
1.start the game
2.press y to enter main game
3.press k and j to eliminate drum
4.30 seconds for a game
5.Game over and tell the player his score

program architecture:

---start---
1.main.cpp-> mainwindow.cpp -> setUp(ui) -> set start page () -> scene.cpp
---enter main game(scene.cpp)---
2.Init()->keyPressEvent(Key:Y )->setscore(QGraphicsTextItem)->setTime(QGraphicsTextItem)->setCheckbox()->setAnim(Add Special)->Introduce how to play (add h1,h2)
---Game Set---
3.Generate  a drum per second(timer 500ms/per())->GenerateFace()->showScore(right hit 1/per)->showTime(30sec -> 0sec)
---How to play---



