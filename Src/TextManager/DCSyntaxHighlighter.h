#ifndef DCSYNTAXHIGHLIGHTER_H
#define DCSYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QRegularExpression>

#include "Def.h"

class DCFontManager;
QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

class DCSyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    DCSyntaxHighlighter(QTextDocument *parent = nullptr, DCFontManager* font_manager = nullptr);

protected:
    void highlightBlock(const QString &text) override;

private:
    struct HighlightingRule
    {
        QRegularExpression pattern;
        QTextCharFormat format;
        QString formatName;
    };
    QVector<HighlightingRule> highlightingRules;

    QRegularExpression commentStartExpression;
    QRegularExpression commentEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat functionFormat;
    QTextCharFormat globalVarFormat;
    QTextCharFormat localVarFotmat;
    QTextCharFormat escapeSequenceFormat;
    QTextCharFormat numberFormat;
    QTextCharFormat stringFormat;
    QTextCharFormat preprocessorFormat;
    QTextCharFormat headerPathFormat;
    QTextCharFormat macroFormat;


    DCFontManager *_font_manager;
    QMap<QString, QColor> *_highlightColorMap;
    ElaThemeType::ThemeMode _themeMode;
    QString _current;
private slots:
    void onThemeChange(ElaThemeType::ThemeMode themeMode);
};



#endif //DCSYNTAXHIGHLIGHTER_H
