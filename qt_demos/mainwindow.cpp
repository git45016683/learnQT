#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , thread1(NULL)
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
