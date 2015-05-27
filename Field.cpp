#include "Field.h"

Field::Field(bool who, units sx, units sy)
{
    owner = who;
    posx = 0;
    posy = 0;
    wc = sx;
    wcells = sx;
    hc = sy;
    hcells = sy;
    cells.resize(sx);
    for (int w = 0; w < sx; w++) cells[w].resize(sy);
    for (int w = 0; w < sx; w++) for (int h = 0; h < sy; h++) cells[w][h] = water;
}

Field::~Field()
{
    for (int w = 0; w < wc; w++)
        cells[w].erase(cells[w].begin(), cells[w].end());
    cells.erase(cells.begin(), cells.end());
}

void Field::Wipe()
{
    for (units i = 0; i < wc; i++) for (units j = 0; j < hc; j++) cells[i][j] = water;
}

cstate Field::GetCell(units w, units h)
{
    if (w >= wc || h >= hc) return err;
    else return cells[w][h];
}

void Field::SetCell(units w, units h, cstate s)
{
    cells[w][h] = s;
    if (this->owner == PLAYER) emit P_StateChanged(w, h, s);
    else emit C_StateChanged(w, h, s);
}

bool Field::SetPos(units x, units y)
{
    if (y >= hc || x >= wc) return false;
    posx = x;
    posy = y;
    return true;
}

cstate Field::GetPosVal()
{
    return cells[posx][posy];
}

bool Field::CreateShip(units x, units y, units l, dir vdir)
{
    bool isplaced = false;
    short it = 0;
    if (ShipSpaceIsChecked(x, y, l, vdir))
    {
        if (l == 1)
        {
            SetCell(x, y, onesh);
            isplaced = true;
            return isplaced;
        }
        isplaced = true;
        switch (vdir)
        {
        case ('h') :
            SetCell(x, y, left);
            for (short le = 1; le <= l - 1; le++) { SetCell(x + le, y, hbody); it++; }
            SetCell(x + it, y, right);
            break;
        case ('v') :
            SetCell(x, y, up);
            for (short le = 1; le <= l - 1; le++) { SetCell(x, y + le, vbody); it++; }
            SetCell(x, y + it, down);
            break;
        default:
            //printf("Unknown symbol!");
            break;
        }
    }
    return isplaced;
}

bool Field::CenterCellSpaceIsChecked(units cellx, units celly, units le, dir di, units ord)
{
    bool b = true;
    switch (di)
    {
    case ('h') :
        if (ord == 1)
        {
            if ((this->GetCell(cellx, celly - 1) != water && this->GetCell(cellx, celly - 1) != err) || (this->GetCell(cellx, celly + 1) != water && this->GetCell(cellx, celly + 1) != err) || (this->GetCell(cellx - 1, celly) != water && this->GetCell(cellx - 1, celly) != err) || (this->GetCell(cellx - 1, celly - 1) != water && this->GetCell(cellx - 1, celly - 1) != err) || (this->GetCell(cellx - 1, celly + 1) != water && this->GetCell(cellx - 1, celly + 1) != err) || (this->GetCell(cellx, celly) != water && this->GetCell(cellx, celly) != err) || this->GetCell(cellx, celly) == err)
            {
                b = false;
                return b;
            }
            break;
        }
        if (ord == le)
        {
            if ((this->GetCell(cellx, celly - 1) != water && this->GetCell(cellx, celly - 1) != err) || (this->GetCell(cellx, celly + 1) != water && this->GetCell(cellx, celly + 1) != err) || (this->GetCell(cellx + 1, celly) != water && this->GetCell(cellx + 1, celly) != err) || (this->GetCell(cellx + 1, celly - 1) != water && this->GetCell(cellx + 1, celly - 1) != err) || (this->GetCell(cellx + 1, celly + 1) != water && this->GetCell(cellx + 1, celly + 1) != err) || (this->GetCell(cellx, celly) != water && this->GetCell(cellx, celly) != err) || this->GetCell(cellx, celly) == err)
            {
                b = false;
                return b;
            }
            break;
        }
        else if ((this->GetCell(cellx, celly - 1) != water && this->GetCell(cellx, celly - 1) != err) || (this->GetCell(cellx, celly + 1) != water && this->GetCell(cellx, celly + 1) != err) || (this->GetCell(cellx, celly) != water && this->GetCell(cellx, celly) != err) || (this->GetCell(cellx, celly) != water && this->GetCell(cellx, celly) != err) || this->GetCell(cellx, celly) == err)
        {
            b = false;
            return b;
        }
        break;
    case ('v') :
        if (ord == 1)
        {
            if ((this->GetCell(cellx, celly - 1) != water && this->GetCell(cellx, celly - 1) != err) || (this->GetCell(cellx + 1, celly) != water && this->GetCell(cellx + 1, celly) != err) || (this->GetCell(cellx - 1, celly) != water && this->GetCell(cellx - 1, celly) != err) || (this->GetCell(cellx - 1, celly - 1) != water && this->GetCell(cellx - 1, celly - 1) != err) || (this->GetCell(cellx + 1, celly - 1) != water && this->GetCell(cellx + 1, celly - 1) != err) || (this->GetCell(cellx, celly) != water && this->GetCell(cellx, celly) != err) || this->GetCell(cellx, celly) == err)
            {
                b = false;
                return b;
            }
            break;
        }
        if (ord == le)
        {
            if ((this->GetCell(cellx, celly + 1) != water && this->GetCell(cellx, celly + 1) != err) || (this->GetCell(cellx + 1, celly) != water && this->GetCell(cellx + 1, celly) != err) || (this->GetCell(cellx - 1, celly) != water && this->GetCell(cellx - 1, celly) != err) || (this->GetCell(cellx - 1, celly + 1) != water && this->GetCell(cellx - 1, celly + 1) != err) || (this->GetCell(cellx + 1, celly + 1) != water && this->GetCell(cellx + 1, celly + 1) != err) || (this->GetCell(cellx, celly) != water && this->GetCell(cellx, celly) != err) || this->GetCell(cellx, celly) == err)
            {
                b = false;
                return b;
            }
            break;
        }
        else if ((this->GetCell(cellx - 1, celly) != water && this->GetCell(cellx - 1, celly) != err) || (this->GetCell(cellx + 1, celly) != water && this->GetCell(cellx + 1, celly) != err) || (this->GetCell(cellx, celly) != water && this->GetCell(cellx, celly) != err) || this->GetCell(cellx, celly) == err)
        {
            b = false;
            return b;
        }
        break;
    }
    return b;
}

bool Field::ShipSpaceIsChecked(units x, units y, units l, dir vdir)
{
    bool b = true;
    unsigned short order = 1;
    units vx = x, vy = y;
    if (l == 1)
    {
        if ((this->GetCell(x, y + 1) != water && this->GetCell(x, y + 1) != err) || (this->GetCell(x + 1, y) != water && this->GetCell(x + 1, y) != err) || (this->GetCell(x - 1, y) != water && this->GetCell(x - 1, y) != err) || (this->GetCell(x, y - 1) != water && this->GetCell(x, y - 1) != err) || (this->GetCell(x + 1, y + 1) != water && this->GetCell(x + 1, y + 1) != err) || (this->GetCell(x + 1, y - 1) != water && this->GetCell(x + 1, y - 1) != err) || (this->GetCell(x - 1, y + 1) != water && this->GetCell(x - 1, y + 1) != err) || (this->GetCell(x - 1, y - 1) != water && this->GetCell(x - 1, y - 1) != err) || (this->GetCell(x, y) != water && this->GetCell(x, y) != err))
        {
            b = false;
            return b;
        }
    }
    switch (vdir)
    {
    case ('h') :
        for (; vx <= l - 1 + x; vx++)
        {
            if (!CenterCellSpaceIsChecked(vx, vy, l, vdir, order))
            {
                b = false;
                return b;
            }
            order++;
        }
        break;
    case ('v') :
        for (; vy <= l - 1 + y; vy++)
        {
            if (!CenterCellSpaceIsChecked(vx, vy, l, vdir, order))
            {
                b = false;
                return b;
            }
            order++;
        }
        break;
    }
    return b;
}

unsigned short Field::Aftermath(units px, units py)
{
    unsigned short countlen = 0, lencheck = 1, posxs = px, posys = py;
    this->SetPos(px,py);
    cstate cs = this->GetPosVal();
    if (cs == onesh)
        countlen = 1;
    else if (cs == left)
    {
        px++;
        this->SetPos(px, py);
        cs = this->GetPosVal();
        while (cs == hit && px < (this->Width()-1))
        {
            px++;
            this->SetPos(px, py);
            cs = this->GetPosVal();
            lencheck++;
        }
        if (px == (this->Width()-1) && cs == hit) lencheck++;
        if (cs == miss || cs == water || (px == (this->Width()-1) && cs == hit)) countlen = lencheck;
    }
    else if (cs == right)
    {
        px--;
        this->SetPos(px, py);
        cs = this->GetPosVal();
        while (cs == hit && px > 0)
        {
            px--;
            this->SetPos(px, py);
            cs = this->GetPosVal();
            lencheck++;
        }
        if (px == 0 && cs == hit) lencheck++;
        if (cs == miss || cs == water || (px == 0 && cs == hit)) countlen = lencheck;
    }
    else if (cs == up)
    {
        py++;
        this->SetPos(px, py);
        cs = this->GetPosVal();
        //lencheck++;
        while (cs == hit && py < (this->Height()-1))
        {
            py++;
            this->SetPos(px, py);
            cs = this->GetPosVal();
            lencheck++;
        }
        if (py == (this->Height()-1) && cs == hit) lencheck++;
        if (cs == miss || cs == water || (py == (this->Height()-1) && cs == hit)) countlen = lencheck;
    }
    else if (cs == down)
    {
        py--;
        this->SetPos(px, py);
        cs = this->GetPosVal();
        //lencheck++;
        while (cs == hit && py > 0)
        {
            py--;
            this->SetPos(px, py);
            cs = this->GetPosVal();
            lencheck++;
        }
        if (py == 0 && cs == hit) lencheck++;
        if (cs == miss || cs == water || (py == 0 && cs == hit)) countlen = lencheck;
    }
    else if (cs == hbody)
    {
        bool l = false, r = false;
        px++;
        this->SetPos(px, py);
        cs = this->GetPosVal();
        while (cs == hit && px < (this->Width()-1))
        {
            px++;
            this->SetPos(px, py);
            cs = this->GetPosVal();
            lencheck++;
        }
        if (px == (this->Width()-1) && cs == hit) lencheck++;
        if (cs == miss || cs == water || (px == (this->Width()-1) && cs == hit)) r = true;
        px = posxs;
        px--;
        this->SetPos(px, py);
        cs = this->GetPosVal();
        while (cs == hit && px > 0)
        {
            px--;
            this->SetPos(px, py);
            cs = this->GetPosVal();
            lencheck++;
        }
        if (px == 0 && cs == hit) lencheck++;
        if (cs == miss || cs == water || (px == 0 && cs == hit)) l = true;
        if (l == true && r == true)
            countlen = lencheck;
    }
    else if (cs == vbody)
    {
        bool u = false, d = false;
        py++;
        this->SetPos(px, py);
        cs = this->GetPosVal();
        //lencheck++;
        while (cs == hit && py < (this->Height()-1))
        {
            py++;
            this->SetPos(px, py);
            cs = this->GetPosVal();
            lencheck++;
        }
        if (py == (this->Height()-1) && cs == hit) lencheck++;
        if (cs == miss || cs == water || (py == (this->Height()-1) && cs == hit)) d = true;
        py = posys;
        py--;
        this->SetPos(px, py);
        cs = this->GetPosVal();
        //lencheck++;
        while (cs == hit && py > 0)
        {
            py--;
            this->SetPos(px, py);
            cs = this->GetPosVal();
            lencheck++;
        }
        if (py == 0 && cs == hit) lencheck++;
        if (cs == miss || cs == water || (py == 0 && cs == hit)) u = true;
        if (u == true && d == true)
            countlen = lencheck;
    }
    px = posxs; py = posys;
    this->SetPos(px, py);
    if (countlen != 0) this->shipsnum[countlen]--;
    return countlen;
}

unsigned short Field::Fire(units px, units py)
{
    unsigned short count = 0;
    cstate st = this->GetPosVal();
    if (st != this->water && st != this->hit && st != this->miss)
    {
        count = Aftermath(px, py);
        SetCell(px, py, hit);
        this->shipsnum[0]--;
    }
    else if (st == this->water)
    {
        SetCell(px, py, miss);
    }
    return count;
}
