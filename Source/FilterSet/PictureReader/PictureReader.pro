QT += core gui

TEMPLATE = lib
DEFINES += PICTUREREADER_LIBRARY

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    PictureReader.cpp

HEADERS += \
    PictureReader_global.h \
    PictureReader.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target



win32:CONFIG(release, debug|release): LIBS += -LC:/opencv/build/x64/vc15/lib/ -lopencv_world440
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/opencv/build/x64/vc15/lib/ -lopencv_world440d
else:unix: LIBS += -LC:/opencv/build/x64/vc15/lib/ -lopencv_world440

INCLUDEPATH += C:/opencv/build/include
DEPENDPATH += C:/opencv/build/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += C:/opencv/build/x64/vc15/lib/libopencv_world440.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += C:/opencv/build/x64/vc15/lib/libopencv_world440d.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += C:/opencv/build/x64/vc15/lib/opencv_world440.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += C:/opencv/build/x64/vc15/lib/opencv_world440d.lib
else:unix: PRE_TARGETDEPS += C:/opencv/build/x64/vc15/lib/libopencv_world440.a
