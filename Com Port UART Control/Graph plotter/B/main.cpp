//#include "mainwindow.h"
#include <QApplication>

#include "bs.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //BS t;
    w.show();
    int c=a.exec();

    //qDebug()<<"close";
    w.serial->disconnect();
    w.serial->close();
    //QThread::currentThread()->usleep(1);

    //QThread::currentThread()->msleep(10);
    return c;
}
