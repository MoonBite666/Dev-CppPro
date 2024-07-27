//
// Created by MoonFeather on 24-7-27.
//

#ifndef INITWINDOW_H
#define INITWINDOW_H
#include <QObject>
#include <QWidget>


class InitWindow : public QWidget {
    Q_OBJECT
public:
    InitWindow(QWidget* parent = nullptr);
    ~InitWindow() = default;

};



#endif //INITWINDOW_H
