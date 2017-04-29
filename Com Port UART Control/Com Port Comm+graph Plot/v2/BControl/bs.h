#ifndef BS_H
#define BS_H

#include <QDebug>
#include <iostream>
#include <mainwindow.h>
#include <QtMath>
using namespace std;
//class MainWindow;
class BS : public QThread
{
public:
    static bool flag;
    BS();
    ~BS();
//    friend void MainWindow::newData(double x,double y);
protected:
    void run();
};

#endif // BS_H
