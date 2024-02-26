QT       += core gui sql
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agreementpage.cpp \
    calendar.cpp \
    ceo.cpp \
    client.cpp \
    clientloginpage.cpp \
    employee.cpp \
    founder.cpp \
    genpeople.cpp \
    investor.cpp \
    joinpart.cpp \
    loadingpage.cpp \
    main.cpp \
    mainwindow.cpp \
    signuppage.cpp \
    teampage.cpp

HEADERS += \
    agreementpage.h \
    calendar.h \
    ceo.h \
    client.h \
    clientloginpage.h \
    employee.h \
    founder.h \
    genpeople.h \
    investor.h \
    joinpart.h \
    loadingpage.h \
    mainwindow.h \
    signuppage.h \
    teampage.h

FORMS += \
    agreementpage.ui \
    calendar.ui \
    ceo.ui \
    client.ui \
    clientloginpage.ui \
    employee.ui \
    founder.ui \
    investor.ui \
    joinpart.ui \
    loadingpage.ui \
    mainwindow.ui \
    signuppage.ui \
    teampage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    media.qrc

DISTFILES += \
    Agreementpage.txt
