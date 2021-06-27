#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->showChildButton, &QPushButton::clicked, this, &MainWindow::showChildDialog);
//    connect(ui->autoBindBtn, &QPushButton::clicked, this, &MainWindow::showDlg);
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
