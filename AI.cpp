#include "AI.h"

AI::AI(Field* fuf)
{
    level = 0;
    lhX   = -1;
    lhY   = -1;
    hDir  = false;
    v.resize(fuf->Width());
    for (int i=0; i<v.size(); i++)
        v[i].resize(fuf->Height());
    for (int i=0; i<v.size(); i++)
        for (int j=0; j<v[i].size(); j++)
            v[i][j]=0;
}

AI::~AI()
{

}

bool AI::Getlevel()
{
    return level;
}

void AI::Setlevel(bool lv)
{
    level = lv;
}

void AI::PlaceShipsAI(Field* fcf)
{
    srand((unsigned)time(0));
    units x = 0, y = 0, sdnum;
    short currcc = 20;
    dir sd = 'h';
    units len = 1;
    unsigned short  count1 = 4,
                    count2 = 3,
                    count3 = 2,
                    count4 = 1;
    while (currcc > 0)
    {
        sdnum = rand() % 2;
        switch (sdnum)
        {
        case (0) :
            sd = 'h';
            break;
        case (1) :
            sd = 'v';
            break;
        }
        len = rand() % 5;
        if (len == 0) continue;
        switch (len)
        {
        case(1) :
            if (count1 != 0)
            {
                x = rand() % fcf->Width();
                y = rand() % fcf->Height();
                count1--;
                currcc -= 1;
                if (!fcf->CreateShip(x, y, len, sd)) switch (len)
                {
                case(1) :
                    count1++;
                    currcc += 1;
                    break;
                case(2) :
                    count2++;
                    currcc += 2;
                    break;
                case(3) :
                    count3++;
                    currcc += 3;
                    break;
                case(4) :
                    count4++;
                    currcc += 4;
                    break;
                }
            }
            else continue;
            break;
        case(2) :
            if (count2 != 0)
            {
                switch (sd)
                {
                case ('h') :
                    x = rand() % (fcf->Width() - 1);
                    y = rand() % fcf->Height();
                    break;
                case ('v') :
                    x = rand() % fcf->Width();
                    y = rand() % (fcf->Height() - 1);
                    break;
                }
                count2--;
                currcc -= 2;
                if (!fcf->CreateShip(x, y, len, sd)) switch (len)
                {
                case(1) :
                    count1++;
                    currcc += 1;
                    break;
                case(2) :
                    count2++;
                    currcc += 2;
                    break;
                case(3) :
                    count3++;
                    currcc += 3;
                    break;
                case(4) :
                    count4++;
                    currcc += 4;
                    break;
                }
            }
            else continue;
            break;
        case(3) :
            if (count3 != 0)
            {
                switch (sd)
                {
                case ('h') :
                    x = rand() % (fcf->Width() - 2);
                    y = rand() % fcf->Height();
                    break;
                case ('v') :
                    x = rand() % fcf->Width();
                    y = rand() % (fcf->Height() - 2);
                    break;
                }
                count3--;
                currcc -= 3;
                if (!fcf->CreateShip(x, y, len, sd)) switch (len)
                {
                case(1) :
                    count1++;
                    currcc += 1;
                    break;
                case(2) :
                    count2++;
                    currcc += 2;
                    break;
                case(3) :
                    count3++;
                    currcc += 3;
                    break;
                case(4) :
                    count4++;
                    currcc += 4;
                    break;
                }
            }
            else continue;
            break;
        case(4) :
            if (count4 != 0)
            {
                switch (sd)
                {
                case ('h') :
                    x = rand() % (fcf->Width() - 3);
                    y = rand() % fcf->Height();
                    break;
                case ('v') :
                    x = rand() % fcf->Width();
                    y = rand() % (fcf->Height() - 3);
                    break;
                }
                count4--;
                currcc -= 4;
                if (!fcf->CreateShip(x, y, len, sd)) switch (len)
                {
                case(1) :
                    count1++;
                    currcc += 1;
                    break;
                case(2) :
                    count2++;
                    currcc += 2;
                    break;
                case(3) :
                    count3++;
                    currcc += 3;
                    break;
                case(4) :
                    count4++;
                    currcc += 4;
                    break;
                }
            }
            else continue;
            break;
        }
    }
}

bool AI::PieceOfShip(cstate s, Field* fuf)
{
    bool isp = false;
    if (s == fuf->hbody || s == fuf->vbody || s == fuf->left || s == fuf->right || s == fuf->onesh || s == fuf->up || s == fuf->down) isp = true;
    return isp;
}

bool AI::CheckNeighbours(int x, int y)
{
    if (x == 0 && y == 0)
    {
        if (v[x + 1][y+1]==2) return false;
        if (v[x + 1][y]==2) return false;
        //if (v[x + 1][y-1]==2) return false;
        if (v[x][y+1]==2) return false;
        //if (v[x][y-1]==2) return false;
        //if (v[x-1][y+1]==2) return false;
        //if (v[x-1][y]==2) return false;
        //if (v[x-1][y-1]==2) return false;
    }
    else if (x == 0 && y == (v[x].size()-1))
    {
        //if (v[x + 1][y+1]==2) return false;
        if (v[x + 1][y]==2) return false;
        if (v[x + 1][y-1]==2) return false;
        //if (v[x][y+1]==2) return false;
        //if (v[x][y]==2) return false;
        if (v[x][y-1]==2) return false;
        //if (v[x-1][y+1]==2) return false;
        //if (v[x-1][y]==2) return false;
        //if (v[x-1][y-1]==2) return false;
    }
    else if (x == (v.size()-1) && y == 0)
    {
        //if (v[x + 1][y+1]==2) return false;
        //if (v[x + 1][y]==2) return false;
        //if (v[x + 1][y-1]==2) return false;
        if (v[x][y+1]==2) return false;
        //if (v[x][y]==2) return false;
        //if (v[x][y-1]==2) return false;
        if (v[x-1][y+1]==2) return false;
        if (v[x-1][y]==2) return false;
        //if (v[x-1][y-1]==2) return false;
    }
    else if (x == (v.size()-1) && y == (v[0].size()-1))
    {
        //if (v[x + 1][y+1]==2) return false;
        //if (v[x + 1][y]==2) return false;
        //if (v[x + 1][y-1]==2) return false;
        //if (v[x][y+1]==2) return false;
        //if (v[x][y]==2) return false;
        if (v[x][y-1]==2) return false;
        //if (v[x-1][y+1]==2) return false;
        if (v[x-1][y]==2) return false;
        if (v[x-1][y-1]==2) return false;
    }
    else if (x == 0)
    {
        if (v[x + 1][y+1]==2) return false;
        if (v[x + 1][y]==2) return false;
        if (v[x + 1][y-1]==2) return false;
        if (v[x][y-1]==2) return false;
        //if (v[x-1][y+1]==2) return false;
        //if (v[x-1][y]==2) return false;
        //if (v[x-1][y-1]==2) return false;
    }
    else if (y == 0)
    {
        if (v[x + 1][y+1]==2) return false;
        if (v[x + 1][y]==2) return false;
        //if (v[x + 1][y-1]==2) return false;
        if (v[x][y+1]==2) return false;
        //if (v[x][y-1]==2) return false;
        if (v[x-1][y+1]==2) return false;
        if (v[x-1][y]==2) return false;
        //if (v[x-1][y-1]==2) return false;
    }

    if (x == v[0].size()-1)
    {
        //if (v[x + 1][y+1]==2) return false;
        //if (v[x + 1][y]==2) return false;
        //if (v[x + 1][y-1]==2) return false;
        if (v[x][y+1]==2) return false;
        if (v[x][y-1]==2) return false;
        if (v[x-1][y+1]==2) return false;
        if (v[x-1][y]==2) return false;
        if (v[x-1][y-1]==2) return false;
    }

    if (y == v[0].size()-1)
    {
        //if (v[x + 1][y+1]==2) return false;
        if (v[x + 1][y]==2) return false;
        if (v[x + 1][y-1]==2) return false;
        //if (v[x][y+1]==2) return false;
        if (v[x][y-1]==2) return false;
        //if (v[x-1][y+1]==2) return false;
        if (v[x-1][y]==2) return false;
        if (v[x-1][y-1]==2) return false;
    }
    else
    {
        if (v[x + 1][y+1]==2) return false;
        if (v[x + 1][y]==2) return false;
        if (v[x + 1][y-1]==2) return false;
        if (v[x][y+1]==2) return false;
        if (v[x][y-1]==2) return false;
        if (v[x-1][y+1]==2) return false;
        if (v[x-1][y]==2) return false;
        if (v[x-1][y-1]==2) return false;
    }
    return true;
}

void AI::MakeMove(Field* fuf)
{
    unsigned short clen;
    srand((unsigned)time(0));
    bool isturn  = true;
    bool nextship = true;
    //bool hardchoice = true;
    static bool wasmiss = false;
    unsigned short dir = 0;
    //units x = 0, y = 0;
    bool found = false;
    unsigned short touchC=0;
    cstate st;
    switch (this->level)
    {
    case (1) :						//*** Hard level. ***
        // AI chooses position to hit enemy
        while (fuf->shipsnum[0] > 0 && isturn)
        {
            if ((isshot /*|| wasmiss*/) && !nextship)
            {
                found = false;
                touchC = 0;
                while (!found && touchC<4)
                {
                    dir = rand() % 2;
                    if (hDir)
                        dir += 2;
                    switch (dir)
                    {
                    case(2) :			//*** Up. ***
                        touchC++;
                        if (fuf->posy > 0)
                            if (v[fuf->posx][fuf->posy - 1] == 0)
                            {
                                fuf->posy--;
                                found = true;
                            }
                        break;
                    case(3) :			//*** Down. ***
                        touchC++;
                        if (fuf->posy < fuf->Height() - 1)
                            if (v[fuf->posx][fuf->posy + 1] == 0)
                            {
                                fuf->posy++;
                                found = true;
                            }
                        break;
                    case(0) :			//*** Left. ***
                        touchC++;
                        if (fuf->posx > 0)
                            if (v[fuf->posx - 1][fuf->posy] == 0)
                            {
                                fuf->posx--;
                                found = true;
                            }
                        break;
                    case(1) :			//*** Right. ***
                        touchC++;
                        if (fuf->posx < fuf->Width() - 1)
                            if (v[fuf->posx + 1][fuf->posy] == 0)
                            {
                                found = true;
                                fuf->posx++;
                            }
                        break;
                    }
                }
                if (touchC == 3 && !found)
                {
                    //There are no fields to shoot around this point
                    //Check other side of the ship
                    int xx = fuf->posx;
                    int yy = fuf->posy;

                    bool check = false;
                    //Check vertical
                    if (hDir)
                    {
                        //Check upside
                        if (yy == fuf->Height() - 1)
                            check = true;
                        else
                            if (v[xx][yy] == 2 && v[xx][yy + 1] != 0)
                                check = true;
                        if (check)
                            while ((v[xx][yy] == 2)&&(yy > 0))
                                yy--;
                        //Check downside
                        if (yy == 0)
                            check = true;
                        else
                            if (v[xx][yy] == 2 && v[xx][yy - 1] != 0)
                                check = true;
                        if (check)
                            while ((v[xx][yy] == 2)&&(yy < (fuf->Height() - 1)))
                                yy++;
                    }
                    //Check horizontal
                    if (!hDir)
                    {
                        //Check to the right side
                        if (xx == 0)
                            check = true;
                        else
                            if (v[xx][yy] == 2 && v[xx - 1][yy] != 0)
                                check = true;
                        if (check)
                            while ((v[xx][yy] == 2) && (xx < (fuf->Width() - 1)))
                                xx++;
                        //Check to the left side
                        if (xx == (fuf->Width() - 1))
                            check = true;
                        else
                            if (v[xx][yy] == 2 && v[xx + 1][yy] != 0)
                                check = true;
                        if (check)
                            while ((v[xx][yy] == 2) && (xx > 0))
                                xx--;
                    }
                    // If found nothing in these steps, check random position
                    if (v[xx][yy] == 2)
                    {
                        fuf->posx = rand() % fuf->Width();
                        fuf->posy = rand() % fuf->Height();
                        while (v[fuf->posx][fuf->posy] != 0 && v[fuf->posx][fuf->posy] && CheckNeighbours(fuf->posx, fuf->posy))
                        {
                            fuf->posx = rand() % fuf->Width();
                            fuf->posy = rand() % fuf->Height();
                        }
                    }
                }
            }
            else
            {
                if (lhX >= 0 && lhY >= 0)
                {
                    fuf->posx = lhX;
                    fuf->posy = lhY;
                    found = false;
                    while (!found)
                    {
                        dir = rand() % 2;
                        if (hDir)
                            dir += 2;
                        switch (dir)
                        {
                        case(2) :			//*** Up. ***
                            if (fuf->posy > 0)
                                if (v[fuf->posx][fuf->posy - 1] == 0)
                                {
                                    fuf->posy--;
                                    found = true;
                                }
                            break;
                        case(3) :			//*** Down. ***
                            if (fuf->posy < fuf->Height() - 1)
                                if (v[fuf->posx][fuf->posy + 1] == 0)
                                {
                                    fuf->posy++;
                                    found = true;
                                }
                            break;
                        case(0) :			//*** Left. ***
                            if (fuf->posx > 0)
                                if (v[fuf->posx - 1][fuf->posy] == 0)
                                {
                                    fuf->posx--;
                                    found = true;
                                }
                            break;
                        case(1) :			//*** Right. ***
                            if (fuf->posx < fuf->Width() - 1)
                                if (v[fuf->posx + 1][fuf->posy] == 0)
                                {
                                    found = true;
                                    fuf->posx++;
                                }
                            break;
                        }
                    }
                }
                else
                {
                    fuf->posx = rand() % fuf->Width();
                    fuf->posy = rand() % fuf->Height();
                    while (v[fuf->posx][fuf->posy] != 0 && CheckNeighbours(fuf->posx, fuf->posy))
                    {
                        fuf->posx = rand() % fuf->Width();
                        fuf->posy = rand() % fuf->Height();
                   }
                }

            }
            // AI chooses position to hit enemy - end of the code
            //Sleep(500);
            st = fuf->GetPosVal();
            clen = fuf->Fire(fuf->posx, fuf->posy);

            // AI hit
            if (st != fuf->water && st != fuf->hit && st != fuf->miss)
            {
                emit P_StateChanged2(fuf->posx, fuf->posy, fuf->hit);
                v[fuf->posx][fuf->posy] = 2;
                if (clen > 0)
                {
                    QString ss;
                    ss.append("AI killed the ship of length ");
                    ss.append(QString::number(clen));
                    emit LogToCons(ss);
                }
                // Check direction
                if (lhX >= 0 && lhY >= 0)
                {
                    if (lhX == fuf->posx)
                        hDir = false;
                    else if (lhY == fuf->posy)
                        hDir = true;
                }
                //
                lhX = fuf->posx;
                lhY = fuf->posy;

                isshot = true;
                wasmiss = false;
                if (clen <= 1)
                {
                    lhX = -1;
                    lhY = -1;
                    nextship = true;
                }
            }
            //AI miss
            else if (st == fuf->water)
            {
                emit P_StateChanged2(fuf->posx, fuf->posy, fuf->miss);
                v[fuf->posx][fuf->posy] = 1;
                if (isshot) isshot = false;
                isturn = false;
            }
        }
        break;
    case (0) :						//*** Easy level. ***
        while (fuf->shipsnum[0] > 0 && isturn)
        {
            fuf->posx = rand() % fuf->Width();
            fuf->posy = rand() % fuf->Height();
            cstate st = fuf->GetPosVal();
            Sleep(500);
            clen = fuf->Fire(fuf->posx, fuf->posy);
            if (st != fuf->water && st != fuf->hit && st != fuf->miss)
            {
                emit P_StateChanged2(fuf->posx, fuf->posy, fuf->hit);
                v[fuf->posx][fuf->posy] = 2;
                if (clen > 0)
                {
                    QString ss;
                    ss.append("AI killed the ship of length ");
                    ss.append(QString::number(clen));
                    emit LogToCons(ss);
                }
            }
            else if (st == fuf->water)
            {
                emit P_StateChanged2(fuf->posx, fuf->posy, fuf->miss);
                isturn = false;
                v[fuf->posx][fuf->posy] = 1;
            }
        }
        break;
    }
}
