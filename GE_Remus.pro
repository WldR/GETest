#-------------------------------------------------
#
# Project created by QtCreator 2015-06-24T13:10:01
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = GE_Remus
CONFIG   += console
CONFIG   -= app_bundle


TEMPLATE = app

INCLUDEPATH += jsoncpp-master/include
#INCLUDEPATH += curlpp-master/include
INCLUDEPATH += curl-7.43.0/include


LIBS += -lcurl

SOURCES += main.cpp \
    JsonReader.cpp \
    jsoncpp-master/src/lib_json/json_value.cpp \
    jsoncpp-master/src/lib_json/json_reader.cpp \
    jsoncpp-master/src/lib_json/json_writer.cpp \
    OnlineUtils.cpp \
    Response.cpp

#HEADERS += \
#    curlpp-master/include/curlpp/cURLpp.hpp \
#    curlpp-master/include/curlpp/Easy.hpp \
#    curlpp-master/include/curlpp/Option.hpp \
#    curlpp-master/include/curlpp/OptionBase.hpp \
#    curlpp-master/include/curlpp/Options.hpp \
#    curlpp-master/include/curlpp/Exception.hpp \
#    curlpp-master/include/curlpp/Form.hpp \
#    curlpp-master/include/curlpp/Info.hpp \
#    curlpp-master/include/curlpp/Infos.hpp \
#    curlpp-master/include/curlpp/Multi.hpp \
#    curlpp-master/include/curlpp/Types.hpp

HEADERS += \
    JsonReader.h \
    Response.h \
    OnlineUtils.h
