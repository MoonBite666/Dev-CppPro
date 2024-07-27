
#include "dw_classdock.h"


ClassDock::ClassDock(QWidget* parent): ElaDockWidget(parent)
{
    setWindowTitle("Classes");
    setWindowIcon(QIcon(":/icons/Icon.png"));
    setMinimumSize(200,200);
}