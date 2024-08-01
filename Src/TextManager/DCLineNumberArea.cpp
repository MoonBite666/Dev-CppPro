#include "DCLineNumberArea.h"
#include "DCTextEdit.h"
#include "ElaTheme.h"

DCLineNumberArea::DCLineNumberArea(DCTextEdit *editor)
    : QWidget(editor),
      _code_editor(editor) {
    _themeMode = eTheme->getThemeMode();
    onThemeChange(_themeMode);
    connect(eTheme, &ElaTheme::themeModeChanged, this, &DCLineNumberArea::onThemeChange);
}
QSize DCLineNumberArea::sizeHint() const {
    return {_code_editor->lineNumberAreaWidth(), 0};
}

void DCLineNumberArea::paintEvent(QPaintEvent *event) {
    _code_editor->lineNumberAreaPaintEvent(event);
}
void DCLineNumberArea::onThemeChange(ElaThemeType::ThemeMode themeMode) {
    _themeMode = themeMode;
    QPalette palette = this->palette();

    if (themeMode == ElaThemeType::Light)
    {
        palette.setColor(QPalette::Text, QColor::fromString("#495057").lighter(200));
        palette.setColor(QPalette::Window, QColor::fromString("#f3f2f9"));
    }
    else
    {
        palette.setColor(QPalette::Text, QColor::fromString("#ced4da").darker());
        palette.setColor(QPalette::Window, QColor::fromString("#282c3a"));
    }
    this->setPalette(palette);

}