#ifndef DCMAINWINDOW_H
#define DCMAINWINDOW_H

#include "ElaWindow.h"

#include <QMainWindow>



class DCMainWindow : public ElaWindow
{
    Q_OBJECT

public:
    DCMainWindow(QWidget* parent = nullptr);
    ~DCMainWindow();


private:

};
#endif // DCMAINWINDOW_H
