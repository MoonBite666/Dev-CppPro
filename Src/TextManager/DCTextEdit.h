#ifndef DCFILEEDIT_H
#define DCFILEEDIT_H

#include "ElaTextEdit.h"

class DCFontManager;
class ElaTextEdit;
class QFile;
class DCTextEdit : public ElaTextEdit {
public:
    explicit DCTextEdit(QWidget* parent = nullptr, QFile* file = nullptr, DCFontManager* font_manager = nullptr);
    ~DCTextEdit() override = default;
    int lineNumberAreaWidth();
    void lineNumberAreaPaintEvent(QPaintEvent* event);

protected:
    void resizeEvent(QResizeEvent *event) override;


    private slots:
        void updateLineNumberAreaWidth(int /* newBlockCount */);
    void updateLineNumberArea(const QRect &rect, int dy);
    void highlightCurrentLine();
    void onThemeChange(ElaThemeType::ThemeMode themeMode);


private:
    QFile* _file;
    QByteArray _filedata;
    QWidget *_lineNumberArea;
    ElaThemeType::ThemeMode _themeMode;
    QPalette _linePalette;
    DCFontManager *_font_manager;
};


#endif //DCFILEEDIT_H
