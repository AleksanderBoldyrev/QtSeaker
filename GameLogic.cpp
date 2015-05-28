#include "GameLogic.h"

GameLogic::GameLogic()
{
    fuf     = new Field(PLAYER, Field::wid, Field::hei);
    fcf     = new Field(COMP,   Field::wid, Field::hei);
    art     = new AI(fcf);
    turn    = false;
    g_state = 0;
    dir     = 1;
}

GameLogic::~GameLogic()
{
    delete art;
    delete fuf;
    delete fcf;
}

void GameLogic::ChangeDirect(int s)
{
    if (s == Qt::Checked)
        dir = false;
    else if (s == Qt::Unchecked)
        dir = true;
}

void GameLogic::PlaceShips(int x, int y, bool b)
{
    switch (g_state)
    {
    case (0):
        break;

    case (1):
        if ((dir == true)  && b) if(fuf->CreateShip(x, y, 4, 'h'))
            g_state++;
        if ((dir == false) && b) if(fuf->CreateShip(x, y, 4, 'v')) g_state++;
        break;
    case (2):
        if ((dir == true) && b) if(fuf->CreateShip(x, y, 3, 'h'))
            g_state++;
        if ((dir == false) && b) if(fuf->CreateShip(x, y, 3, 'v'))
            g_state++;
        break;
    case (3):
        if ((dir == true)  && b) if(fuf->CreateShip(x, y, 3, 'h')) g_state++;
        if ((dir == false) && b) if(fuf->CreateShip(x, y, 3, 'v')) g_state++;
        break;
    case (4):
        if ((dir == true)  && b) if(fuf->CreateShip(x, y, 2, 'h')) g_state++;
        if ((dir == false) && b) if(fuf->CreateShip(x, y, 2, 'v')) g_state++;
        break;

    case (5):
        if ((dir == true)  && b) if(fuf->CreateShip(x, y, 2, 'h')) g_state++;
        if ((dir == false) && b) if(fuf->CreateShip(x, y, 2, 'v')) g_state++;
        break;
    case (6):
        if ((dir == true)  && b) if(fuf->CreateShip(x, y, 2, 'h')) g_state++;
        if ((dir == false) && b) if(fuf->CreateShip(x, y, 2, 'v')) g_state++;
        break;
    case (7):
        if ((dir == true)  && b) if(fuf->CreateShip(x, y, 1, 'h')) g_state++;
        if ((dir == false) && b) if(fuf->CreateShip(x, y, 1, 'v')) g_state++;
        break;
    case (8):
        if ((dir == true)  && b) if(fuf->CreateShip(x, y, 1, 'h')) g_state++;
        if ((dir == false) && b) if(fuf->CreateShip(x, y, 1, 'v')) g_state++;
        break;
    case (9):
        if ((dir == true)  && b) if(fuf->CreateShip(x, y, 1, 'h')) g_state++;
        if ((dir == false) && b) if(fuf->CreateShip(x, y, 1, 'v')) g_state++;
        break;
    case (10):
        if ((dir == true)  && b) if(fuf->CreateShip(x, y, 1, 'h')) g_state++;
        if ((dir == false) && b) if(fuf->CreateShip(x, y, 1, 'v')) g_state++;
        break;
    case (11):
        art->PlaceShipsAI(fcf);
        g_state++;
        break;
    }
}

void GameLogic::MakeMove(int x, int y, bool b)
{
    switch (g_state)
    {
    case (12):
        if (!b)
        {
            fcf->posx = x; fcf->posy = y;
        }
        break;
    }
}

void GameLogic::PlayTheGame(int x, int y, bool b)
{
    cstate s = fcf->GetPosVal();
    if (g_state==12 && !b)
    {
        if (s == fcf->water)
        {
           g_state++;
        }
        clen = fcf->Fire(fcf->posx, fcf->posy);
        if (clen != 0)
        {
            emit LogToCons("Player killed the ship of length " + QString::number(clen));
            clen = 0;
        }
        if (fuf->shipsnum[0] <= 0)
        {
            g_state = 14;
            emit LogToCons("AI Won!");
        }
        if (fcf->shipsnum[0] <= 0)
        {
            g_state = 15;
            emit LogToCons("Player Won!");
        }
    }
    if (g_state==13)
    {
        art->MakeMove(fuf);
        if (fuf->shipsnum[0] <= 0)
        {
            g_state = 14;
            emit LogToCons("AI Won!");
        }
        if (fcf->shipsnum[0] <= 0)
        {
            g_state = 15;
            emit LogToCons("Player Won!");
        }
        g_state--;
    }
}

void GameLogic::Initz()
{
    units lv;
    lv = 0;
    art->Setlevel(lv);

    fuf->shipsnum[0] = 20;			//TODO: ships instead of cells.
    fuf->shipsnum[1] = 4;
    fuf->shipsnum[2] = 3;
    fuf->shipsnum[3] = 2;
    fuf->shipsnum[4] = 1;
    fcf->shipsnum[0] = 20;
    fcf->shipsnum[1] = 4;
    fcf->shipsnum[2] = 3;
    fcf->shipsnum[3] = 2;
    fcf->shipsnum[4] = 1;

    g_state++;
}
