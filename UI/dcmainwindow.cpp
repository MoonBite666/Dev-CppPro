#include "dcmainwindow.h"

#include <QVBoxLayout>

#include "dcmenubar.h"
#include "dw_classdock.h"
#include "dw_projectdock.h"
#include "dceditor.h"
#include "dcstatus.h"
#include "dw_tooldock.h"


DCMainWindow::DCMainWindow(QWidget* parent): ElaWindow(parent)
{

    setIsNavigationBarEnable(false);
    showMaximized();
    // moveToCenter();


    auto *editor = new DCEditor(this);
    addPageNode("EDITOR", editor, ElaIconType::House);

    auto *projectdock = new ProjectDock(this);
    this->addDockWidget(Qt::LeftDockWidgetArea,projectdock);
    resizeDocks({projectdock}, {600}, Qt::Vertical);
    resizeDocks({projectdock}, {200}, Qt::Horizontal);
    auto *classdock = new ClassDock(this);
    this->addDockWidget(Qt::LeftDockWidgetArea,classdock);
    resizeDocks({classdock}, {400}, Qt::Vertical);
    resizeDocks({classdock}, {200}, Qt::Horizontal);
    auto *tooldock = new ToolDock(this);
    this->addDockWidget(Qt::TopDockWidgetArea,tooldock);
    resizeDocks({tooldock}, {30}, Qt::Vertical);
    // resizeDocks({tooldock}, {30}, Qt::Horizontal);

    auto *menubar = new DCMenuBar(this,{projectdock,classdock,tooldock});
    setMenuBar(menubar);

    auto *statusbar = new DCStatus(this);
    setStatusBar(statusbar);

}