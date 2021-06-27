#include "qmythread1.h"
#include <QDebug>

MyThreadFromQThread::MyThreadFromQThread(QObject* parent, int count) : QThread(parent)
  ,m_runCount(count)
{

}

MyThreadFromQThread::~MyThreadFromQThread()
{
    qDebug() << "线程析构了哦" << endl;
}

void MyThreadFromQThread::run()
{
    int count = 0;
    while(1)
    {
        sleep(1);
        ++count;
        QString str = QString("running %1 S").arg(count);
        qDebug() << str;
        emit message(str);
        if (m_runCount == count)
        {
            break;
        }
    }
//    this->exit();
//    this->quit();
//    this->terminate();
//    delete this;
}
