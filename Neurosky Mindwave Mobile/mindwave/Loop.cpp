#include<Loop.h>
#include <QtSerialPort/QSerialPortInfo>
bool Loop::flag=1;
Loop::Loop():QThread(){
    char a = '\0';
    data = &a;
    serial = new QSerialPort(this);
    serial->setPortName("COM5");
    serial->setBaudRate(QSerialPort::Baud57600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    QSerialPortInfo info=QSerialPortInfo::availablePorts().at(4);
    qDebug()<<info.portName();
    if(serial->open(QIODevice::ReadWrite));
    this->flag = 1;
    generatedChecksum = 0;
    checksum = 0;
    payloadLength = 0;
    payloadData[64] = {0};
    poorQuality = 0;
    attention = 0;
    meditation = 0;
    lastReceivedPacket = 0;
    bigPacket = false;
}

Loop::~Loop(){flag = 0;}

int Loop::ReadOneByte(){
    while(!serial->bytesAvailable()){QThread::yieldCurrentThread();}
    serial->read(data,1);
    return (int)data[0];
}
void Loop::run(){
    serial->isOpen();
    while(flag){
x:
        if(ReadOneByte() == 170)
         {
            qDebug()<<"op";
           if(ReadOneByte() == 170)
           {
               payloadLength = ReadOneByte();

               if(payloadLength > 169)                      //Payload length can not be greater than 169
               goto x;
               generatedChecksum = 0;
               for(int i = 0; i < payloadLength; i++)
               {
               payloadData[i] = ReadOneByte();            //Read payload into memory
               generatedChecksum += payloadData[i];
               }

               checksum = ReadOneByte();                      //Read checksum byte from stream
               generatedChecksum = 255 - generatedChecksum;   //Take one's compliment of generated checksum

               if(checksum == generatedChecksum)
               {
                 poorQuality = 200;
                 attention = 0;
                 meditation = 0;

                 for(int i = 0; i < payloadLength; i++)
                 {                                          // Parse the payload
                 switch (payloadData[i])
                 {
                 case 2:
                   i++;
                   poorQuality = payloadData[i];
                   bigPacket = true;
                   break;
                 case 4:
                   i++;
                   attention = payloadData[i];
                   break;
                 case 5:
                   i++;
                   meditation = payloadData[i];
                   break;
                 case 0x80:
                   i = i + 3;
                   break;
                 case 0x83:
                   i = i + 25;
                   break;
                 default:
                   break;
                 } // switch
               } // for loop


               }
           }
           qDebug()<<payloadData;
        }
    }
}
