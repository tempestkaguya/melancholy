#ifndef INITIALIZING_H
#define INITIALIZING_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>

class Initializing : public QWidget {
    Q_OBJECT
    
    public:
        explicit Initializing(QWidget *parent = nullptr);

        ~Initializing();
    private slots:
        void selectFile(); 
        QString isValidFile();
    private:
        void windowProperties();
        void openMain();
        void about_melancholy();
        void welcomeHeader(QVBoxLayout* mainLayout);
        class QLineEdit *pathBox;
};

#endif