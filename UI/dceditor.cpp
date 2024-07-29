#include "dceditor.h"
#include <QHBoxLayout>
#include <QFile>
#include <DCFileEdit.h>
#include "ElaTabWidget.h"

DCEditor::DCEditor(QWidget* parent)
    : ElaScrollPage(parent)
{
    _tabWidget = new ElaTabWidget(this);
    auto *centralWidget = new QWidget(this);
    auto *layout = new QVBoxLayout(centralWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(_tabWidget);
    addCentralWidget(centralWidget, true, true, 0);
    setTitleVisible(false);
}

void DCEditor::addTab(QFile* tabFile) {
    auto *page = new DCFileEdit(this, tabFile);
    _tabWidget->addTab(page, tabFile->fileName());

}
