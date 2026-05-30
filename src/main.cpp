#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QPixmap>
#include <QDebug>
#include <qnamespace.h>
#include <qpushbutton.h>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);    

    QMainWindow *window = new QMainWindow();
    window->setWindowTitle("Open your file");
    window->resize(450, 600);

    QWidget *widget = new QWidget(window);
    QVBoxLayout *layout = new QVBoxLayout(widget);
    window->setCentralWidget(widget);

    QPixmap pixmap("../images/tear.png");

    QLabel *label = new QLabel(window);

    if (pixmap.isNull()) {
        label->setText("Failed to load the img");
        label->setGeometry(10, 10, 200, 30);
    } else {
        label->setPixmap(pixmap);

        label->setFixedSize(100, 150);
        label->setScaledContents(true);

        layout->addWidget(label, 0, Qt::AlignHCenter | Qt::AlignTop);

        QLabel *text = new QLabel(window);
        text->setText("Welcome to Melancholy! Click 'About us' for further information!");
        text->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

        layout->addWidget(text);
        layout->addStretch();

        QPushButton *about = new QPushButton("About us", window);
        layout->addWidget(about, 0);
    }

    window->show();
    return app.exec();
}