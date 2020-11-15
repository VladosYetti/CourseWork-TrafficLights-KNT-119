QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Transfer.cpp \
    TransferGraph.cpp \
    aboutform.cpp \
    abstractalgorithmgraph.cpp \
    bfsalgorithmgraph.cpp \
    dijkstraalgorithmgraph.cpp \
    fordfulkersonalgorithmgraph.cpp \
    helpform.cpp \
    inputdata.cpp \
    main.cpp \
    mainwindow.cpp \
    resultworkalgorithmform.cpp \
    road.cpp \
    root.cpp \
    settingform.cpp \
    trafficlights.cpp \
    working.cpp

HEADERS += \
    Transfer.h \
    TransferGraph.h \
    aboutform.h \
    abstractalgorithmgraph.h \
    bfsalgorithmgraph.h \
    dijkstraalgorithmgraph.h \
    fordfulkersonalgorithmgraph.h \
    helpform.h \
    inputdata.h \
    mainwindow.h \
    resultworkalgorithmform.h \
    road.h \
    root.h \
    settingform.h \
    trafficlights.h \
    working.h

FORMS += \
    aboutform.ui \
    helpform.ui \
    mainwindow.ui \
    resultworkalgorithmform.ui \
    settingform.ui \
    working.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc
