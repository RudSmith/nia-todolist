#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "taskwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Обработчик добавления новой подзадачи
    void AddSubtask(TaskWidget* subtaskParent);

private:
    Ui::MainWindow* ui;
    // Основной тасквиджет, потом просто вектор будет
    TaskWidget* _tw;
    QVector<TaskWidget*> _tasks;
};
#endif // MAINWINDOW_H
