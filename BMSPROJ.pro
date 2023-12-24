QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminauthenticationdialog.cpp \
    admindialog.cpp \
    bankmanagerdialog.cpp \
    currentuser.cpp \
    currentuserbalancedialog.cpp \
    currentuserdepositdialog.cpp \
    currentuserloggedin.cpp \
    currentuserwithdrawdialog.cpp \
    logindialog.cpp \
    main.cpp \
    managerauthenticationdialog.cpp \
    managerauthenticationdialog2.cpp \
    newuser.cpp \
    startdialog.cpp \
    userchequehistorydialog.cpp \
    userchequesdialog.cpp \
    userdialog.cpp \
    usertransaction.cpp

HEADERS += \
    adminauthenticationdialog.h \
    admindialog.h \
    bankmanagerdialog.h \
    currentuser.h \
    currentuserbalancedialog.h \
    currentuserdepositdialog.h \
    currentuserloggedin.h \
    currentuserwithdrawdialog.h \
    logindialog.h \
    managerauthenticationdialog.h \
    managerauthenticationdialog2.h \
    newuser.h \
    startdialog.h \
    userchequehistorydialog.h \
    userchequesdialog.h \
    userdialog.h \
    usertransaction.h

FORMS += \
    adminauthenticationdialog.ui \
    admindialog.ui \
    bankmanagerdialog.ui \
    currentuser.ui \
    currentuserbalancedialog.ui \
    currentuserdepositdialog.ui \
    currentuserloggedin.ui \
    currentuserwithdrawdialog.ui \
    logindialog.ui \
    managerauthenticationdialog.ui \
    managerauthenticationdialog2.ui \
    newuser.ui \
    startdialog.ui \
    userchequehistorydialog.ui \
    userchequesdialog.ui \
    userdialog.ui \
    usertransaction.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc
