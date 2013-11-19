TEMPLATE = app
TARGET = Elina_Labels
QT += core \
    gui \
    sql \
    network
HEADERS += rewrap.h \
    mainwindow.h \
    ktreport.h \
    r3a.h \
    constants.h \
    production.h \
    login.h \
    elina_labels.h \
    mailsender.h
SOURCES += rewrap.cpp \
    mainwindow.cpp \
    ktreport.cpp \
    r3a.cpp \
    production.cpp \
    login.cpp \
    main.cpp \
    elina_labels.cpp \
    mailsender.cpp
FORMS += rewrap.ui \
    mainwindow.ui \
    ktreport.ui \
    r3a.ui \
    production.ui \
    login.ui \
    elina_labels.ui
RESOURCES += 
CONFIG += serialport
