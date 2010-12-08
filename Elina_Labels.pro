TEMPLATE = app
TARGET = Elina_Labels
QT += core \
    gui \
    sql \
    network
HEADERS += r3a.h \
    constants.h \
    production.h \
    mainwindow.h \
    login.h \
    scanlabels.h \
    elina_labels.h
SOURCES += r3a.cpp \
    production.cpp \
    mainwindow.cpp \
    login.cpp \
    scanlabels.cpp \
    main.cpp \
    elina_labels.cpp
FORMS += r3a.ui \
    production.ui \
    mainwindow.ui \
    login.ui \
    scanlabels.ui \
    elina_labels.ui
RESOURCES += 
