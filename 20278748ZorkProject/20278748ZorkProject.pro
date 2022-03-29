QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Room.cpp \
    ZorkUL.cpp \
    character.cpp \
    enemy.cpp \
    image.cpp \
    item.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    tool.cpp \
    weapon.cpp \
    wordle.cpp \
    zombie.cpp

HEADERS += \
    Room.h \
    ZorkUL.h \
    character.h \
    enemy.h \
    image.h \
    item.h \
    mainwindow.h \
    player.h \
    tool.h \
    weapon.h \
    wordle.h \
    zombie.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ZorkAssessmentCriteria \
    wordle_guesses.txt \
    wordle_solutions.txt
