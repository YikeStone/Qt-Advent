#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QKeyEvent"
#include "QDebug"
#include <QCoreApplication>
#include <QtCore/QCoreApplication>
//#include "bs.h"
int KP[44];double kp=0,ki=0,kd=0;int kp1=0,ki1=0,kd1=0;int pwm_left,pwm_right;
int a=-1;
double xa=0,ya=0,za=0;
double xg=0,yg=0,zg=0;
double xxa,yya,zza;double kp2 = 10;
double ki2 = 0;
double kd2 = 0;
double ra=0,rollg=0;const float alpha = 0.5;
QElapsedTimer f;
QByteArray ba("Hello\n");
int outMax = 255;
int outMin = -255;
float lastInput = 0;
double ITerm =0;
double Setpoint = 11;
double Compute(double input)
{
      double error =  Setpoint - input ;
      //qDebug()<<error;
      ITerm+= (ki * error);
      if(ITerm > outMax) ITerm= outMax;
      else if(ITerm < outMin) ITerm= outMin;
      double dInput = (input - lastInput);
      double output = kp * error + ITerm + kd * dInput;
      if(output > outMax) output = outMax;
      else if(output < outMin) output = outMin;
      lastInput = input;
      return output;
}
char blankString[] = QT_TRANSLATE_NOOP("SettingsDialog", "N/A");
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    f.start();
    ui->setupUi(this);
    serial = new QSerialPort(this);
    serial2 = new QSerialPort(this);
    QSerialPortInfo info1=QSerialPortInfo::availablePorts().at(1);
    QSerialPortInfo info=QSerialPortInfo::availablePorts().at(0);
    // Check info of the port
    qDebug() << "Name        : " << info.portName();
    /*qDebug() << "Manufacturer: " << info.manufacturer(); //if showing manufacturer, means Qstring &name is good
    qDebug() << "Busy: " << info.isBusy() << endl;
    */// Initialize Serial
    qDebug()<<info1.portName();
    serial2->setPortName("COM8");
    serial->setPortName("COM17");
    //serial->open(QIODevice::ReadWrite);
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    if(serial->open(QIODevice::ReadWrite));
    serial2->setBaudRate(QSerialPort::Baud115200);
    serial2->setDataBits(QSerialPort::Data8);
    serial2->setParity(QSerialPort::NoParity);
    serial2->setStopBits(QSerialPort::OneStop);
    serial2->setFlowControl(QSerialPort::NoFlowControl);
    if(serial2->open(QIODevice::ReadWrite));
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
    ui->textBrowser->setText("Key(s) Pressed:");
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(value0(int)));
    connect(ui->horizontalSlider_2,SIGNAL(valueChanged(int)),this,SLOT(value1(int)));
    connect(ui->horizontalSlider_3,SIGNAL(valueChanged(int)),this,SLOT(value2(int)));
    connect(ui->horizontalSlider_5,SIGNAL(valueChanged(int)),this,SLOT(value3(int)));
    connect(ui->horizontalSlider_4,SIGNAL(valueChanged(int)),this,SLOT(value4(int)));
    connect(ui->horizontalSlider_6,SIGNAL(valueChanged(int)),this,SLOT(value5(int)));
    connect(ui->horizontalSlider_7,SIGNAL(valueChanged(int)),this,SLOT(value6(int)));
    connect(ui->horizontalSlider_8,SIGNAL(valueChanged(int)),this,SLOT(value7(int)));
    connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(value8()));
    connect(ui->lineEdit_2,SIGNAL(returnPressed()),this,SLOT(value9()));
    connect(ui->lineEdit_3,SIGNAL(returnPressed()),this,SLOT(value10()));
    connect(ui->lineEdit_4,SIGNAL(returnPressed()),this,SLOT(value11()));
    connect(ui->lineEdit_5,SIGNAL(returnPressed()),this,SLOT(value12()));
    connect(ui->lineEdit_6,SIGNAL(returnPressed()),this,SLOT(value13()));
    connect(ui->lineEdit_7,SIGNAL(returnPressed()),this,SLOT(value14()));
    connect(ui->lineEdit_8,SIGNAL(returnPressed()),this,SLOT(value15()));
    connect(ui->radioButton,SIGNAL(pressed()),this,SLOT(value16()));
    connect(ui->radioButton_2,SIGNAL(pressed()),this,SLOT(value17()));
    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(serial2, SIGNAL(readyRead()), this, SLOT(readData1()));
    for(int i=0;i<44;i++)
        KP[i]=0;
    /*QVector<double> x(101), y(101); // initialize with entries 0..100
      for (int i=0; i<101; ++i)
      {
        x[i] = i/50.0 - 1; // x goes from -1 to 1
        y[i] = x[i]*x[i];  // let's plot a quadratic function
      }*/
    // create graph and assign data to it:
    ui->widget->addGraph();
    ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->widget->axisRect()->setRangeZoom(Qt::Horizontal);
    ui->widget->axisRect()->setRangeZoomFactor(1.5);
    //ui->widget->graph(0)->setData(x, y);
    ui->widget->xAxis->setLabel("X Axis");
    ui->widget->yAxis->setLabel("Y Axis");
    ui->widget->xAxis->setRange(0,1000);
    ui->widget->yAxis->setRange(-90,90);
}

MainWindow::~MainWindow()
{

    delete ui;
}
void MainWindow::BlueP()
{
    QString b("");
    for(int i=0;i<44;i++)
        if(KP[i]==1)b.append(i+47);
    b.append("\n");
    ba.clear();
    ui->textBrowser->setText("Key(s) Pressed:"+b);

    if(a==-1)
    {
        if(b.length()>1){
            ba.append(b.toUtf8());
        }
        else
        {
            ba.append("stop\n");
        }
    }
    else{
        QString s("");
        /*s.append("l");
        s.append(QString::number(pwm_left,'g',9));
        s.append("\nr");
        s.append(QString::number(pwm_right,'g',9));
        //s.append("\n");//only for pwm
        s.append("\n");*/
        s.append("p");
        s.append(QString::number(kp,'g',9));
        s.append(",i");
        s.append(QString::number(ki,'g',9));
        s.append(",d");
        s.append(QString::number(kd,'g',9));
        s.append(",");
        ba=s.toUtf8();
    }

    if (serial->isOpen() && serial->isWritable())
    {
        serial->write(ba);
        if (serial->bytesToWrite() > 0)
        {
            serial->flush();
            serial->bytesWritten(ba.length());
        }
    }
    else
    {
        cout<< "An error occured" << endl;
    }
    //QThread::currentThread()->msleep(1000);
}
void MainWindow::keyPressEvent(QKeyEvent * event)
{
    int p=event->key();
    if(p>46&&p<91){
        KP[p-47]=1;
        BlueP();
    }
}
void MainWindow::keyReleaseEvent(QKeyEvent * event)
{
    int r=event->key();
    if(r>46&&r<91){
    KP[r-47]=0;
    BlueP();}
}

void MainWindow::value0(int k)
{
    pwm_left=k-255;
    ui->lineEdit->setText(QString::number(pwm_left));
    BlueP();
}

void MainWindow::value1(int k)
{

    pwm_right=k-255;
    ui->lineEdit_2->setText(QString::number(pwm_right));
    BlueP();
}
void MainWindow::value2(int k)
{

    kp=k/10000000.0+kp1;
    ui->lineEdit_3->setText(QString::number(kp,'g',9));
    BlueP();
}
void MainWindow::value3(int k)
{

    ki=k/10000000.0+ki1;
    ui->lineEdit_5->setText(QString::number(ki,'g',9));
    BlueP();
}
void MainWindow::value4(int k)
{

    kd=k/10000000.0+kd1;
    ui->lineEdit_4->setText(QString::number(kd,'g',9));
    BlueP();
}
void MainWindow::value5(int k)
{

    kp=kp-kp1+k;
    kp1=k;
    ui->lineEdit_8->setText(QString::number(kp1));
    ui->lineEdit_3->setText(QString::number(kp,'g',9));
    BlueP();
}

void MainWindow::value6(int k)
{

    ki=ki-ki1+k;
    ki1=k;
    ui->lineEdit_7->setText(QString::number(ki1));
    ui->lineEdit_5->setText(QString::number(ki,'g',9));
    BlueP();
}

void MainWindow::value7(int k)
{

    kd=kd-kd1+k;
    kd1=k;
    ui->lineEdit_6->setText(QString::number(kd1));
    ui->lineEdit_4->setText(QString::number(kd,'g',9));
    BlueP();
}

void MainWindow::value8()
{
    QString s=ui->lineEdit->text();
    pwm_left=s.toInt();
    ui->horizontalSlider->setSliderPosition(pwm_left+255);
}
void MainWindow::value9()
{
    QString s=ui->lineEdit_2->text();
    pwm_right=s.toInt();
    ui->horizontalSlider_2->setSliderPosition(pwm_right+255);

}
void MainWindow::value10()
{
    QString s=ui->lineEdit_3->text();
    kp=s.toDouble();
    kp1=(int)kp;
    ui->horizontalSlider_3->setSliderPosition((kp-kp1)*10000000);
    ui->horizontalSlider_6->setSliderPosition(kp1);
}
void MainWindow::value11()
{
    QString s=ui->lineEdit_4->text();
    ki=s.toDouble();
    ki1=(int)ki;
    ui->horizontalSlider_4->setSliderPosition((ki-ki1)*10000000);
    ui->horizontalSlider_8->setSliderPosition(ki1);
}
void MainWindow::value12()
{
    QString s=ui->lineEdit_5->text();
    kd=s.toDouble();
    kd1=(int)kd;
    ui->horizontalSlider_5->setSliderPosition((kd-kd1)*10000000);
    ui->horizontalSlider_7->setSliderPosition(kd1);
}
void MainWindow::value13()
{
    QString s=ui->lineEdit_6->text();
    int k=s.toInt();
    kd=kd-kd1+k;
    kd1=k;
    ui->horizontalSlider_8->setSliderPosition(kd1);
}
void MainWindow::value14()
{
    QString s=ui->lineEdit_7->text();
    int k=s.toInt();
    ki=ki-ki1+k;
    ki1=k;
    ui->horizontalSlider_7->setSliderPosition(ki1);

}
void MainWindow::value15()
{
    QString s=ui->lineEdit_8->text();
    int k=s.toInt();
    kp=kp-kp1+k;
    kp1=k;
    ui->horizontalSlider_6->setSliderPosition(kp1);
}
void MainWindow::value16()
{
    a=1;BlueP();
}
void MainWindow::value17()
{
    a=-1;BlueP();
}
void MainWindow::newData(double x,double y)
{
    ui->widget->graph(0)->addData(y,x);
    ui->widget->replot();
}
void MainWindow::readData()
{

    //QThread::currentThread()->sleep(10);
    QByteArray data = serial->readLine();
    int i = data.indexOf(',',3);
    int j = data.indexOf(',',i+1);
    int k = data.indexOf(',',j+1);
    if(data[1]=='1')
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
    yg*=0.07;
    rollg+=yg;
    xxa = xa * alpha + (xxa * (1.0 - alpha));
    zza = za * alpha + (zza * (1.0 - alpha));
    xa=xxa;ya=yya;
    ra= 0.98* (rollg) +   ((qAtan2(-zza, xxa)*180.0))/(3.141592653);
    //qDebug()<<f.elapsed();
    int zzz = Compute(ra);
    //qDebug()<<ra;
    //qDebug()<<zzz;
    //zzz=((zzz>0&&zzz<10)?10:zzz);
    //zzz=((zzz<0&&zzz>-10)?-10:zzz);
    QByteArray ba="";ba.append(",");
    ba.append(QString::number(zzz));
    if (serial2->isOpen() && serial2->isWritable())
    {
        serial2->write(data);
        if (serial2->bytesToWrite() > 0)
        {
            serial2->flush();
            serial2->bytesWritten(data.length());
        }
    }
    else
    {
        //cout<< "2 An error occured" << endl;
    }
   // qDebug()<<ba;
    //qDebug()<<serial2->readAll()<<"hj";
    qDebug()<<ba;
    newData(ra-Setpoint,f.elapsed()/1000.0);
}
void MainWindow::readData1()
{
    qDebug()<<"\narduino- "<<serial2->readAll();

}
/*void MainWindow::mouseWheel()
{
    //ui->widget->replot();

}
*/
