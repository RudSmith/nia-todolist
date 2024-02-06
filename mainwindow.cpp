#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    _tw = new TaskWidget("test");
    ui->setupUi(this);
    this->layout()->addWidget(_tw);
}

MainWindow::~MainWindow()
{
    delete _tw;
    delete ui;
}

