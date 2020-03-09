QT += core
QT -= gui

CONFIG += c++11

TARGET = Jzoffer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    jz_2_2_1_01_mystring.cpp \
    jz_2_2_1_00_sizeof_test.cpp \
    jz_2_2_2_00_singleton.cpp \
    pub.cpp \
    jz_2_3_1_01_duplicatarray.cpp \
    jz_2_3_2_01_replacespace.cpp \
    linklist.cpp \
    jz_mst_06_printlistreverse.cpp \
    linklist_test.cpp

HEADERS += \
    pub.h \
    linklist.h
