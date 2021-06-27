#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qmythread1.h"
#include "mythreadfromqobject.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void showChildDialog();
//    void showDlg();
    void on_autoBindBtn_clicked();
    void receiveMessage(const QString& str);
// 线程示例槽函数
    void startThread();
    void deleteThread();
    void terminateThread();
    void on_threadExit_clicked();
    void on_threadQuit_clicked();

// 线程示例槽函数--fromQObject
    void startThread2();
    void deleteThread2();
    void terminateThread2();
    void on_threadBigWork1_clicked();
    void on_threadBigWork2_clicked();
    void receiveMessage2(const QString& str);

signals:
    void startObjThreadWork1();
    void startObjThreadWork2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    MyThreadFromQThread* thread1;
    MyThreadFromQObject* thread2;
    QThread* m_objThread;
};
#endif // MAINWINDOW_H
