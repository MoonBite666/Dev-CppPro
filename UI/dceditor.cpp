#include "dceditor.h"
#include "TextManager/DCTextEdit.h"
#include "TextManager/DCSyntaxHighlighter.h"
#include "TextManager/DCFontManager.h"

#include <QHBoxLayout>
#include <QFile>
#include <QPainter>
#include "ElaTabWidget.h"

DCEditor::DCEditor(QWidget* parent)
    : ElaScrollPage(parent,false)
{
    setContentsMargins(0,0,0,0);
    _tabWidget = new ElaTabWidget(this);
    auto *centralWidget = new QWidget(this);
    auto *layout = new QVBoxLayout(centralWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(_tabWidget);
    addCentralWidget(centralWidget, true, false, 0);
    setTitleVisible(false);

    _font_manager = new DCFontManager(this);
}

QString removeFilePath(QString path) {
    path.remove(0, path.lastIndexOf('/') + 1);
    return path;
}

void DCEditor::addTab(QFile* tabFile) {
    auto *page = new DCTextEdit(this, tabFile,_font_manager);
    auto *highlighter = new DCSyntaxHighlighter(page->document(),_font_manager);
    _tabWidget->addTab(page, removeFilePath(tabFile->fileName()));
}
