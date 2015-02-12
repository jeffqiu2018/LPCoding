#-------------------------------------------------
#
# Project created by QtCreator 2015-02-09T18:15:59
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LPCoding
TEMPLATE = app

INCLUDEPATH +=  $$PWD/Lib/QCustomPlot/ \
                $$PWD/Source/ \
                $$PWD/GeneratedFiles/

SOURCES += \
    Lib/QCustomPlot/qcustomplot.cpp \
    Source/main.cpp \
    Source/MainForm.cpp \
    Source/Model.cpp \
    Source/WavModel.cpp

HEADERS  += \
    Lib/QCustomPlot/qcustomplot.h \
    Source/Hamming.h \
    Source/Hanning.h \
    Source/IWindow.h \
    Source/MainForm.h \
    Source/Model.h \
    Source/Vector.h \
    Source/WavModel.h

FORMS    += \
    Forms/MainForm.ui
