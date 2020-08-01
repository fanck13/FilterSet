#pragma once

#include <QDockWidget>

class CommandPrompt : public QDockWidget
{
    Q_OBJECT

public:
    CommandPrompt(QWidget *parent);
    ~CommandPrompt();
};
