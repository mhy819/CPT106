QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    choosedatasets.cpp \
    colordialog.cpp \
    database.cpp \
    file.cpp \
    filelist.cpp \
    function.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    choosedatasets.h \
    colordialog.h \
    database.h \
    file.h \
    filelist.h \
    function.h \
    mainwindow.h \
    qcustomplot.h

FORMS += \
    choosedatasets.ui \
    colordialog.ui \
    filelist.ui \
    function.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
