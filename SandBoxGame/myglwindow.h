#ifndef MYGLWINDOW_H
#define MYGLWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MyGLWindow; }
QT_END_NAMESPACE

class MyGLWindow : public QWidget
{
    Q_OBJECT

public:
    MyGLWindow(QWidget *parent = nullptr);
    ~MyGLWindow();

private:
    Ui::MyGLWindow *ui;
};
#endif // MYGLWINDOW_H
