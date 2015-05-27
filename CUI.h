#ifndef _CUI_H
#define _CUI_H

#include <windows.h>
#include <stdio.h>

#include "Field.h"
#include "Types.h"

class CUI
{
public:
    void 		 InitFields		();
    void 		 InitAI			();
    void 		 UpdateFields	();
    void 		 StartGame		();
    void 		 EndGame		();

                 CUI			(units w, units h);
                 ~CUI			();

private:

    units		 _w,			_h;

signals:
    void        P_StateChanged(int x, int y, int state);
    void        C_StateChanged(int x, int y, int state);
public slots:

};

#endif
