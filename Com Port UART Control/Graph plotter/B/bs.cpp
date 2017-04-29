#include <QElapsedTimer>

#include "bs.h"

BS::BS():QThread(),MainWindow()
{

}

BS::~BS()
{
}

void BS::run()
{
    f.start();
    //QByteArray baa = MainWindow::getArray();
    //cout<<baa.toStdString();
    QThread::currentThread()->yieldCurrentThread();
    while(flag){
        if(serial->isReadable())
        {

            QThread::currentThread()->sleep(50);
        }
    }

    flag=1;
}

