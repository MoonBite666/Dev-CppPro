

#include "dw_projectdock.h"
#include <QApplication>

ProjectDock::ProjectDock(QWidget* parent): ElaDockWidget(parent)
{
    setWindowTitle("Project");
    setWindowIcon(QIcon(":/icons/Icon.png"));
    setMinimumSize(200,200);
}