//*** The class which is made to implement all the functions of algorithms. ***

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
    bool            dir;                                        //dir - direction. 1 - horizontal; 0 - vertical.
    unsigned short  clen;

                    GameLogic      ();
                    ~GameLogic     ();
    void            Initz          ();                          // The function which inits all the inner data.
signals:
    void            LogToCons      (QString s);                 // The primitive output for the imitated console.
public slots:
    void            PlaceShips     (int x, int y, bool b);      // This function implements the ship arrangement.
    void            PlayTheGame    (int x, int y, bool b);      // The game states processing and auxiliary calls for other main game logic functions.
    void            MakeMove       (int x, int y, bool b);      // The player's facility to shoot at some computer field cell.
    void            ChangeDirect   (int s);                     // Slot for the QCheckBox call.

};

#endif // GAMELOGIC_H
