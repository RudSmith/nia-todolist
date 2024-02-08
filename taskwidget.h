#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include <QWidget>
#include <QCheckBox>
#include <QLabel>
#include <QString>
#include <QGridLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QVector>

// Виджет задачи, наследуется от QGroupBox
class TaskWidget : public QGroupBox
{
    Q_OBJECT
public:
    // Конструктор, задаёт текст и инициализирует дочерние элементы
    explicit TaskWidget(const QString &text = "", QWidget *parent = nullptr);
    // Деструктор, очищает память
    ~TaskWidget(void);

    // Получить вектор подзадач
    QVector<TaskWidget*>& GetSubtasks();

private:
    void InitializeElements(const QString &text);

    QCheckBox* _checkBox;
    QLabel* _text;
    QGridLayout* _layout;
    QPushButton* _addSubTaskPB; // Кнопка добавления подзадачи
    QVector<TaskWidget*> _subtasks; // Вектор подзадач

private slots:
    // Слот обработки нажатия на чекбокс
    void OnCheckBoxClick();
    // Слот добавления подзадачи
    void OnAddSubtaskClick();

signals:
    // Сигнал появления новой подзадачи, подаётся на главное окно
    void NewSubtask(TaskWidget*);

};

#endif // TASKWIDGET_H
