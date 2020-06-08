#include "myglwindow.h"
#include "ui_myglwindow.h"

MyGLWindow::MyGLWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyGLWindow)
{
    ui->setupUi(this);
}

MyGLWindow::~MyGLWindow()
{
    delete ui;
}

