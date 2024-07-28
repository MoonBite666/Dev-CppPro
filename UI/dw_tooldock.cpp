#include "dw_tooldock.h"

DCToolDock::DCToolDock(QWidget* parent) : ElaDockWidget(parent)
{
    setWindowTitle("Tools");
    setMinimumSize(200, 50);
}