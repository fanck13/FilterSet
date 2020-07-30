#ifndef INFORMATION_H
#define INFORMATION_H

#include <QMessageBox>

class Information : public QMessageBox
{
public:
    Information(QWidget *parent = nullptr);

    QSize sizeHint() const override;
};

#endif // INFORMATION_H
