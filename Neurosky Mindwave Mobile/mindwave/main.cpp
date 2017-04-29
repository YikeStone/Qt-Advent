#include <QCoreApplication>
#include<Loop.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Loop b;
    b.start();
    int c = a.exec();
    b.flag = 0;b.disconnect();
    return c;
}
