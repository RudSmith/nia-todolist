#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Честно я очень пытаюсь разобраться и в синтаксисе и в принципе как это работает, но есть ощущение что без 0,5 ничего не получится.
