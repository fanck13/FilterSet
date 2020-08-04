#include "Information.h"

Information::Information(QWidget *parent):QMessageBox(parent)
{

}


QSize Information::sizeHint() const
{
    return QSize(600, 400);
}
