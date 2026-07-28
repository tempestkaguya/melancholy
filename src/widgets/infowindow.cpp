#include "infowindow.h"
#include <qboxlayout.h>
#include <qlabel.h>
#include <qnamespace.h>

InfoWindow::InfoWindow(QWidget *parent) : QWidget(parent) {
    this->setWindowTitle("About Melancholy");
    this->resize(1250, 700);

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *title = new QLabel();
    title->setText("<b>Melancholy<b>");
    title->resize(50, 100);

    layout->addWidget(title, 0, Qt::AlignCenter | Qt::AlignTop);

    QPixmap img("/home/nyxshadow/melancholy/src/images/tear.png");
    QLabel *label = new QLabel(this);

    if (img.isNull()) {
        qDebug() << "Tear image from info window is bugged";
    }

    label->setPixmap(img);

    label->setFixedSize(300, 300);
    label->setScaledContents(true);

    layout->addWidget(label, 0, Qt::AlignTop | Qt::AlignCenter);

    QLabel *description = new QLabel();
    description->setText("<b>Melancholy is an open source, fast and reliable Reverse Engineering tool.");

    layout->addWidget(description, 0, Qt::AlignCenter | Qt::AlignTop);
    layout->addStretch();

    QLabel *support = new QLabel();
    support->setText("Melancholy supports only the ELF format for now, Mach-O and PE are on the works!");

    layout->addWidget(support, 0, Qt::AlignCenter | Qt::AlignTop);

    QLabel *notice = new QLabel();
    notice->setText("Furthermore we will try to expand as many family architectures as we can. Our main priorities are the following:");

    layout->addWidget(notice, 0, Qt::AlignCenter | Qt::AlignTop);

    QLabel *x86 = new QLabel();
    x86->setText("<b>x86 family architecture<b>");

    layout->addWidget(x86, 0, Qt::AlignCenter | Qt::AlignTop);

    QLabel *arm = new QLabel();
    arm->setText("<b>ARM family architecture<b>");

    layout->addWidget(arm, 0, Qt::AlignCenter | Qt::AlignTop);

    QLabel *riscv = new QLabel();
    riscv->setText("<b>RISC-V family architecture<b>");

    layout->addWidget(riscv, 0, Qt::AlignCenter | Qt::AlignTop);
}

InfoWindow::~InfoWindow() {}