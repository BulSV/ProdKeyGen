QT       += widgets

TEMPLATE = app
#win32:RC_FILE = ProdKeyGen.rc
#CONFIG += console
CONFIG(debug, debug|release) {
    TARGET = ProdKeyGenProd

    DEFINES += DEBUG
}
else {
    TARGET = ProdKeyGenPro
}

HEADERS += \
    Dialog.h

SOURCES += \
    Dialog.cpp \
    main.cpp

#RESOURCES += \
#    ProdKeyGen.qrc
