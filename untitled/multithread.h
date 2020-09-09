#ifndef MULTITHREAD_H
#define MULTITHREAD_H
#include <QThread>
#include <QMutex>
#include <QDebug>


class MultiThread : public QThread
{
    Q_OBJECT
public:
    MultiThread();

    void run();
    void finished();

private:
    unsigned int m_count=0;
    bool m_isCancel=false;
    QMutex m_mutex;

    inline void addOne(){
        m_count++;
        qDebug()<<"MultiThread::addOne():"<<QThread::currentThreadId()<<", count"<<m_count;
    }

};

#endif // MULTITHREAD_H
