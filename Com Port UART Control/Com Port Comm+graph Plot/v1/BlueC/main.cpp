#include "mainwindow.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    MainWindow t;
    t.show();

    int c=a.exec();
    //qDebug()<<"close";
    t.serial->disconnect();
    t.serial->close();
    //QThread::currentThread()->usleep(1);

    //QThread::currentThread()->msleep(10);
    return c;
}
