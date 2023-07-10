#-------------------------------------------------
#
# Project created by QtCreator 2021-05-23T00:42:56
#
#-------------------------------------------------

QT       += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = TextUsServer
TEMPLATE = app

DEPENDPATH += .
INCLUDEPATH += .

SOURCES += main.cpp\
        textusserver.cpp\
        message.cpp \
        user.cpp

HEADERS  += textusserver.h\
        message.h \
        user.h

FORMS    +=
