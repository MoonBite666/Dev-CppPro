#include "DCFileEdit.h"
#include <QFile>
#include <QHBoxLayout>

#include "ElaTextEdit.h"


DCFileEdit::DCFileEdit(QWidget *parent, QFile *file)
    : QWidget(parent),
      _file(file) {
    _filedata = _file->readAll();
    _text_edit = new ElaTextEdit(QString::fromUtf8(_filedata), this);

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(_text_edit);
    setLayout(layout);

}
