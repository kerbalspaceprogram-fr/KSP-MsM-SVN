#-------------------------------------------------
#
# Project created by QtCreator 2013-12-02T18:50:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KspSvn
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    "Resources\Res.qrc"

LIBS += "D:\Projets Qt\build-fdsq-Static-Debug\debug\libfdsq.a" \
"D:\SVN\lib\libsvn_client-1.lib" "D:\SVN\lib\libsvn_delta-1.lib" "D:\SVN\lib\libsvn_diff-1.lib" "D:\SVN\lib\libsvn_fs_base-1.lib" "D:\SVN\lib\libsvn_fs_fs-1.lib" "D:\SVN\lib\libsvn_fs_util-1.lib" "D:\SVN\lib\libsvn_fs-1.lib" "D:\SVN\lib\libsvn_ra_local-1.lib" "D:\SVN\lib\libsvn_ra_neon-1.lib" "D:\SVN\lib\libsvn_ra_serf-1.lib" "D:\SVN\lib\libsvn_ra_svn-1.lib" "D:\SVN\lib\libsvn_ra-1.lib" "D:\SVN\lib\libsvn_repos-1.lib" "D:\SVN\lib\libsvn_subr-1.lib" "D:\SVN\lib\libsvn_wc-1.lib" "D:\SVN\lib\svn_client-1.lib" "D:\SVN\lib\svn_delta-1.lib" "D:\SVN\lib\svn_diff-1.lib" "D:\SVN\lib\svn_fs-1.lib" "D:\SVN\lib\svn_ra-1.lib" "D:\SVN\lib\svn_repos-1.lib" "D:\SVN\lib\svn_subr-1.lib" "D:\SVN\lib\svn_wc-1.lib" \
"D:\SVN\lib\apr\libapr-1.lib" "D:\SVN\lib\apr-util\libaprutil-1.lib"

INCLUDEPATH += $$PWD/../../SVN/include "D:\SVN\SVNCPPQT\include\svncpp"
DEPENDPATH += $$PWD/../../SVN/include "D:\SVN\SVNCPPQT\include\svncpp"
INCLUDEPATH += $$PWD/../../SVN/include/apr
DEPENDPATH += $$PWD/../../SVN/include/apr
