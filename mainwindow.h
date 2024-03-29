#ifndef MAINWINDOW_H //���������, ��������������� ��� ������ ����� �� ������������� ���������, �� ����, ���� ����� ���� ��� ������� ���-�� � ������ ������, �� ����� �������� � �� ����� ����������� �������� (����� ���-�� ��� ������ ��� �������, �������� ���-�� ��������� � �����������, �� � ����� �����) 
#define MAINWINDOW_H //���������� �������, ����� ������������ ��� � ������ ������

#include <QMainWindow>
#include "taskwidget.h"

QT_BEGIN_NAMESPACE // ������, ���������� �������� ��������� � ������ � ������� ������������ � ������� ���������, �����, ����� ����� ��������������� ��� � �������� ��������
namespace Ui { class MainWindow; }
QT_END_NAMESPACE // ����� QT_BEGIN_NAMESPACE 

class MainWindow : public QMainWindow // �����, ������� ����������� �� QMainWindow
{
    Q_OBJECT // ��� ��� �� ���������� �������-�������� �������, ��� ����� ������ �������. ��� ������ ��� ���������� �������� � ������ � Qt

public:
    MainWindow(QWidget *parent = nullptr); // �����������. � ���������� ��������� �� QWidget � �������������� � nullptr, ��� ��������� ��������� ������ (MainWindow) �/��� �������� ��������
    ~MainWindow(); // ����������, ����������� �����, ������� ���������� ��� MainWindow

private slots:
    // ���������� ���������� ����� ���������
    void AddSubtask(TaskWidget* subtaskParent);

private:
    Ui::MainWindow* ui;
    // �������� ����������, ����� ������ ������ �����
    TaskWidget* _tw;
    QVector<TaskWidget*> _tasks;
};
#endif // MAINWINDOW_H
