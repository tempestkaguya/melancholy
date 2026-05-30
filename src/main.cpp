#include <QApplication>
#include <QtGlobal>
#include "mainwindow.h"

#ifndef Q_OS_LINUX
    #include <iostream>
    #include <cstdlib>
#endif

int main(int argc, char *argv[])
{
    #ifndef Q_OS_LINUX
        std::clog << "Melancholy is only supported on Linux." << std::endl;
        std::exit(0);
    #endif

    QApplication app(argc, argv);

    MainWindow window;
    window.show();
    
    return app.exec();
}