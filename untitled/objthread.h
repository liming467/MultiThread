#ifndef OBJTHREAD_H
#define OBJTHREAD_H
#include <QObject>
#include <QThread>


class ObjThread : public QObject
{
    Q_OBJECT
public:
    explicit ObjThread(QObject *parent = nullptr);
    void closeThread();

public slots:
     //开启线程的槽函数
     void startThreadSlot();
private:
     bool isStop=false;
};

#endif // OBJTHREAD_H
