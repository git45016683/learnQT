#include <QtWidgets>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    // 新建qwidget对象，默认parent参数为0，所以它是个窗口
//    QWidget* widget = new QWidget(0,Qt::Dialog);  // dialog样式窗口
    QWidget* widget = new QWidget(0,Qt::Dialog | Qt::FramelessWindowHint);  // 无边框样式
    // 设置窗口标题
    widget->setWindowTitle(QObject::tr("我是learnQT from icemaple"));
    // 新建QLabel对象，默认parent参数为0，所以它是个独立窗口
//    QLabel* label = new QLabel(0,Qt::SplashScreen);  // 欢迎窗口样式
    QLabel* label = new QLabel(0,Qt::SplashScreen | Qt::WindowStaysOnTopHint);  // 欢迎窗口，总是置顶
    // 设置QLabel Title的内容
    label->setWindowTitle(QObject::tr("我是Label Title，Hello Word~"));
    // 设置QLabel要显示的内容
    label->setText(QObject::tr("我是Label内容：Hello icemaple"));
    // 设置窗口大小
    label->resize(200, 50);
    // 新建个有parent参数的QLabel，其不再是独立窗口
    QLabel* labelchild = new QLabel(widget);
    // 设置labelchild显示的内容
    labelchild->setText(QObject::tr("我是子QLabel：你好，世界"));
    // 设置labelchild的大小
    labelchild->resize(300, 100);
    // show
    label->show();
    widget->show();
    int ret = a.exec();
    delete label;
    delete widget;
    return ret;
}
