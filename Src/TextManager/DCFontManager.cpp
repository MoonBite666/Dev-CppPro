//
// Created by MoonFeather on 24-8-1.
//

#include "DCFontManager.h"

#include <QFontDatabase>

DCFontManager::DCFontManager(QWidget *parent) {
    int normalFontId = QFontDatabase::addApplicationFont(":/Fonts/MesloLGS NF Regular.ttf");
    int boldFontId = QFontDatabase::addApplicationFont(":/Fonts/MesloLGS NF Bold.ttf");
    int italicFontId = QFontDatabase::addApplicationFont(":/Fonts/MesloLGS NF Italic.ttf");
    int boldItalicFontId = QFontDatabase::addApplicationFont(":/Fonts/MesloLGS NF Bold Italic.ttf");

    QString normalFontFamily = QFontDatabase::applicationFontFamilies(normalFontId).at(0);
    QString boldFontFamily = QFontDatabase::applicationFontFamilies(boldFontId).at(0);
    QString italicFontFamily = QFontDatabase::applicationFontFamilies(italicFontId).at(0);
    QString boldItalicFontFamily = QFontDatabase::applicationFontFamilies(boldItalicFontId).at(0);

    _normalFont = QFont(normalFontFamily);
    _normalFont.setPointSize(16);
    _boldFont = QFont(boldFontFamily);
    _boldFont.setPointSize(16);
    _italicFont = QFont(italicFontFamily);
    _italicFont.setPointSize(16);
    _boldItalicFont = QFont(boldItalicFontFamily);
    _boldItalicFont.setPointSize(16);

}
