#ifndef LOOP
#define LOOP

#endif // LOOP
#include <iostream>
#include <QThread>
#include <QtSerialPort/QSerialPort>
#include "QDebug"
class Loop:public QThread{

public:
    Loop();
    ~Loop();
    static bool flag;
private:
    QSerialPort *serial;
    char *data;
    int generatedChecksum;
    int checksum;
    int payloadLength;
    int payloadData[64];
    int poorQuality;
    int attention;
    int meditation;
    long lastReceivedPacket;
    bool bigPacket;
    int ReadOneByte();

protected:
    void run();

};
