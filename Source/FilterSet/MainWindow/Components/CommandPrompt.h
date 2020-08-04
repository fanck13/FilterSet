#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QLabel>

class CommandPrompt : public QWidget
{
    Q_OBJECT

public:
    CommandPrompt(QWidget *parent);
    ~CommandPrompt();
    QString get
private:
    QLineEdit* lineEdit;
    QLabel* closeLabel;
};
