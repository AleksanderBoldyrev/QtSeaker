#ifndef _AI_H
#define _AI_H

#include <ctime>
#include <windows.h>
#include <QVector>
#include "Field.h"
#include "Types.h"

class AI: public QObject
{
    Q_OBJECT
    bool			level;
    bool			isshot;
    bool            nextship;
    short           lhX, lhY;
    bool            hDir; // false - horizontal, true - vertical
    QVector<QVector<cstate> > v;
    bool CheckNeighbours(int x, int y);
public:
                    AI (Field* fuf);
                    ~AI();
    bool			Getlevel();
    void			Setlevel(bool lv);
    void 			PlaceShipsAI(Field* fcf);
    bool			PieceOfShip(cstate s, Field* fuf);
    void		 	MakeMove(Field* fuf);
signals:
    void            P_StateChanged2(int x, int y, int state);
    void            C_StateChanged2(int x, int y, int state);
    void            LogToCons      (QString s);
};

#endif
