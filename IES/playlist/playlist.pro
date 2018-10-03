TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    design.c \
    maker.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    design.h \
    maker.h

