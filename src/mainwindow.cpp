#include "mainwindow.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QPixmap>
#include <QDebug>
#include <QComboBox>
#include <QFileDialog>
#include <QFileInfo>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) 
    : QMainWindow(parent) 
{
    this->setWindowTitle("Open your file");
    this->resize(450, 600);

    QWidget *widget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(widget);
    this->setCentralWidget(widget);

    QPixmap pixmap("../images/tear.png");

    QLabel *label = new QLabel(this);

    if (pixmap.isNull())
    {
        label->setText("Failed to load the img");
        label->setGeometry(10, 10, 200, 30);
    }
    else
    {
        label->setPixmap(pixmap);

        label->setFixedSize(100, 150);
        label->setScaledContents(true);

        layout->addWidget(label, 0, Qt::AlignHCenter | Qt::AlignTop);
    }

    QLabel *text = new QLabel(this);
    text->setText("Welcome to Melancholy! Click 'About us' for further information!");
    text->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    layout->addWidget(text);
    // layout->addStretch();

    QTabWidget *tabWidget = new QTabWidget(this);
    layout->setAlignment(Qt::AlignCenter);
    layout->addWidget(tabWidget);

    QWidget *filePage = new QWidget(this);
    QVBoxLayout *tablay = new QVBoxLayout(filePage);

    QLabel *titleLabel = new QLabel(filePage);
    titleLabel->setText("<b>Select a binary file to load</b>");
    tablay->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    tablay->addWidget(titleLabel);

    QHBoxLayout *searchRow = new QHBoxLayout(filePage);
    QLineEdit *pathBox = new QLineEdit();
    pathBox->setPlaceholderText("No file chosen...");
    pathBox->setReadOnly(true);

    searchRow->addWidget(pathBox);
    tablay->addLayout(searchRow);
    tablay->addStretch();

    QPushButton *button = new QPushButton("Open");
    tablay->addWidget(button, 0, Qt::AlignRight);   

    tabWidget->addTab(filePage, "Open File");

    QPushButton *about = new QPushButton("About us", this);
    layout->addWidget(about, 0);
}

MainWindow::~MainWindow() {}