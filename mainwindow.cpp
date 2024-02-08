#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRect>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Временное решение с начальным тасквиджетом
    _tw = new TaskWidget("test");
    connect(_tw, &TaskWidget::NewSubtask, this, &MainWindow::AddSubtask);
    this->layout()->addWidget(_tw);
    _tasks.push_back(_tw);
}

MainWindow::~MainWindow()
{
    delete _tw;
    delete ui;
}

// Это я писал в состоянии полусна и возможно здесь говнокод, если да, исправить
void MainWindow::AddSubtask(TaskWidget *subtaskParent)
{
    // Здесь мы должны сформировать геометрию новой подзадачи
    QRect geometry {};
    // Смещение по х всегда ~20 (можно меньше\больше сделать)
    int xOffset { 20 };
    // Смещение по y всегда разное
    int yOffset;

    // Если это первая подзадача, смещение по y будет равно родительская_подзадача.у() + высота плитки
    if(subtaskParent->GetSubtasks().size() == 1)
    {
        yOffset = subtaskParent->height();
        geometry.setY(subtaskParent->y() + yOffset);
    }
    // Если это не первая подзадача, смещение по y будет равно игрику самой нижней подзадачи + высота плитки
    else
    {
        std::size_t size = subtaskParent->GetSubtasks().size();
        yOffset =  + subtaskParent->height();
        geometry.setY(subtaskParent->GetSubtasks().at(size - 2)->y() + yOffset);
    }

    // Устанавливаем параметры геометрии
    geometry.setX(subtaskParent->x() + xOffset);
    geometry.setHeight(subtaskParent->height());
    geometry.setWidth(subtaskParent->width());

    // Задаём геометрию для подзадачи
    subtaskParent->GetSubtasks().last()->setGeometry(geometry);

    // Пихаем подзадачу в окно
    this->layout()->addWidget(subtaskParent->GetSubtasks().last());
    // Делаем так, чтобы новая подзадача тоже могла подавать сигнал создания подзадачи
    connect(subtaskParent->GetSubtasks().last(), &TaskWidget::NewSubtask, this, &MainWindow::AddSubtask);
    _tasks.push_back(subtaskParent);
}

