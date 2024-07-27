#include "dceditor.h"
#include <QVBoxLayout>
#include <QTextEdit>
#include "ElaText.h"
#include "ElaTabWidget.h"
#include "ElaText.h"

DCEditor::DCEditor(QWidget* parent)
    : ElaScrollPage(parent)
{
    _tabWidget = new ElaTabWidget(this);
    auto *page1 = new QTextEdit(this);
    auto font = page1->font();
    font.setPointSize(20);
    page1->setFont(font);
    _tabWidget->addTab(page1,"新标签页1");


    auto *centralWidget = new QWidget(this);
    auto *layout = new QVBoxLayout(centralWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(_tabWidget);
    addCentralWidget(centralWidget, true, true, 0);
    setTitleVisible(false);
}
