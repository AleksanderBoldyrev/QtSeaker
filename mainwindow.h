#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QGridLayout>
#include <QWidget>
#include <QVector>
#include <QPushButton>
#include <QString>
#include <QCheckBox>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void mousePressEvent(QMouseEvent* ev);

signals:
    void Clicked(int x, int y, bool cond);

public slots:
    void Log(QString s);
    void P_Changed(int x, int y, int state);
    void C_Changed(int x, int y, int state);
public:
    QCheckBox* cb;
private:
    Ui::MainWindow *ui;
    QVector<QVector<QLabel*> > p_cells;
    QVector<QVector<QLabel*> > c_cells;

    int _rows = 10;
    int _cols = 10;
};

#endif // MAINWINDOW_H
