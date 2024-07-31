#include "dceditor.h"
#include "DCFileEdit.h"

#include <QHBoxLayout>
#include <QFile>
#include <QPainter>
#include "ElaTabWidget.h"

DCEditor::DCEditor(QWidget* parent)
    : ElaScrollPage(parent)
{
    _tabWidget = new ElaTabWidget(this);
    auto *centralWidget = new QWidget(this);
    auto *layout = new QVBoxLayout(centralWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(_tabWidget);
    addCentralWidget(centralWidget, true, false, 0);
    setTitleVisible(false);
}

QString removeFilePath(QString path) {
    path.remove(0, path.lastIndexOf('/') + 1);
    return path;
}

void DCEditor::addTab(QFile* tabFile) {
    auto *page = new DCFileEdit(this, tabFile);
    _tabWidget->addTab(page, removeFilePath(tabFile->fileName()));
}
