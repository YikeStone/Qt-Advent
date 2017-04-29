#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QKeyEvent"
#include "QDebug"
#include <QCoreApplication>
#include <QtCore/QCoreApplication>
//#include "bs.h"
int KP[44];double kp=3,ki=0,kd=0;int kp1=3,ki1=0,kd1=0;double pkp=0, pki = 0,pkd = 0;int pwm_left,pwm_right;
QString cmd("");
int a=0;
long t;
double xa=0,ya=0,za=0;
double xg=0,yg=0,zg=0;
double xxa,yya,zza;double kp2 = 10;
double ki2 = 0;
double kd2 = 0;
double g1;
double ra=0,rollg=0;const float alpha = 0.5;
QElapsedTimer f;
IMUfilter *imufilter;
QByteArray ba("");
int outMax = 255;
int outMin = -255;
float lastInput = 0;
double ITerm =0;
double Setpoint = 0;
double gg=0;

char blankString[] = QT_TRANSLATE_NOOP("SettingsDialog", "N/A");
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);
    QSerialPortInfo info=QSerialPortInfo::availablePorts().at(0);
    // Check info of the port
    qDebug() << "Name        : " << info.portName();
    /*qDebug() << "Manufacturer: " << info.manufacturer(); //if showing manufacturer, means Qstring &name is good
    qDebug() << "Busy: " << info.isBusy() << endl;
    */// Initialize Serial
    serial->setPortName("COM8");
    //serial->open(QIODevice::ReadWrite);
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    if(serial->open(QIODevice::ReadWrite));
    /*QString description;
    QString manufacturer;
    QString serialNumber;int i=0;
    /*foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        cout<<i++;
        description = info.description();
        manufacturer = info.manufacturer();
        serialNumber = info.serialNumber();
        qDebug() << info.portName()<<"  "
             << (!description.isEmpty() ? description : blankString)<<"  "
             << (!manufacturer.isEmpty() ? manufacturer : blankString)<<"  "
             << (!serialNumber.isEmpty() ? serialNumber : blankString)<<"  "
             << info.systemLocation()<<"  "
             << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : blankString)<<"  "
             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : blankString)<<info.isBusy()<<" \n ";}*/
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(readData()));
    timer->start(10);
    // create graph and assign data to it:
    ui->widget_1->legend->setVisible(true);
    //ui->widget->addGraph()->setName("AccelAng");
    ui->widget_1->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    //ui->widget->axisRect()->setRangeZoom(Qt::Horizontal | Qt::Vertical);
    ui->widget_1->axisRect()->setRangeZoom(Qt::Horizontal);
    ui->widget_1->axisRect()->setRangeZoomFactor(1.5);

    ui->widget_2->legend->setVisible(true);
    //ui->widget->addGraph()->setName("AccelAng");
    ui->widget_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    //ui->widge->axisRect()->setRangeZoom(Qt::Horizontal | Qt::Vertical);
    ui->widget_2->axisRect()->setRangeZoom(Qt::Horizontal);
    ui->widget_2->axisRect()->setRangeZoomFactor(1.5);

    ui->widget_3->legend->setVisible(true);
    //ui->widget->addGraph()->setName("AccelAng");
    ui->widget_3->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    //ui->widge->axisRect()->setRangeZoom(Qt::Horizontal | Qt::Vertical);
    ui->widget_3->axisRect()->setRangeZoom(Qt::Horizontal);
    ui->widget_3->axisRect()->setRangeZoomFactor(1.5);

    ui->widget_4->legend->setVisible(true);
    //ui->widge->addGraph()->setName("AccelAng");
    ui->widget_4->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    //ui->widget->axisRect()->setRangeZoom(Qt::Horizontal | Qt::Vertical);
    ui->widget_4->axisRect()->setRangeZoom(Qt::Horizontal);
    ui->widget_4->axisRect()->setRangeZoomFactor(1.5);

    ui->widget_5->legend->setVisible(true);
    //ui->widget->addGraph()->setName("AccelAng");
    ui->widget_5->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    //ui->widget->axisRect()->setRangeZoom(Qt::Horizontal | Qt::Vertical);
    ui->widget_5->axisRect()->setRangeZoom(Qt::Horizontal);
    ui->widget_5->axisRect()->setRangeZoomFactor(1.5);

    ui->widget_1->addGraph()->setName("AccelAngle");
    ui->widget_2->addGraph()->setName("GyroAngle");
    ui->widget_3->addGraph()->setName("CompFilterAngle");
    ui->widget_4->addGraph()->setName("KalmanFilterAngle");
    ui->widget_5->addGraph()->setName("AccelAngle");
    ui->widget_5->addGraph()->setName("GyroAngle");
    ui->widget_5->addGraph()->setName("CompFilterAngle");
    ui->widget_5->addGraph()->setName("KalmanFilterAngle");
    //ui->widget->addGraph()->setName("Displacement");
    //ui->widget->graph(0)->setData(x, y);

    ui->widget_1->xAxis->setLabel("Time(s)->");
    ui->widget_1->yAxis->setLabel("Angle(°)");
    ui->widget_2->xAxis->setLabel("Time(s)->");
    ui->widget_2->yAxis->setLabel("Angle(°)");
    ui->widget_3->xAxis->setLabel("Time(s)->");
    ui->widget_3->yAxis->setLabel("Angle(°)");
    ui->widget_4->xAxis->setLabel("Time(s)->");
    ui->widget_4->yAxis->setLabel("Angle(°)");
    ui->widget_5->xAxis->setLabel("Time(s)->");
    ui->widget_5->yAxis->setLabel("Angle(°)");

    ui->widget_1->graph(0)->setPen(QPen(Qt::red));
    ui->widget_2->graph(0)->setPen(QPen(Qt::green));
    ui->widget_3->graph(0)->setPen(QPen(Qt::blue));
    ui->widget_4->graph(0)->setPen(QPen(Qt::black));
    ui->widget_5->graph(0)->setPen(QPen(Qt::red));
    ui->widget_5->graph(1)->setPen(QPen(Qt::green));
    ui->widget_5->graph(2)->setPen(QPen(Qt::blue));
    ui->widget_5->graph(3)->setPen(QPen(Qt::black));

    //ui->widget->graph(4)->setPen(QPen(Qt::cyan));
    ui->widget_1->xAxis->setRange(0,20);
    ui->widget_1->yAxis->setRange(20,-20);
    ui->widget_2->xAxis->setRange(0,20);
    ui->widget_2->yAxis->setRange(20,-20);
    ui->widget_3->xAxis->setRange(0,20);
    ui->widget_3->yAxis->setRange(20,-20);
    ui->widget_4->xAxis->setRange(0,20);
    ui->widget_4->yAxis->setRange(20,-20);
    ui->widget_5->xAxis->setRange(0,20);
    ui->widget_5->yAxis->setRange(20,-20);




    //imufilter = new IMUfilter(0.015, 20);

}

MainWindow::~MainWindow()
{
    timer->stop();
    QFile file1("C:/Users/yikes/Desktop/graph1.jpg");
    ui->widget_1->saveJpg( "C:/Users/yikes/Desktop/graph1.jpg",  0, 0, 1.0, -1  );
    QFile file2("C:/Users/yikes/Desktop/graph2.jpg");
    ui->widget_2->saveJpg( "C:/Users/yikes/Desktop/graph2.jpg",  0, 0, 1.0, -1  );
    QFile file3("C:/Users/yikes/Desktop/graph3.jpg");
    ui->widget_3->saveJpg( "C:/Users/yikes/Desktop/graph3.jpg",  0, 0, 1.0, -1  );
    QFile file4("C:/Users/yikes/Desktop/graph4.jpg");
    ui->widget_4->saveJpg( "C:/Users/yikes/Desktop/graph4.jpg",  0, 0, 1.0, -1  );
    QFile file5("C:/Users/yikes/Desktop/graph5.jpg");
    ui->widget_5->saveJpg( "C:/Users/yikes/Desktop/graph5.jpg",  0, 0, 1.0, -1  );

    delete ui;
}

void MainWindow::newData_1(double w,double t)
{
    ui->widget_1->graph(0)->addData(t,w);
    ui->widget_5->graph(0)->addData(t,w);
    ui->widget_1->replot();
    ui->widget_5->replot();

}
void MainWindow::newData_2(double w,double t)
{
    ui->widget_2->graph(0)->addData(t,w);
    ui->widget_5->graph(1)->addData(t,w);
    ui->widget_2->replot();
    ui->widget_5->replot();
}
void MainWindow::newData_3(double w,double t)
{
    ui->widget_3->graph(0)->addData(t,w);
    ui->widget_5->graph(2)->addData(t,w);
    ui->widget_3->replot();
    ui->widget_5->replot();

}
void MainWindow::newData_4(double w,double t)
{
    ui->widget_4->graph(0)->addData(t,w);
    ui->widget_5->graph(3)->addData(t,w);
    ui->widget_4->replot();
    ui->widget_5->replot();
}



double zoff,xoff;volatile int ch=0;int aa=0;
double compAngleY=0;double gyroYangle;
void MainWindow::readData()
{

    //timer->stop();
    if(ch==1)return;
    x:;
        if(!(serial->bytesAvailable()>25))return;
        ch=1;
    double g=0,xs,ys,zs;
    int i,j,k,l,m,n,o;
    //QThread::currentThread()->sleep(10);
    //while(serial->bytesAvailable()>2){
        QThread::currentThread()->msleep(1);
    char c[1];
    while(1)
    {
        if(!(serial->bytesAvailable())){ch=0;return;}
        serial->read(c,1);
        if(c[0]=='a')
        {
            if(!(serial->bytesAvailable()>25))
               QThread::currentThread()->msleep(1);
                break;
        }
    }
    QByteArray data = serial->readLine();
    qDebug()<<data;
    //if(data[0]!='a')goto x;
    i = data.indexOf(',');
    j = data.indexOf(',',i+1);
    k = data.indexOf(',',j+1);
    l = data.indexOf(',',k+1);
    //n = data.indexOf(',',l+1);
    //o = data.indexOf(',',n+1);
    //if(k==-1)goto x;
    //if(j==-1)goto x;
    //if(i==-1)goto x;
    //m = data.indexOf(',',l+1);
    //j = data.indexOf(' ',i+1);
    //k = data.indexOf(' ',j+1);
    //l = data.indexOf(' ',k+1);
    m = data.indexOf('\n');
    if(m==-1){ch=0;return;}
   // qDebug()<<i<<j<<k<<l<<m;
    //QThread::currentThread()->sleep(1);
    xs=data.mid(0,i-1).toDouble();
    xa=data.mid(i+1,j-i-1).toDouble();
    //QThread::currentThread()->sleep(1);
    ya=data.mid(j+1,k-j-1).toDouble();
    za=data.mid(k+1,l-k-1).toDouble();
    //ys=data.mid(l+1,n-l-1).toDouble();
    //g= data.mid(n+1,o-n-1).toDouble();
    //double pitch = atan(-xs / sqrt(xa * xa + ya * ya)) * 57.2958;
    //compAngleY = 0.93 * (compAngleY + za * 0.015) + 0.07 * pitch;
    /*imufilter->updateFilter(za,ys,g,xs*10.0,xa*10.0,ya*10.0);
    imufilter->computeEuler();
    double temp = imufilter->getPitch()* 57.2958;;
    */
    //gyroYangle += za * 0.015;
    //if (gyroYangle < -180 || gyroYangle > 180)
    //    gyroYangle = compAngleY;
    //zs=data.mid(l+1,m-l-1).toDouble();
    /*if(data[1]=='1')
    {
        xa=data.mid(i+1,j-i-1).toDouble();
        ya=data.mid(j+1,k-j-1).toDouble();
        za=data.mid(k+1,data.length()-k-2).toDouble();
    }
    else
    {
        xg=data.mid(i+1,j-i-1).toDouble();
        yg=data.mid(j+1,k-j-1).toDouble();
        zg=data.mid(k+1,data.length()-k-1).toDouble();
    }
    rollg+=yg;
    xxa = xa * alpha + (xxa * (1.0 - alpha));
    zza = za * alpha + (zza * (1.0 - alpha));
    ra= 0.98* (rollg) +   ((qAtan2(-zza, xxa)*180.0))/(3.141592653);
    //qDebug()<<f.elapsed();
    int zzz = Compute(ra);*/
    //qDebug()<<data;
    //qDebug()<<(k+1)<<(l-k-1);
    //if(t>40000){gg+=g*(t-f.elapsed())/1000;}
    //xs=atan2(za,-ya)*57.2958;
    //ra= 0.96* (ra+gg) + 0.04*xs;
    //double angle = atan2(-za,xa);
    //qDebug()<<i<<j<<k<<l<<m;

    qDebug()<<xs<<xa<<ya<<za<<f.elapsed()<<endl;

    //if(f.elapsed()>40000)

        if(aa==0) f.start();aa=1;
    t=f.elapsed();
    newData_1(xs,t/1000.0);
    newData_2(xa,t/1000.0);
    newData_3(ya,t/1000.0);
    newData_4(za,t/1000.0);
    if(serial->bytesAvailable()>25) goto x;
    else ch=0;
        }



/*void MainWindow::mouseWheel()
{
    //ui->widget->replot();

}
*/
