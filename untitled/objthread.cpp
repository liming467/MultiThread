#include "objthread.h"
#include <QDebug>
#include <QTime>

ObjThread::ObjThread(QObject *parent) : QObject(parent)
{

}

void ObjThread::closeThread()
{
    isStop = true;
}
//这个函数写要循环运行的代码段
void ObjThread::startThreadSlot()
{
    QTime time;
    time.start();
    unsigned int count=0;
    isStop=false;
    qDebug()<<"ObjThread::startThreadSlot():"<<QThread::currentThreadId();
    while(!isStop){
        if(time.elapsed()>100){
            qDebug()<<"ObjThread::startThreadSlot():"<<QThread::currentThreadId()<<", count:"<<count;
             count++;
             time.restart();
        }
    }



}
