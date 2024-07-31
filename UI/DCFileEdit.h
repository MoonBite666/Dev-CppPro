#ifndef DCFILEEDIT_H
#define DCFILEEDIT_H

#include "ElaTextEdit.h"

class ElaTextEdit;
class QFile;

class DCFileEdit;
class LineNumberArea : public QWidget {
public:
    explicit LineNumberArea(DCFileEdit* editor);
    QSize sizeHint() const override;
    QColor _lineNumberColor;
    QColor _lineNumberBgColor;

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void onThemeChange(ElaThemeType::ThemeMode themeMode);
private:
    DCFileEdit *_code_editor;
    ElaThemeType::ThemeMode _themeMode;

};

class DCFileEdit : public ElaTextEdit{
public:
    explicit DCFileEdit(QWidget* parent = nullptr, QFile* file = nullptr);
    ~DCFileEdit() override = default;
    int lineNumberAreaWidth();
    void lineNumberAreaPaintEvent(QPaintEvent* event);

protected:
    void resizeEvent(QResizeEvent *event) override;


private slots:
    void updateLineNumberAreaWidth(int /* newBlockCount */);
    void updateLineNumberArea(const QRect &rect, int dy);


private:
    QFile* _file;
    QByteArray _filedata;
    QWidget *_lineNumberArea;
};



#endif //DCFILEEDIT_H
