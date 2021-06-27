#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , thread1(NULL)
    , thread2(NULL)
    , m_objThread(NULL)
{
    ui->setupUi(this);
    connect(ui->showChildButton, &QPushButton::clicked,
            this, &MainWindow::showChildDialog);
//    connect(ui->autoBindBtn, &QPushButton::clicked,
//            this, &MainWindow::showDlg);
    connect(ui->deleteThread, &QPushButton::clicked,
            this, &MainWindow::deleteThread);
    connect(ui->startThread, &QPushButton::clicked,
            this, &MainWindow::startThread);

    connect(ui->startThread_2, &QPushButton::clicked,
            this, &MainWindow::startThread2);
    connect(ui->threadTerm_2, &QPushButton::clicked,
            this, &MainWindow::terminateThread2);
    connect(ui->deleteThread_2, &QPushButton::clicked,
            this, &MainWindow::deleteThread2);

    startThread();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showChildDialog()
{
    QDialog *dialog = new QDialog(this);
    dialog->show();
}

void MainWindow::on_autoBindBtn_clicked()
{
    QDialog* dlg = new QDialog(this);
    QLabel* label = new QLabel(dlg);
    label->setText("I am a Model Dialog......");
    dlg->resize(200,100);
    dlg->exec();
}


void MainWindow::on_pushButton_clicked()
{
    close();
}

void MainWindow::receiveMessage(const QString& str)
{
    ui->textBrowser->append(str);
    QString tempStr = str;
//    QStringList strList = tempStr.split(" ");
//    qDebug() << list;
    ui->lcdNumber->display(tempStr.split(" ")[1]);
}

void MainWindow::startThread()
{
    QString count = ui->textEditcount->toPlainText();
    if (count == "" || count == NULL)
    {
        count = "6";
    }
    thread1 = new MyThreadFromQThread(this, count.toInt());
    connect(thread1, &MyThreadFromQThread::message,
            this, &MainWindow::receiveMessage);
    thread1->start();
    qDebug("开启线程");
    ui->textBrowser->clear();
}

void MainWindow::deleteThread()
{
    if (thread1 != NULL)
    {
        delete thread1;
        thread1 = NULL;
    }
    qDebug() << "删除线程";
}

void MainWindow::terminateThread()
{
    thread1->terminate();
    qDebug() << "终结线程";
}

void MainWindow::on_threadExit_clicked()
{
    thread1->exit();
    qDebug("exit退出线程");
}

void MainWindow::on_threadQuit_clicked()
{
    thread1->quit();
    qDebug() << "quit退出线程";
}

void MainWindow::startThread2()
{
    qDebug() << "startThread2";
    if (m_objThread)
    {
        qDebug() << "return startThread2";
        return;
    }
    QString count = ui->textEditcount->toPlainText();
    if (count == "" || count == NULL)
    {
        count = "6";
    }

    m_objThread = new QThread();
    thread2 = new MyThreadFromQObject(count.toInt());
    thread2->moveToThread(m_objThread);

    connect(m_objThread, &QThread::finished,
            m_objThread, &QObject::deleteLater);
    connect(m_objThread, &QThread::finished,
            thread2, &QObject::deleteLater);
    connect(this, &MainWindow::startObjThreadWork1,
            thread2, &MyThreadFromQObject::runSomeBigWork1);
    connect(this, &MainWindow::startObjThreadWork2,
            thread2, &MyThreadFromQObject::runSomeBigWork2);
    connect(thread2, &MyThreadFromQObject::message,
            this, &MainWindow::receiveMessage2);

    m_objThread->start();
}

void MainWindow::deleteThread2()
{
    if (m_objThread)
    {
        delete m_objThread;
    }
    if (thread2)
    {
        delete thread2;
    }
}

void MainWindow::terminateThread2()
{
    if (m_objThread)
    {
        if (thread2)
        {
            thread2->stop();
            delete thread2;
        }
    }
}

void MainWindow::on_threadBigWork1_clicked()
{
    if (!m_objThread)
    {
        startThread2();
    }
    emit startObjThreadWork1();

    ui->textBrowser_2->append("start ObjThread Work 1");
}

void MainWindow::on_threadBigWork2_clicked()
{
    if (!m_objThread)
    {
        startThread2();
    }
    emit startObjThreadWork2();

    ui->textBrowser_2->append("start ObjThread Work 2");
}

void MainWindow::receiveMessage2(const QString &str)
{
    ui->textBrowser_2->append(str);
//    QString tempStr = str;
////    QStringList strList = tempStr.split(" ");
////    qDebug() << list;
//    ui->lcdNumber->display(tempStr.split(" ")[1]);
}
