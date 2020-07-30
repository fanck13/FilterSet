#ifndef PICTUREREADER_H
#define PICTUREREADER_H

#include <QtGui/QImage>

#include "PictureReader_global.h"

class PICTUREREADER_EXPORT PictureReader
{
public:
    PictureReader();
    ~PictureReader();

    QImage* getPicture();

private:
    QScopedPointer<QImage> image;
};

#endif // PICTUREREADER_H
