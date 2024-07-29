#ifndef DCFILEEDIT_H
#define DCFILEEDIT_H
#include <QWidget>

class ElaTextEdit;
class QFile;

class DCFileEdit : public QWidget{
public:
    explicit DCFileEdit(QWidget* parent = nullptr, QFile* file = nullptr);



    ~DCFileEdit() override = default;

private:
    QFile* _file;
    QByteArray _filedata;
    ElaTextEdit* _text_edit;

};



#endif //DCFILEEDIT_H
