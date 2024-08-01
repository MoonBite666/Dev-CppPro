#ifndef DCLINENUMBERAREA_H
#define DCLINENUMBERAREA_H
#include <QWidget>
#include "Def.h"


class DCTextEdit;
class DCLineNumberArea : public QWidget {
public:
    explicit DCLineNumberArea(DCTextEdit* editor);
    QSize sizeHint() const override;
    QColor _lineNumberColor;
    QColor _lineNumberBgColor;

protected:
    void paintEvent(QPaintEvent *event) override;

    private slots:
        void onThemeChange(ElaThemeType::ThemeMode themeMode);
private:
    DCTextEdit *_code_editor;
    ElaThemeType::ThemeMode _themeMode;
};



#endif //DCLINENUMBERAREA_H
