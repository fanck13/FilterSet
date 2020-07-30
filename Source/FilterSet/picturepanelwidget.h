#ifndef PICTUREPANELWIDGET_H
#define PICTUREPANELWIDGET_H

#include <QWidget>

class PicturePanelWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PicturePanelWidget(QWidget *parent = nullptr);
    ~PicturePanelWidget();

public slots:
    void updatePicture(const QString& filePath );

signals:

};

#endif // PICTUREPANELWIDGET_H
