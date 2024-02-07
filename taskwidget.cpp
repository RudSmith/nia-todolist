#include "taskwidget.h"
#include <QFont>

TaskWidget::TaskWidget(const QString &text, QWidget *parent) :
    QGroupBox(parent)
{
    InitializeElements(text);
    // Коннектим нажатие на чекбокс и зачёркивание текста
    connect(_checkBox, &QCheckBox::clicked, this, &TaskWidget::OnCheckBoxClick);
    // Коннектим кнопку плюсика и добавление подзадачи
    connect(_addSubTaskPB, &QPushButton::clicked, this, &TaskWidget::OnAddSubtaskClick);
}

TaskWidget::~TaskWidget()
{
    // Очистка ресурсов
    delete _checkBox;
    delete _text;
    delete _layout;
    delete _addSubTaskPB;

    // Цикл foreach для очистки памяти подзадач
    for(auto &subtask : _subtasks)
        delete subtask;
}

QVector<TaskWidget *> &TaskWidget::GetSubtasks()
{
    return _subtasks;
}

void TaskWidget::InitializeElements(const QString &text)
{
    // Создаём чекбокс и надпись
    _checkBox = new QCheckBox();
    _checkBox->setChecked(false);

    _text = new QLabel(text);
    _addSubTaskPB = new QPushButton("+");
    _addSubTaskPB->setFixedSize(15, 15);

    // Создаём layout и добавляем туда элементы
    _layout = new QGridLayout();
    _layout->addWidget(_checkBox, 0, 0);
    _layout->addWidget(_text, 0, 1);
    _layout->addWidget(_addSubTaskPB, 1, 0);

    // Запихиваем layout внутрь групбокса и устанавливаем размер
    this->setLayout(_layout);
    this->setGeometry(0, 0, 170, 60);
}

void TaskWidget::OnCheckBoxClick()
{
    // Копируем текущий шрифт из надписи
    QFont font = this->_text->font();

    // Если не зачёркнуто, зачёркиваем
    if(_checkBox->isChecked())
        font.setStrikeOut(true);
    else
        font.setStrikeOut(false);

    // Задаём тексту новый шрифт
    _text->setFont(font);

}

void TaskWidget::OnAddSubtaskClick()
{
    // Создаём новую подзадачу и пихаем её в вектор
    TaskWidget* newSubtask = new TaskWidget("test");
    _subtasks.push_back(newSubtask);

    // Подаём сигнал на главное окно, что у нас появилась подзадача!!!!
    // this передаём в качестве родителя этой подзадачи, чтобы mainwindow знал, куда её добавлять ваще
    emit NewSubtask(this);
}
