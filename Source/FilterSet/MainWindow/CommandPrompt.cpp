#include "CommandPrompt.h"

#include <QLineEdit>

CommandPrompt::CommandPrompt(QWidget *parent)
    : QDockWidget(parent)
{
    QLineEdit* lineEdit = new QLineEdit(this);
    lineEdit->setFixedWidth(200);

    this->setWidget(lineEdit);

    this->setFixedSize(lineEdit->width(), lineEdit->height());

    QWidget * qw = new QWidget(this);
    this->setTitleBarWidget(qw);

    //this->setWindowFlags(Qt::CustomizeWindowHint);
}

CommandPrompt::~CommandPrompt()
{
}
