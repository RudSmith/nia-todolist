#ifndef MAINWINDOW_H //include guard
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; } // определили пространство имен Ui с компонентом MainWindow
QT_END_NAMESPACE // как я понял, это qtшный прикол с пространствами имен

class MainWindow : public QMainWindow // инициализация QMainWindow?
{
    Q_OBJECT // qt...

public:
    MainWindow(QWidget *parent = nullptr); // конструктор, который присваивает нулевой указатель
    ~MainWindow(); //деструктор

private:
    Ui::MainWindow *ui; // обращаемся к созданному неймспейсу и оттуда берем класс MainWindow (*ui = nullptr ???)
};
#endif // MAINWINDOW_H
