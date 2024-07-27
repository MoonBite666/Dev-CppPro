#include "dw_tooldock.h"

ToolDock::ToolDock(QWidget* parent) : ElaDockWidget(parent)
{
    setWindowTitle("Tools");
    setMinimumSize(200, 50);
}