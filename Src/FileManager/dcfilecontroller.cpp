//
// Created by MoonFeather on 24-7-28.
//

#include "dcfilecontroller.h"
#include "dcfilemodel.h"

#include "dcmenubar.h"
#include "dceditor.h"

DCFileController::DCFileController
(QObject *parent, DCFileModel *model, DCMainWindow *view) :
QObject(parent), _model(model), _view(view)
{
    connect(qobject_cast<DCMenuBar*>(_view->menuBar()), &DCMenuBar::fileNewTriggerd, this, &DCFileController::newFile);
    connect(this, &DCFileController::fileNewOpened, _view->editor(), &DCEditor::addTab);
}

void DCFileController::newFile(QString filename) {
    qDebug() << filename;
    try {
        emit(fileNewOpened(_model->newFile(filename)));
    }catch (std::exception &e) {
        qDebug() << e.what();
    }
}

void DCFileController::openFile(QString filename) {
    qDebug() << filename;
}