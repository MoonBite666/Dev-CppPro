#include "initwindow.h"

InitWindow::InitWindow(QWidget *parent) : QWidget(parent)
{
    this->resize(600,400);
    this->setWindowFlags(Qt::FramelessWindowHint);

}