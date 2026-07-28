// NOT USED ANYMORE

/*
#include "close.h"
#include <QVBoxLayout>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qnamespace.h>
#include <qpushbutton.h>

Close::Close(QWidget *parent) : QWidget(parent) {
    this->setWindowTitle("Melancholy");
    this->resize(200, 75);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("<b>Do you really want to exit?<b>");
    layout->addWidget(label, 0, Qt::AlignTop | Qt::AlignCenter);

    QHBoxLayout *buttonsLayer = new QHBoxLayout();

    buttonsLayer->addWidget(new QPushButton("Close without saving"));
    buttonsLayer->addWidget(new QPushButton("Cancel"));
    buttonsLayer->addWidget(new QPushButton("Save"));

    layout->addLayout(buttonsLayer);
}

Close::~Close() {}*/