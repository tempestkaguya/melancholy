#include "mainwindow.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QPixmap>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QDebug>
#include <QCloseEvent>
#include <QComboBox>
#include <QFileDialog>
#include <QFileInfo>
#include <QLineEdit>
#include <QMessageBox>
#include <qaction.h>
#include <qkeysequence.h>
#include <qmessagebox.h>
#include <widgets/infowindow.h>
#include <widgets/initializing.h>
#include <widgets/close.h>

MainWindow::MainWindow(QWidget *parent) 
    : QMainWindow(parent) 
{
    this->showMaximized();
    this->setWindowTitle("Melancholy");

    qDebug() << "MAIN WINDOW OPENED!";

    QMenu *file = menuBar()->addMenu("&File");
    QAction *openAction = new QAction("New Window", this);
    openAction->setShortcut(QKeySequence("Ctrl+N"));

    QAction *quit = new QAction("Quit", this);
    quit->setShortcut(QKeySequence("Ctrl+Q"));

    file->addAction(openAction);

    file->addSeparator();
    file->addAction(quit);

    QMenu *help = menuBar()->addMenu("&Help");

    QAction *about = new QAction("About", this);
    help->addAction(about);
}

void MainWindow::closeEvent(QCloseEvent *event) {
    auto reply = QMessageBox::question(this, "Melancholy", "Do you really want to quit?", 
        QMessageBox::Yes, QMessageBox::No
    );

    if (reply == QMessageBox::Yes) {
        event->accept();
    } else {
        event->ignore();
    }
}

/*MainWindow::~MainWindow() {
    qDebug() << "does this shit even fire?";
    Initializing *initializer = new Initializing();
    initializer->show();
}*/