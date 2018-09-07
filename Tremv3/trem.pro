TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    trem.cpp \
    vagao.cpp \
    passageiro.cpp \
    controller.cpp \
    split.cpp \
    registropassageiros.cpp

HEADERS += \
    trem.h \
    vagao.h \
    passageiro.h \
    registropassageiros.h \
    controller.h \
    split.h
