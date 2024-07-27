#ifndef DW_PROJECTWIDGET_H
#define DW_PROJECTWIDGET_H

#include "ElaDockWidget.h"


class ProjectDock : public ElaDockWidget{
    Q_OBJECT
public:
    ProjectDock(QWidget* parent = nullptr);
    ~ProjectDock() = default;

};



#endif //DW_PROJECTWIDGET_H
