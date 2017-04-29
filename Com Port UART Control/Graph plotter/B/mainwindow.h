#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <iostream>
#include <QThread>
#include <QtMath>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "IMUFilter.h"
using namespace std;
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSerialPort *serial;
    QTimer *timer;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    Ui::MainWindow *ui;
protected:
    void run();
    void newData_1(double w, double t);
        void newData_2(double w, double t);
            void newData_3(double w, double t);
                void newData_4(double w, double t);
private slots:
    void readData();
    //void mouseWheel();
};

#endif // MAINWINDOW_H
