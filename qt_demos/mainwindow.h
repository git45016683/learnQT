#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qmythread1.h"

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

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    MyThreadFromQThread* thread1;
};
#endif // MAINWINDOW_H
