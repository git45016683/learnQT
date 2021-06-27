#include "mythreadfromqobject.h"
#include <QDebug>
#include <QThread>

MyThreadFromQObject::MyThreadFromQObject(int count, QObject *parent)
    : QObject(parent)
    , m_runCount1(count)
    , m_runCount2(count)
{
    qDebug("new线程了哦--fromThreadQObject");
}

MyThreadFromQObject::~MyThreadFromQObject()
{
    qDebug("线程析构了哦--fromThreadQObject");
}

void MyThreadFromQObject::stop()
{
    emit message(QString("%1->%2, thread id:%3").arg(__FUNCTION__).arg(__FILE__).arg((int)QThread::currentThreadId()));
}

void MyThreadFromQObject::runSomeBigWork1()
{
    qDebug() << "MyThreadFromQObject::runSomeBigWork1()";
    int count = 0;
    while(1)
    {
        QThread::sleep(1);
        ++count;
        QString str = QString("running %1 S--fromThreadQObject work1").arg(count);
        qDebug() << str;
        emit message(str);
        if (m_runCount1 == count)
        {
            break;
        }
    }
}

void MyThreadFromQObject::runSomeBigWork2()
{
    qDebug() << "MyThreadFromQObject::runSomeBigWork2()";
    int count = 0;
    while(1)
    {
        QThread::sleep(10);
        ++count;
        QString str = QString("running %1 S--fromThreadQObject work2").arg(count*10);
        //qDebug("%s", str);
        qDebug() << str;
        emit message(str);
        if (m_runCount2 == count)
        {
            break;
        }
    }
}
