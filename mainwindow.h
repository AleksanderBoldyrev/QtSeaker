//*** The class which is using the Qt facilities for the GUI. ***

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
#include <QMessageBox>

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
    void mousePressEvent(QMouseEvent* ev);              // Function processing the mouse interactions.

signals:
    void Clicked(int x, int y, bool cond);              // The signal function used to be emited when the field widget is pressed.

public slots:
    void Log(QString s);                                // Primitive output to the imitated console.
    void P_Changed(int x, int y, int state);            // These functions are called.
    void C_Changed(int x, int y, int state);            // when the field state has changed.
public:
    QCheckBox* cb;
private slots:
    void on_actionAbout_triggered();                    // This is the function made for the About section in help.

private:
    Ui::MainWindow *ui;
    QVector<QVector<QLabel*> > p_cells;
    QVector<QVector<QLabel*> > c_cells;

    int _rows = 10;
    int _cols = 10;
};

#endif // MAINWINDOW_H
