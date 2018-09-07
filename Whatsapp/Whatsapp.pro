TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    user.cpp \
    chat.cpp \
    controller.cpp \
    poo_aux.cpp \
    registro.cpp \
    repository.cpp \
    whatsapp.cpp \
    zap.cpp

HEADERS += \
    registro.h \
    chat.h \
    user.h \
    zap.h \
    whatsapp.h \
    repository.h \
    poo_aux.h \
    controller.h
