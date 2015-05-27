#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#define _CRT_SECURE_NO_WARNINGS

#include "mainwindow.h"
#include <QApplication>

#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <cstring>

#include "Types.h"
#include "AI.h"
#include "Player.h"
#include "Field.h"

class GameLogic : public QObject
{
    Q_OBJECT

public:
    AI*             art;
    Field*          fuf;
    Field*          fcf;
    bool            turn;
    unsigned int    g_state;
    bool            dir;       //dir - direction. 1 - horizontal; 0 - vertical.
    unsigned short  clen;

                    GameLogic      ();
                    ~GameLogic     ();
    void            Initz          ();
signals:
    void            LogToCons      (QString s);
public slots:
    void            PlaceShips     (int x, int y, bool b);
    void            PlayTheGame    (int x, int y, bool b);
    void            MakeMove       (int x, int y, bool b);
    void            ChangeDirect   (int s);

};

#endif // GAMELOGIC_H
