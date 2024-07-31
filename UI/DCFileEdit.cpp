#include "DCFileEdit.h"

#include <qevent.h>
#include <QFile>
#include <QPainter>
#include <QScrollBar>
#include <QTextBlock>
#include "ElaTextEdit.h"
#include "ElaTheme.h"


LineNumberArea::LineNumberArea(DCFileEdit *editor)
    : QWidget(editor),
      _code_editor(editor) {
    _themeMode = eTheme->getThemeMode();
    onThemeChange(_themeMode);
    connect(eTheme, &ElaTheme::themeModeChanged, this, &LineNumberArea::onThemeChange);
}
QSize LineNumberArea::sizeHint() const {
    return {_code_editor->lineNumberAreaWidth(), 0};
}

void LineNumberArea::paintEvent(QPaintEvent *event) {
    _code_editor->lineNumberAreaPaintEvent(event);
}
void LineNumberArea::onThemeChange(ElaThemeType::ThemeMode themeMode) {
    _themeMode = themeMode;
    QPalette palette = this->palette();

    if (themeMode == ElaThemeType::Light)
    {
        palette.setColor(QPalette::Text, Qt::black);
        palette.setColor(QPalette::Window, QColor::fromString("#a2d2ff"));
    }
    else
    {
        palette.setColor(QPalette::Text, Qt::white);
        palette.setColor(QPalette::Window, QColor::fromString("#457b9d"));
    }
    this->setPalette(palette);
}



DCFileEdit::DCFileEdit(QWidget *parent, QFile *file)
    : ElaTextEdit(parent),
      _file(file) {
    _lineNumberArea = new LineNumberArea(this);
    connect(this, &DCFileEdit::blockCountChanged, this, &DCFileEdit::updateLineNumberAreaWidth);
    connect(this, &DCFileEdit::updateRequest, this, &DCFileEdit::updateLineNumberArea);
    // connect(this, &DCFileEdit::cursorPositionChanged, this, &DCFileEdit::updateLineNumberAreaWidth);
    updateLineNumberAreaWidth(0);
}

int DCFileEdit::lineNumberAreaWidth() {
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = 3 + fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;
    return space;
}


void DCFileEdit::resizeEvent(QResizeEvent *event) {
    ElaTextEdit::resizeEvent(event);
    QRect cr = contentsRect();
    _lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

void DCFileEdit::lineNumberAreaPaintEvent(QPaintEvent *event) {
    QPainter painter(_lineNumberArea);
    painter.fillRect(event->rect(), _lineNumberArea->palette().window().color());
    auto font = painter.font();
    font.setPointSize(18);
    painter.setFont(font);
    auto block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = static_cast<int>(blockBoundingGeometry(block).translated(contentOffset()).top());
    int bottom = top + static_cast<int>(blockBoundingRect(block).height());

    while (block.isValid() && top <= event->rect().bottom()) {
        if(block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(_lineNumberArea->palette().text().color());
            painter.drawText(0, top, _lineNumberArea->width(), fontMetrics().height(), Qt::AlignRight, number);
        }
        block = block.next();
        top = bottom;
        bottom = top + static_cast<int>(blockBoundingRect(block).height());
        ++blockNumber;
    }
}

void DCFileEdit::updateLineNumberArea(const QRect &rect, int dy) {
    if(dy) _lineNumberArea->scroll(0,dy);
    else _lineNumberArea->update(0, rect.y(), _lineNumberArea->width(), rect.height());
    if (rect.contains(viewport()->rect())) updateLineNumberAreaWidth(0);
}

void DCFileEdit::updateLineNumberAreaWidth(int) {
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}




