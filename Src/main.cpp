#include "dcmainwindow.h"
#include "initwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include "ElaApplication.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ElaApplication::getInstance()->init();
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "DevCppPro_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    DCMainWindow w;
    w.show();
    // InitWindow i;
    // i.show();
    return a.exec();
}
