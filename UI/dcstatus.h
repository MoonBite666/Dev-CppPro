//
// Created by MoonFeather on 24-7-27.
//

#ifndef DCSTATUS_H
#define DCSTATUS_H

#include "ElaStatusBar.h"


class DCStatus : public ElaStatusBar{
    Q_OBJECT
public:
    DCStatus(QWidget* parent = nullptr);
    ~DCStatus() = default;

};



#endif //DCSTATUS_H
