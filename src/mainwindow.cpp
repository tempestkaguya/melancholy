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
#include <qnamespace.h>

MainWindow::MainWindow(QWidget *parent) 
    : QMainWindow(parent) 
{
    windowProperties();

    QWidget *widget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(widget);
    this->setCentralWidget(widget);

    welcomeHeader(mainLayout);
    
    QTabWidget *tabWidget = new QTabWidget(this);
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(tabWidget);

    QWidget *filePage = new QWidget(this);
    QVBoxLayout *tablay = new QVBoxLayout(filePage);

    QLabel *titleLabel = new QLabel(filePage);
    titleLabel->setText("<b>Select a binary file to load</b>");
    tablay->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    tablay->addWidget(titleLabel);

    QHBoxLayout *searchRow = new QHBoxLayout(filePage);
    pathBox = new QLineEdit(this);
    pathBox->setPlaceholderText("No file chosen...");
    pathBox->setReadOnly(true); 

    searchRow->addWidget(pathBox); 
    tablay->addLayout(searchRow);

    QPushButton *select = new QPushButton("Select file");
    tablay->addWidget(select, 0, Qt::AlignRight); 

    connect(select, &QPushButton::clicked, this, &MainWindow::selectFile);

    tablay->addStretch();

    QPushButton *button = new QPushButton();
    button->setText("Open");

    tablay->addWidget(button, 0, Qt::AlignRight | Qt::AlignBottom);   
    tabWidget->addTab(filePage, "Open File");

    QPushButton *about = new QPushButton("About us", this);
    mainLayout->addWidget(about, 0);
}

void MainWindow::welcomeHeader(QVBoxLayout* mainLayout) {
    QPixmap pixmap("../src/images/tear.png");

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

        mainLayout->addWidget(label, 0, Qt::AlignHCenter | Qt::AlignTop);
    }

    QLabel *text = new QLabel(this);
    text->setText("Welcome to Melancholy! Click 'About us' for further information!");
    text->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    mainLayout->addWidget(text);
    // layout->addStretch();
}

void MainWindow::windowProperties() {
    this->setWindowTitle("Open your file");
    this->resize(450, 600);
}

void MainWindow::selectFile() {
    QString filePath = QFileDialog::getOpenFileName(
        this, 
        "Open Binary File", 
        QDir::homePath(), 
        "All Files (*);;ELF Binaries (*)"
    );

    if (!filePath.isEmpty()) {
        pathBox->setText(filePath);
    }
}

MainWindow::~MainWindow() {}