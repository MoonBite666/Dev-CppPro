#ifndef DCFONTMANAGER_H
#define DCFONTMANAGER_H
#include <QFont>
#include <QObject>

class QFont;
class DCFontManager : public QObject{
    Q_OBJECT
public:
    DCFontManager(QWidget* parent = nullptr);
    ~DCFontManager() override = default;
    QFont normal_font() const {
        return _normalFont;
    }

    QFont bold_font() const {
        return _boldFont;
    }

    QFont italic_font() const {
        return _italicFont;
    }

    QFont bold_italic_font() const {
        return _boldItalicFont;
    }
private:
    QFont _normalFont;
    QFont _boldFont;
    QFont _italicFont;
    QFont _boldItalicFont;

};



#endif //DCFONTMANAGER_H
