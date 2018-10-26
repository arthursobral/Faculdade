TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    design.c \
    maker.c \
    cadastro.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    design.h \
    maker.h \
    data.h \
    cadastro.h

