 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QComboBox>
#include <QMessageBox>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton_finish->setEnabled(false);

    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
          [=](int index){
        m_type=ui->comboBox->currentIndex();
        if(m_type)
            ui->pushButton_finish->setEnabled(true);
        else
            ui->pushButton_finish->setEnabled(false);
        QMessageBox::information(NULL,"Current id",QString::number(m_type));
    });    

}

MainWindow::~MainWindow()
{
    delete ui;
}

//Start loop
void MainWindow::on_pushButton_start_clicked()
{
    if(m_type==0){
        mainStart();
    }else if(m_type==1){
        qthreadStart();
    }else if(m_type==2){
       qobjectStart();
    }

}


//Finish loop
void MainWindow::on_pushButton_finish_clicked()
{
    if(m_type==0){
        mainFinish();
    }else if(m_type==1){
        qthreadFinish();
    }else if(m_type==2){
        qobjectFinish();
    }
}


/*******************************Start*************************************/
void MainWindow::mainStart(){
    QMessageBox::information(NULL,"MainWindow","mainStart");
    unsigned int count=0;
    QTime time;
    time.start();
    m_isCancel=false;
    qDebug()<<"MainWindow::run():"<<QThread::currentThreadId();
    while(!m_isCancel){
        if(time.elapsed()>10000){
            m_isCancel=true;
            time.restart();
        }
        count++;
    }

}

void MainWindow::qthreadStart(){
    QMessageBox::information(NULL,"MainWindow","qthreadStart");
    if(m_thread.isRunning())
        return;
    m_thread.start();
}

void MainWindow::qobjectStart(){
    QMessageBox::information(NULL,"MainWindow","qobjectStart");

    thread = new QThread();
    m_objThread=new ObjThread;
    m_objThread->moveToThread(thread);
    connect(thread,&QThread::finished,m_objThread,&QObject::deleteLater);
    connect(thread,SIGNAL(started()),m_objThread,SLOT(startThreadSlot()));
    thread->start();

}

/*******************************Finish*************************************/
void MainWindow::mainFinish(){
    QMessageBox::information(NULL,"MainWindow","mainFinish");
    m_isCancel=true;
}

void MainWindow::qthreadFinish(){
    QMessageBox::information(NULL,"MainWindow","qthreadFinish");
    m_thread.finished();

    if(m_thread.isFinished())
        QMessageBox::information(NULL,"MainWindow","Thread finished!");
}

void MainWindow::qobjectFinish(){
    QMessageBox::information(NULL,"MainWindow","qthreadFinish");
    m_objThread->closeThread();
    m_objThread->deleteLater();

    if(thread->isFinished())
        QMessageBox::information(NULL,"MainWindow","Thread inherited from QObject is finished!");
}

