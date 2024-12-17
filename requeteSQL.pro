QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = requeteSQL
TEMPLATE = app

SOURCES += main.cpp \
    widget.cpp

HEADERS +=widget.h

FORMS +=widget.ui
