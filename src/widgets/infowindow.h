#ifndef INFOWINDOW_H
#define INFOWINDOW_H

#include <QWidget>

class InfoWindow : public QWidget {
    Q_OBJECT
public:
    explicit InfoWindow(QWidget *parent = nullptr);

    ~InfoWindow();
};  
    
#endif