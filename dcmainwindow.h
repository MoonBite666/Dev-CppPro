#ifndef DCMAINWINDOW_H
#define DCMAINWINDOW_H

#include <QMainWindow>

class DCMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    DCMainWindow(QWidget *parent = nullptr);
    ~DCMainWindow();
};
#endif // DCMAINWINDOW_H
