#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); //указатель на объект класса
}

MainWindow::~MainWindow() //берем из MainWindow дестркутор и удаляем переменную ui?
{
    delete ui;
}

// Честно я очень пытаюсь разобраться и в синтаксисе и в принципе как это работает, но есть ощущение что без 0,5 ничего не получится.
