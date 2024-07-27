//
// Created by MoonFeather on 24-7-27.
//

#ifndef DW_TOOLDOCK_H
#define DW_TOOLDOCK_H
#include "ElaDockWidget.h"


class ToolDock : public ElaDockWidget {
    Q_OBJECT
public:
    ToolDock(QWidget* parent = nullptr);
    ~ToolDock() = default;
};



#endif //DW_TOOLDOCK_H
