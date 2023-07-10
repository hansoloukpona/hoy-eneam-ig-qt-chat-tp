#-------------------------------------------------
#
# Project created by QtCreator 2021-05-19T12:45:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = TestUs
TEMPLATE = app


SOURCES += main.cpp\
    user.cpp \
    textusconnection.cpp \
    message.cpp

HEADERS  += \
    user.h \
    textusconnection.h \
    message.h

FORMS    += \
    textusconnection.ui

RESOURCES +=
