#include "taskwidget.h"
#include <QFont>

TaskWidget::TaskWidget(const QString &text, QWidget *parent) : QGroupBox(parent)
{
    InitializeElements(text);
    connect(_checkBox, &QCheckBox::clicked, this, &TaskWidget::OnCheckBoxClick);
}

TaskWidget::~TaskWidget()
{
    delete _checkBox;
    delete _text;
    delete _laytout;
}

void TaskWidget::InitializeElements(const QString &text)
{
    // Создаём чекбокс и надпись
    _checkBox = new QCheckBox();
    _checkBox->setChecked(false);
    _text = new QLabel(text);

    // Создаём layout и добавляем туда элементы
    _laytout = new QGridLayout();
    _laytout->addWidget(_checkBox, 0, 0);
    _laytout->addWidget(_text, 0, 1);

    // Запихиваем layout внутрь групбокса и устанавливаем размер
    this->setLayout(_laytout);
    this->setGeometry(0, 0, 100, 50);
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
