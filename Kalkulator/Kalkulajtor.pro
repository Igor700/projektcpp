#-------------------------------------------------
#
# Project created by QtCreator 2018-11-06T20:38:34
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Kalkulajtor
TEMPLATE = app


SOURCES += main.cpp\
        calculator.cpp \
    units.cpp \
    qcustomplot.cpp

HEADERS  += calculator.h \
    units.h \
    qcustomplot.h

FORMS    += calculator.ui

RESOURCES += \
    resources.qrc
