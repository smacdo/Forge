###
### Forge QMake script
###
TEMPLATE     = app
TARGET       = forge
VERSION      = 0.1.1
DEPENDPATH  += src
INCLUDEPATH += src
QT          += core opengl network sql xml
CONFIG      += embed_manifest_exe
MOC_DIR      = .build/moc
OBJECTS_DIR  = .build/obj

HEADERS += src/gameclient.h \
           src/gameserver.h \
           src/logger.h \
           src/loginwindow.h \
           src/gamewindow.h \
           src/clientview.h \
           src/chatwidget.h

SOURCES += src/forge.cpp \
           src/gameclient.cpp \
           src/gameserver.cpp \
           src/loginwindow.cpp \
           src/gamewindow.cpp \
           src/clientview.cpp \
           src/chatwidget.cpp
