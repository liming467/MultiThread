#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "multithread.h"
#include "objthread.h"
#include <QThread>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_start_clicked();
    void on_pushButton_finish_clicked();




private:
    Ui::MainWindow *ui;

    MultiThread m_thread;
    ObjThread  *m_objThread;

    QThread *thread=nullptr;

    void run();
    bool m_isCancel=true;
    int m_type=0;


    void mainStart();
    void qthreadStart();
    void qobjectStart();

    void mainFinish();
    void qthreadFinish();
    void qobjectFinish();
};

#endif // MAINWINDOW_H
