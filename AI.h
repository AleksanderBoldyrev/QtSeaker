//*** The class which was made to implement the AI logic and all the authomatic algorithms. ***

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
    bool            hDir;                                       // false - horizontal, true - vertical
    QVector<QVector<cstate> > v;
    bool CheckNeighbours(int x, int y);
public:
                    AI (Field* fuf);
                    ~AI();
    bool			Getlevel();
    void			Setlevel(bool lv);
    void 			PlaceShipsAI(Field* fcf);                   // Similar to the PlaceShips function (in the Field )
    bool			PieceOfShip(cstate s, Field* fuf);          // Checks whether the exact cell is a part of the function, or not.
    void		 	MakeMove(Field* fuf);                       // The similar to the Field class MakeMove function.
signals:
    void            P_StateChanged2(int x, int y, int state);   // These are the similar slots
    void            C_StateChanged2(int x, int y, int state);   // with those in the Field class.
    void            LogToCons      (QString s);                 // The imitated console output.
};

#endif
