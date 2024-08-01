#include "DCTextEdit.h"
#include <QFile>
#include <QPainter>
#include <QScrollBar>
#include <QTextBlock>
#include "ElaTextEdit.h"
#include "ElaTheme.h"
#include "DCLineNumberArea.h"
#include "DCFontManager.h"



DCTextEdit::DCTextEdit(QWidget *parent, QFile *file, DCFontManager *font_manager)
    : ElaTextEdit(parent),
      _file(file), _font_manager(font_manager) {
    setContentsMargins(0,0,0,0);
    _lineNumberArea = new DCLineNumberArea(this);
    _themeMode = eTheme->getThemeMode();
    onThemeChange(_themeMode);
    connect(eTheme, &ElaTheme::themeModeChanged, this, &DCTextEdit::onThemeChange);
    connect(this, &DCTextEdit::blockCountChanged, this, &DCTextEdit::updateLineNumberAreaWidth);
    connect(this, &DCTextEdit::updateRequest, this, &DCTextEdit::updateLineNumberArea);
    connect(this, &DCTextEdit::cursorPositionChanged, this, &DCTextEdit::highlightCurrentLine);
    updateLineNumberAreaWidth(0);
    setFont(_font_manager->normal_font());
    highlightCurrentLine();
}

int DCTextEdit::lineNumberAreaWidth() {
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = 3 + fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;
    return space;
}


void DCTextEdit::resizeEvent(QResizeEvent *event) {
    ElaTextEdit::resizeEvent(event);
    QRect cr = contentsRect();
    _lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

void DCTextEdit::lineNumberAreaPaintEvent(QPaintEvent *event) {
    QPainter painter(_lineNumberArea);
    painter.fillRect(event->rect(), _lineNumberArea->palette().window().color());
    auto font = painter.font();
    font.setPointSize(this->font().pointSize() - 1);
    painter.setFont(font);
    auto block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = static_cast<int>(blockBoundingGeometry(block).translated(contentOffset()).top());
    int bottom = top + static_cast<int>(blockBoundingRect(block).height());

    while (block.isValid() && top <= event->rect().bottom()) {
        if(block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(_lineNumberArea->palette().text().color());
            painter.drawText(0, top+this->font().pointSize()/4, _lineNumberArea->width(), fontMetrics().height(), Qt::AlignRight, number);
        }
        block = block.next();
        top = bottom;
        bottom = top + static_cast<int>(blockBoundingRect(block).height());
        ++blockNumber;
    }
}

void DCTextEdit::updateLineNumberArea(const QRect &rect, int dy) {
    if(dy) _lineNumberArea->scroll(0,dy);
    else _lineNumberArea->update(0, rect.y(), _lineNumberArea->width(), rect.height());
    if (rect.contains(viewport()->rect())) updateLineNumberAreaWidth(0);
}

void DCTextEdit::updateLineNumberAreaWidth(int) {
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

void DCTextEdit::highlightCurrentLine() {
    QList<QTextEdit::ExtraSelection> extraSelections;

    if(!isReadOnly()) {
        QTextEdit::ExtraSelection selection;

        const QColor lineColor = _linePalette.window().color();

        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }
    setExtraSelections(extraSelections);
}

void DCTextEdit::onThemeChange(ElaThemeType::ThemeMode themeMode) {
    _themeMode = themeMode;

    if (themeMode == ElaThemeType::Light)
    {
        _linePalette.setColor(QPalette::Window, QColor::fromString("#edf6f9"));
        _linePalette.setColor(QPalette::Text, QColor::fromString("#161b33"));
    }
    else
    {
        _linePalette.setColor(QPalette::Window, QColor::fromString("#5c677d").darker(200));
        _linePalette.setColor(QPalette::Text, QColor::fromString("#f4f4f6"));
    }
    this->setPalette(_linePalette);
    this->highlightCurrentLine();

}
