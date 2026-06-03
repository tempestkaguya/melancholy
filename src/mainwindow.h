#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>

class MainWindow : public QMainWindow {
    Q_OBJECT
    
    public:
        MainWindow(QWidget *parent = nullptr);

        ~MainWindow();
    private slots:
        void selectFile();    
    private:
        void windowProperties();
        void welcomeHeader(QVBoxLayout* mainLayout);
        class QLineEdit *pathBox;
};

#endif