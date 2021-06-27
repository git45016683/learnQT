#ifndef MYTHREADFROMQOBJECT_H
#define MYTHREADFROMQOBJECT_H

#include <QThread>
#include <QObject>

class MyThreadFromQObject : public QObject
{
    Q_OBJECT
public:
    MyThreadFromQObject(int count, QObject* parent = NULL);
    ~MyThreadFromQObject();
    void stop();
public slots:
    void runSomeBigWork1();
    void runSomeBigWork2();
signals:
    void message(const QString& info);
private:
    int m_runCount1;
    int m_runCount2;
};

#endif // MYTHREADFROMQOBJECT_H
