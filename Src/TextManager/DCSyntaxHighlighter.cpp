#include "DCSyntaxHighlighter.h"

#include <QThread>

#include "DCFontManager.h"
#include "ElaTheme.h"

DCSyntaxHighlighter::DCSyntaxHighlighter(QTextDocument *parent, DCFontManager *font_manager)
    : QSyntaxHighlighter(parent), _font_manager(font_manager)
{
    _highlightColorMap = new QMap<QString, QColor>();
    _themeMode = eTheme->getThemeMode();

    connect(eTheme, &ElaTheme::themeModeChanged, this, &DCSyntaxHighlighter::onThemeChange);
    connect(eTheme, &ElaTheme::themeModeChanged, this, &DCSyntaxHighlighter::rehighlight);
    onThemeChange(_themeMode);

    HighlightingRule rule;
    keywordFormat.setFont(_font_manager->bold_font());
    keywordFormat.setFontWeight(QFont::Bold);
    const QString keywordPatterns[] = {
        QStringLiteral("\\bchar\\b"), QStringLiteral("\\bclass\\b"), QStringLiteral("\\bconst\\b"),
        QStringLiteral("\\bdouble\\b"), QStringLiteral("\\benum\\b"), QStringLiteral("\\bexplicit\\b"),
        QStringLiteral("\\bfriend\\b"), QStringLiteral("\\binline\\b"), QStringLiteral("\\bint\\b"),
        QStringLiteral("\\blong\\b"), QStringLiteral("\\bnamespace\\b"), QStringLiteral("\\boperator\\b"),
        QStringLiteral("\\bprivate\\b"), QStringLiteral("\\bprotected\\b"), QStringLiteral("\\bpublic\\b"),
        QStringLiteral("\\bshort\\b"), QStringLiteral("\\bsignals\\b"), QStringLiteral("\\bsigned\\b"),
        QStringLiteral("\\bslots\\b"), QStringLiteral("\\bstatic\\b"), QStringLiteral("\\bstruct\\b"),
        QStringLiteral("\\btemplate\\b"), QStringLiteral("\\btypedef\\b"), QStringLiteral("\\btypename\\b"),
        QStringLiteral("\\bunion\\b"), QStringLiteral("\\bunsigned\\b"), QStringLiteral("\\bvirtual\\b"),
        QStringLiteral("\\bvoid\\b"), QStringLiteral("\\bvolatile\\b"), QStringLiteral("\\bbool\\b")
    };
    for (const QString &pattern : keywordPatterns) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        rule.formatName = "Keyword";
        highlightingRules.append(rule);
    }

    classFormat.setFont(_font_manager->bold_font());
    classFormat.setFontWeight(QFont::Bold);
    rule.pattern = QRegularExpression(QStringLiteral("\\bQ[A-Za-z]+\\b"));
    rule.format = classFormat;
    rule.formatName = "Class";
    highlightingRules.append(rule);

    singleLineCommentFormat.setFont(_font_manager->normal_font());
    rule.pattern = QRegularExpression(QStringLiteral("//[^\n]*"));
    rule.format = singleLineCommentFormat;
    rule.formatName = "Comment";
    highlightingRules.append(rule);

    multiLineCommentFormat.setFont(_font_manager->normal_font());
    rule.pattern = QRegularExpression(QStringLiteral("/\\*"));
    rule.format = multiLineCommentFormat;
    rule.formatName = "Comment";
    highlightingRules.append(rule);

    quotationFormat.setFont(_font_manager->normal_font());
    rule.pattern = QRegularExpression(QStringLiteral("\".*\""));
    rule.format = quotationFormat;
    rule.formatName = "String";
    highlightingRules.append(rule);

    functionFormat.setFont(_font_manager->normal_font());
    functionFormat.setForeground(_highlightColorMap->value("Function"));
    rule.pattern = QRegularExpression(QStringLiteral("\\b[A-Za-z0-9_]+(?=\\()"));
    rule.format = functionFormat;
    rule.formatName = "Function";
    highlightingRules.append(rule);

    commentStartExpression = QRegularExpression(QStringLiteral(" /\\*"));
    commentEndExpression = QRegularExpression(QStringLiteral("\\*/"));
}

void DCSyntaxHighlighter::highlightBlock(const QString &text)
{

    for (HighlightingRule &rule : highlightingRules) { //qAsConst(highlightingRules)
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            rule.format.setForeground(_highlightColorMap->value(rule.formatName));
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
    setCurrentBlockState(0);

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = text.indexOf(commentStartExpression);

    while (startIndex >= 0) {
        QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
        int endIndex = match.capturedStart();
        int commentLength = 0;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + match.capturedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
    }
}

void DCSyntaxHighlighter::onThemeChange(ElaThemeType::ThemeMode themeMode) {
    _themeMode = themeMode;
    if (themeMode == ElaThemeType::Light) {
        // keywordFormat.setForeground(QColor::fromString("#000080"));
        _highlightColorMap->insert("Keyword", QColor::fromString("#000080"));
        _highlightColorMap->insert("This", QColor::fromString("#000080"));
        // functionFormat.setForeground(QColor::fromString("#000000"));
        _highlightColorMap->insert("Function", QColor::fromString("#000000"));
        _highlightColorMap->insert("GlobalVar", QColor::fromString("#000000"));
        _highlightColorMap->insert("LocalVar", QColor::fromString("#000000"));
        _highlightColorMap->insert("Namespace", QColor::fromString("#008080"));
        _highlightColorMap->insert("OperatorOverride", QColor::fromString("#008080"));
        _highlightColorMap->insert("StringArgFormat", QColor::fromString("#000080"));
        // quotationFormat.setForeground(QColor::fromString("#00733b"));
        _highlightColorMap->insert("String", QColor::fromString("#00733b"));
        _highlightColorMap->insert("EscapeSequence", QColor::fromString("#008000"));
        _highlightColorMap->insert("Macro", QColor::fromString("#1f542e"));
        _highlightColorMap->insert("Param", QColor::fromString("#000000"));
        _highlightColorMap->insert("Number", QColor::fromString("#0073e6"));
        _highlightColorMap->insert("EnumConst", QColor::fromString("#660e7a"));
        _highlightColorMap->insert("Concept", QColor::fromString("#008080"));
        _highlightColorMap->insert("DoxygenCommand", QColor::fromString("#808080"));
        // singleLineCommentFormat.setForeground(QColor::fromString("#808080"));
        // multiLineCommentFormat.setForeground(QColor::fromString("#808080"));
        _highlightColorMap->insert("Comment", QColor::fromString("#808080"));
        // classFormat.setForeground(QColor::fromString("#008080"));
        _highlightColorMap->insert("Class", QColor::fromString("#008080"));
        _highlightColorMap->insert("StructVar", QColor::fromString("#660e7a"));
        _highlightColorMap->insert("ErrorChar", QColor::fromString("#ffcccc"));
        _highlightColorMap->insert("HeaderPath", QColor::fromString("#00733b"));
        _highlightColorMap->insert("Preprocessor", QColor::fromString("#808000"));
    } else {
        // keywordFormat.setForeground(QColor::fromString("#d55fde"));
        _highlightColorMap->insert("Keyword", QColor::fromString("#d55fde"));
        _highlightColorMap->insert("This", QColor::fromString("#d55fde"));
        // functionFormat.setForeground(QColor::fromString("#61afaf"));
        _highlightColorMap->insert("Function", QColor::fromString("#61afaf"));
        _highlightColorMap->insert("GlobalVar", QColor::fromString("#ef596f"));
        _highlightColorMap->insert("LocalVar", QColor::fromString("#bbbbbb"));
        _highlightColorMap->insert("Namespace", QColor::fromString("#e5c07b"));
        _highlightColorMap->insert("OperatorOverride", QColor::fromString("#008080"));
        _highlightColorMap->insert("StringArgFormat", QColor::fromString("#2bbac5"));
        // quotationFormat.setForeground(QColor::fromString("#89ca78"));
        _highlightColorMap->insert("String", QColor::fromString("#89ca78"));
        _highlightColorMap->insert("EscapeSequence", QColor::fromString("#008000"));
        _highlightColorMap->insert("Macro", QColor::fromString("#ef596f"));
        _highlightColorMap->insert("Param", QColor::fromString("#d19a66"));
        _highlightColorMap->insert("Number", QColor::fromString("#d19a66"));
        _highlightColorMap->insert("EnumConst", QColor::fromString("#d19a66"));
        _highlightColorMap->insert("Concept", QColor::fromString("#e5c07b"));
        _highlightColorMap->insert("DoxygenCommand", QColor::fromString("#d55fde"));
        // classFormat.setForeground(QColor::fromString("#e5co7b"));
        _highlightColorMap->insert("Class", QColor::fromString("#e5c07b"));
        // singleLineCommentFormat.setForeground(QColor::fromString("#5c6370"));
        // multiLineCommentFormat.setForeground(QColor::fromString("#5c6370"));
        _highlightColorMap->insert("Comment", QColor::fromString("#5c6370"));
        _highlightColorMap->insert("StructVar", QColor::fromString("#ef596f"));
        _highlightColorMap->insert("ErrorChar", QColor::fromString("#9b3636"));
        _highlightColorMap->insert("HeaderPath", QColor::fromString("#b9ca78"));
        _highlightColorMap->insert("Preprocessor", QColor::fromString("#d55fde"));
    }

}
