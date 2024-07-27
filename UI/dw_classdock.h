//
// Created by MoonFeather on 24-7-27.
//

#ifndef DW_CLASSDOCK_H
#define DW_CLASSDOCK_H



#include "ElaDockWidget.h"


class ClassDock : public ElaDockWidget{
    Q_OBJECT
public:
    ClassDock(QWidget* parent = nullptr);
    ~ClassDock() = default;

};


#endif //DW_CLASSDOCK_H
