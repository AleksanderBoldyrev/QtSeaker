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

// Function processing the mouse interactions.
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

// Primitive output to the imitated console.
void MainWindow::Log(QString s)
{
    ui->console->appendPlainText(s);
}

// This function is called when the field state has changed.
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

// This function is called when the field state has changed.
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

// This is the function made for the About section widget in help.
void MainWindow::on_actionAbout_triggered()
{
    QMessageBox* helpWindow = new QMessageBox(this);
    QIcon* ico = new QIcon("image: url(:/files/Sand16.png);");
    //*** TODO ***
    helpWindow->setWindowTitle("Know How!");
    helpWindow->setWindowIcon(*ico);
    helpWindow->setText("\t#The Rules to play  the Seaker game#\n1> The movement keys: 'w'(~up), 's'(~down), 'a'(~left), 'd'(~right).\n2> To place a ship use a spacebar key.\n3> To choose a ship's length use the numeric keys (1--4).\n4> To shoot at the field use the key 'f'.\n5> To exit the game use the 'x' key.\n6> Created and designed by Alexander Boldyrev, 2015.\nP.S. 7> Don't look into my source code! (Nothing interesting, but harmful).");
    helpWindow->show();
}
