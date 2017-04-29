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
double Compute(double input)
{
      double error = Setpoint - input;
      ITerm+= (ki2 * error);
      if(ITerm > outMax) ITerm= outMax;
      else if(ITerm < outMin) ITerm= outMin;
      double dInput = (input - lastInput);
      double output = kp2 * error + ITerm + kd2 * dInput;
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
    ui->setupUi(this);
    serial = new QSerialPort(this);
    QSerialPortInfo info=QSerialPortInfo::availablePorts().at(0);
    // Check info of the port
    qDebug() << "Name        : " << info.portName();
    /*qDebug() << "Manufacturer: " << info.manufacturer(); //if showing manufacturer, means Qstring &name is good
    qDebug() << "Busy: " << info.isBusy() << endl;
    */// Initialize Serial
    serial->setPortName("COM6");
    //serial->open(QIODevice::ReadWrite);
    serial->setBaudRate(QSerialPort::Baud57600);
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
    connect(ui->lineEdit_9,SIGNAL(returnPressed()),this,SLOT(value18()));
    connect(ui->radioButton_3,SIGNAL(pressed()),this,SLOT(value19()));
    //connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(readData()));
    timer->start(16);
    for(int i=0;i<44;i++)
        KP[i]=0;
    // create graph and assign data to it:
    ui->widget->legend->setVisible(true);
    //ui->widget->addGraph()->setName("AccelAng");
    ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    //ui->widget->axisRect()->setRangeZoom(Qt::Horizontal | Qt::Vertical);
    ui->widget->axisRect()->setRangeZoom(Qt::Horizontal);
    ui->widget->axisRect()->setRangeZoomFactor(1.5);
    ui->widget->addGraph()->setName("Theta");
    ui->widget->addGraph()->setName("ThetaDot");
    ui->widget->addGraph()->setName("Velocity");
    ui->widget->addGraph()->setName("ThetaOffset");
    ui->widget->addGraph()->setName("Displacement");
    //ui->widget->graph(0)->setData(x, y);
    ui->widget->xAxis->setLabel("Time(s)->");
    ui->widget->yAxis->setLabel("Angle(°),Disp(m),Vel(m/s)");
    ui->widget->graph(0)->setPen(QPen(Qt::red));
    ui->widget->graph(1)->setPen(QPen(Qt::green));
    ui->widget->graph(2)->setPen(QPen(Qt::blue));
    ui->widget->graph(3)->setPen(QPen(Qt::black));
    ui->widget->graph(4)->setPen(QPen(Qt::cyan));
    ui->widget->xAxis->setRange(0,50);
    ui->widget->yAxis->setRange(15,-15);
    f.start();
    //imufilter = new IMUfilter(0.015, 20);

}

MainWindow::~MainWindow()
{
    timer->stop();
    QFile file("C:/Users/yikes/Desktop/graph.jpg");
    ui->widget->saveJpg( "C:/Users/yikes/Desktop/graph.jpg",  0, 0, 1.0, -1  );
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
    else if(a==1){
        QString s("");
        /*s.append("l");
        s.append(QString::number(pwm_left,'g',9));
        s.append("\nr");
        s.append(QString::number(pwm_right,'g',9));
        s.append("\n");//only for pwm
        */
        if(pkp!=kp){
        s.append("p");pkp=kp;
        s.append(QString::number(kp,'g',5));
        s.append(",\n");
        goto zz;
        }
        if(pki!=ki){
        s.append("i");pki=ki;
        s.append(QString::number(ki,'g',5));
        s.append(",\n");
        goto zz;
        }
        if(pkd!=kd){
        s.append("d");pkd=kd;
        s.append(QString::number(kd,'g',5));
        s.append(",\n");
        goto zz;
        }
        zz:
        qDebug()<<s<<"123";
        ba=s.toUtf8();
    }
    else if(a==0){

        QString s("");
        s.append(cmd);
        s.append(",\n");
        ba=s.toUtf8();
}
    if (serial->isOpen() && serial->isWritable())
    {
        qDebug()<<ba;
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
        qDebug()<<a;
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
    a=1;//BlueP();
}
void MainWindow::value17()
{
    a=-1;//BlueP();
}
void MainWindow::value18()
{
    QString s=ui->lineEdit_9->text();
    cmd = s;
    ui->lineEdit_9->clear();BlueP();
}
void MainWindow::value19()
{
    a=0;//BlueP();
}

void MainWindow::newData(double w, double x,double y,double z,double a,double t)
{
    ui->widget->graph(0)->addData(t,w);
    ui->widget->graph(1)->addData(t,x);
    ui->widget->graph(2)->addData(t,y);
    ui->widget->graph(3)->addData(t,z);
    ui->widget->graph(4)->addData(t,a);
    ui->widget->replot();

}

double zoff,xoff;volatile int ch=0;
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
    n = data.indexOf(',',l+1);
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
    ys=data.mid(l+1,n-l-1).toDouble()/1000;
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

    qDebug()<<xs<<xa<<ya<<f.elapsed();

    //if(f.elapsed()>40000)
    newData(xs,xa,ya,za,ys,(t=f.elapsed())/1000.0);
    if(serial->bytesAvailable()>25) goto x;
    else ch=0;
        }



/*void MainWindow::mouseWheel()
{
    //ui->widget->replot();

}
*/
