//
// Created by MoonFeather on 24-7-27.
//

#ifndef DW_TOOLDOCK_H
#define DW_TOOLDOCK_H
#include "ElaDockWidget.h"


class DCToolDock : public ElaDockWidget {
    Q_OBJECT
public:
    explicit DCToolDock(QWidget* parent = nullptr);
    ~DCToolDock() override = default;
};



#endif //DW_TOOLDOCK_H
