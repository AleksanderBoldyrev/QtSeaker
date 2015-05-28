//*** The class which was made to collect the information about two fields:
//    AI field and Player field, and it collects the cell states and other data. ***

#ifndef _FIELD_H
#define _FIELD_H

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <QObject>

using namespace std;

#include "Types.h"

class Field: public QObject
{
    Q_OBJECT
    units   				wcells, hcells;
    vector<vector<cstate> >	cells;
    units					wc = 10,				 hc = 10;

    unsigned short			Aftermath				 (units px, units py);
public:
    void					SetCell					 (units w, units h, cstate s);
    cstate 					GetCell					 (units w, units h);
    const cstate			water					 = 0x20;
    const cstate			miss					 = 0x0F;
    const cstate			up						 = 0x1E;
    const cstate			down					 = 0x1F;
    const cstate			left					 = 0x11;
    const cstate			right					 = 0x10;
    const cstate			hbody					 = 0xFE;
    const cstate			vbody					 = 0xFD;
    const cstate			onesh					 = 0x04;
    const cstate			hit						 = 0x06;
    const cstate			err						 = 0xFF;

    unsigned short			shipsnum[5];
    bool 					owner;											//True == Player; False == AI.
    units					posx = 0,                posy = 0;
    static const units		wid = 10,                hei = 10;
                            Field					 (bool who, units sx, units sy);
                            ~Field					 ();
    units					Width					 ()  { return wcells; }
    units					Height					 ()  { return hcells; }
    void					Wipe					 ();                                        // Clears the field.
    bool 					SetPos					 (units x, units y);                        // Feature setting of the position of the cursor which was used for both of the classes,
                                                                                                // but in the GUI version only for the AI.
    cstate					GetPosVal				 ();                                        // Gets the cell state of the cell with position posx and posy.
    unsigned short			Fire					 (units px, units py);                      // The hard algorithm function which is used to change the cell state when the fire signal is caught.
    bool					CreateShip				 (units x, units y, units l, dir vdir);     // Creates the ship exactly on the player field (For the AI place there is another function in the AI class).
    bool					ShipSpaceIsChecked		 (units x, units y, units l, dir vdir);     // Defines, whether the ship is placed correctly or not.
    bool					CenterCellSpaceIsChecked (units cellx, units celly, units le, dir di, units ord);   // An extra function which checks the cell surroundings for the previous function.
signals:
    void                    P_StateChanged(int x, int y, int state);                        // The signal for the player field changes to change the field promptly.
    void                    C_StateChanged(int x, int y, int state);                        // -||- for the computer.
};

#endif
