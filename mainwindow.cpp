#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    cb = ui->checkBox;

    p_cells.resize(10);
    for (int i = 0; i < 10; i++) p_cells[i].resize(10);


    for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++)
    {
        p_cells[i][j]=new QLabel(ui->w1, 0);
        int sx = (ui->w1->geometry().width())/_cols;
        int sy = (ui->w1->geometry().height())/_cols;
        p_cells[i][j]->setGeometry(i*sx, j*sy, sx, sy);
    }


    c_cells.resize(10);
    for (int i = 0; i < 10; i++) c_cells[i].resize(10);


    for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++)
    {
        c_cells[i][j]=new QLabel(ui->w2, 0);
        int sx = (ui->w2->geometry().width())/_cols;
        int sy = (ui->w2->geometry().height())/_cols;
        c_cells[i][j]->setGeometry(i*sx, j*sy, sx, sy);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    int xx = ev->x(), yy = ev->y() - 40;

    int w1x1 = ui->w1->geometry().x();
    int w1y1 = ui->w1->geometry().y();
    int w2x1 = ui->w2->geometry().x();
    int w2y1 = ui->w2->geometry().y();
    int w1x2 = ui->w1->geometry().x() + ui->w1->geometry().width();
    int w1y2 = ui->w1->geometry().y() + ui->w1->geometry().height();
    int w2x2 = ui->w2->geometry().x() + ui->w2->geometry().width();
    int w2y2 = ui->w2->geometry().y() + ui->w2->geometry().height();

    int i = 0, j = 0;

    if (xx >= w1x1 && xx <= w1x2 && yy >= w1y1 && yy <= w1y2)
    {
        i = ui->w1->geometry().width()/_cols;
        j = ui->w1->geometry().height()/_cols;
        emit Clicked(floor((xx - w1x1)/i), floor((yy - w1y1)/j), true);
    }
    else if (xx >= w2x1 && xx <= w2x2 && yy >= w2y1 && yy <= w2y2)
    {
        i = ui->w2->geometry().width()/_cols;
        j = ui->w2->geometry().height()/_cols;
        emit Clicked(floor((xx - w2x1))/i, floor((yy - w2y1)/j), false);
    }
}

void MainWindow::Log(QString s)
{
    ui->console->appendPlainText(s);
}

void MainWindow::C_Changed(int x, int y, int state)
{
    switch(state)
    {
    case (0x20):
        c_cells[x][y]->setStyleSheet("");
        c_cells[x][y]->repaint();
        break;
    case (0x06):
        c_cells[x][y]->setStyleSheet("background-image: url(:/files/HitMan.png);");
        c_cells[x][y]->repaint();
        break;
    case (0x0F):
        c_cells[x][y]->setStyleSheet("background-image: url(:/files/Miss.png);");
        c_cells[x][y]->repaint();
        break;
    }
}

void MainWindow::P_Changed(int x, int y, int state)
{
    switch(state)
    {
    case (0x20):
        p_cells[x][y]->setStyleSheet("");
        break;
    case (0xFE):
        p_cells[x][y]->setStyleSheet("background-image: url(:/files/HBody.png);");
        break;
    case (0xFD):
        p_cells[x][y]->setStyleSheet("background-image: url(:/files/VBody.png);");
        break;
    case (0x04):
        p_cells[x][y]->setStyleSheet("background-image: url(:/files/Single.png);");
        break;
    case (0x11):
        p_cells[x][y]->setStyleSheet("background-image: url(:/files/Left.png);");
        break;
    case (0x10):
        p_cells[x][y]->setStyleSheet("background-image: url(:/files/Right.png);");
        break;
    case (0x1E):
        p_cells[x][y]->setStyleSheet("background-image: url(:/files/Up.png);");
        break;
    case (0x1F):
        p_cells[x][y]->setStyleSheet("background-image: url(:/files/Down.png);");
        break;
    case (0x06):
        p_cells[x][y]->setStyleSheet("background-image: url(:/files/HitMan.png);");
        break;
    case (0x0F):
        p_cells[x][y]->setStyleSheet("background-image: url(:/files/Miss.png);");
        break;
    }
}
