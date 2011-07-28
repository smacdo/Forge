###
### Forge QMake script
###
TEMPLATE     = app
TARGET       = Forge
VERSION      = 0.1.1
DEPENDPATH  += src
INCLUDEPATH += src
QT          += core opengl network sql xml
CONFIG      += embed_manifest_exe
MOC_DIR      = .build/moc
OBJECTS_DIR  = .build/obj

HEADERS += src/client/gameclient.h \
           src/client/gamewindow.h \
           src/client/clientview.h \
           src/client/chatwidget.h \
           src/client/loginwindow.h \
           src/server/gameserver.h \

SOURCES += src/forge.cpp \
           src/client/gameclient.cpp \
           src/client/loginwindow.cpp \
           src/client/gamewindow.cpp \
           src/client/clientview.cpp \
           src/client/chatwidget.cpp \
           src/server/gameserver.cpp
