#include "multithread.h"


MultiThread::MultiThread()
{

}

void MultiThread::run()
{
     m_isCancel=false;
    while (!m_isCancel) {
        m_count++;
        qDebug()<<"MultiThread::run():"<<QThread::currentThreadId()<<", count:"<<m_count;
        addOne();
    }

}

void MultiThread::finished(){
    m_mutex.lock();
    m_isCancel=true;
    m_mutex.unlock();
    this->quit();
    this->wait();
}

