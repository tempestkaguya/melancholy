#include <QApplication>
#include <QtGlobal>
#include "mainwindow.h"
#include "widgets/initializing.h"
#include "widgets/close.h"

#ifndef Q_OS_LINUX
    #error "Melancholy is only supported on Linux."
#endif

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //Initializing window;
    //window.show();

    MainWindow window;
    window.show();
    
    return app.exec();
}   