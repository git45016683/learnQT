#ifndef QMYTHREAD1_H
#define QMYTHREAD1_H

#include <QThread>

class MyThreadFromQThread : public QThread
{
    Q_OBJECT
signals:
    void message(const QString& info);
public:
    MyThreadFromQThread(QObject* parent, int count);
    ~MyThreadFromQThread();
    void run();
private:
    int m_runCount;
};

#endif // QMYTHREAD1_H
