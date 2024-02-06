#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include <QWidget>
#include <QCheckBox>
#include <QLabel>
#include <QString>
#include <QGridLayout>
#include <QGroupBox>

// Виджет задачи, наследуется от QGroupBox
class TaskWidget : public QGroupBox
{
    Q_OBJECT
public:
    // Конструктор, задаёт текст и инициализирует дочерние элементы
    explicit TaskWidget(const QString &text = "", QWidget *parent = nullptr);
    // Деструктор, очищает память
    ~TaskWidget(void);

private:
    void InitializeElements(const QString &text);

    QCheckBox* _checkBox;
    QLabel* _text;
    QGridLayout* _laytout;

private slots:
    // Слот обработки нажатия на чекбокс
    void OnCheckBoxClick();

};

#endif // TASKWIDGET_H
