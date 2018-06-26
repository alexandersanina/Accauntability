#-------------------------------------------------
#
# Project created by QtCreator 2018-04-05T12:33:00
#
#-------------------------------------------------

QT       += core gui xml testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Accountability
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        ui.cpp \
    authentication.cpp \
    group.cpp \
    student.cpp \
    workerxml.cpp \
    testauto.cpp \
    gtest/src/gtest-all.cc \
    gtest/src/gtest-death-test.cc \
    gtest/src/gtest-filepath.cc \
    gtest/src/gtest-port.cc \
    gtest/src/gtest-printers.cc \
    gtest/src/gtest-test-part.cc \
    gtest/src/gtest-typed-test.cc \
    gtest/src/gtest.cc

HEADERS  += ui.h \
    authentication.h \
    group.h \
    student.h \
    workerxml.h \
    testauto.h \
    gtest/gtest.h \
    gtest/gtest_pred_impl.h \
    gtest/gtest_prod.h \
    gtest/gtest-death-test.h \
    gtest/gtest-message.h \
    gtest/gtest-param-test.h \
    gtest/gtest-printers.h \
    gtest/gtest-spi.h \
    gtest/gtest-test-part.h \
    gtest/gtest-typed-test.h \
    gtest/gtest-param-test.h.pump \
    gtest/internal/gtest-death-test-internal.h \
    gtest/internal/gtest-filepath.h \
    gtest/internal/gtest-internal.h \
    gtest/internal/gtest-linked_ptr.h \
    gtest/internal/gtest-param-util.h \
    gtest/internal/gtest-param-util-generated.h \
    gtest/internal/gtest-port.h \
    gtest/internal/gtest-port-arch.h \
    gtest/internal/gtest-string.h \
    gtest/internal/gtest-tuple.h \
    gtest/internal/gtest-tuple.h.pump \
    gtest/internal/gtest-type-util.h

FORMS    += ui.ui

DISTFILES += \
    gtest/internal/gtest-param-util-generated.h.pump \
    gtest/internal/gtest-type-util.h.pump
