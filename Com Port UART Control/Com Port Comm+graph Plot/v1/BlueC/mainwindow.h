#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <iostream>
#include <QThread>
#include <QtMath>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
//#include "bs.h"
using namespace std;
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSerialPort *serial;
    QSerialPort *serial2;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void BlueP();
protected:
    void newData(double x, double y);

private slots:
    void value0(int);
    void value1(int);
    void value2(int);
    void value3(int);
    void value4(int);
    void value5(int);
    void value6(int);
    void value7(int);
    void value8();
    void value9();
    void value10();
    void value11();
    void value12();
    void value13();
    void value14();
    void value15();
    void value16();
    void value17();
    void readData();
    void readData1();
    //void mouseWheel();
};

#endif // MAINWINDOW_H
