#-------------------------------------------------
#
# Project created by QtCreator 2016-04-12T09:44:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = LearnEigen
TEMPLATE = app


SOURCES +=\
        mainwindow.cpp \
    qcustomplot.cpp \
    main.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h

FORMS    += mainwindow.ui

INCLUDEPATH += C:/Users/bec100/Desktop/Eigen/eigen-eigen-07105f7124f9

CONFIG += console
