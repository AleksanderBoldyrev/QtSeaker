#include "GameLogic.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    GameLogic gl;
    gl.Initz();

    QObject::connect(&w, SIGNAL(Clicked(int,int, bool)), &gl, SLOT(PlaceShips(int, int, bool)));
    QObject::connect(&w, SIGNAL(Clicked(int,int, bool)), &gl, SLOT(MakeMove(int, int, bool)));
    QObject::connect(&w, SIGNAL(Clicked(int,int, bool)), &gl, SLOT(PlayTheGame(int, int, bool)));
    QObject::connect(&gl, SIGNAL(LogToCons(QString)), &w, SLOT(Log(QString)));
    QObject::connect(gl.art, SIGNAL(LogToCons(QString)), &w, SLOT(Log(QString)));
    QObject::connect(gl.fuf, SIGNAL(P_StateChanged(int, int, int)), &w, SLOT(P_Changed(int,int,int)));
    QObject::connect(gl.fcf, SIGNAL(C_StateChanged(int, int, int)), &w, SLOT(C_Changed(int,int,int)));
    QObject::connect(gl.art, SIGNAL(P_StateChanged2(int, int, int)), &w, SLOT(P_Changed(int,int,int)));
    QObject::connect(w.cb, SIGNAL(stateChanged(int)), &gl, SLOT(ChangeDirect(int)));


    w.show();
    return a.exec();
}


