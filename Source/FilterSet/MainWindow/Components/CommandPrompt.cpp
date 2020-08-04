#include "CommandPrompt.h"

#include <QHBoxLayout>


CommandPrompt::CommandPrompt(QWidget *parent)
    : QWidget(parent)
{
    auto hBoxLayout = new QHBoxLayout(this);
    lineEdit = new QLineEdit(this);
    hBoxLayout->addWidget(lineEdit);
    closeLabel = new QLabel("close", this);
    hBoxLayout->addWidget(closeLabel);
    this->setLayout(hBoxLayout);
}

CommandPrompt::~CommandPrompt()
{
}
