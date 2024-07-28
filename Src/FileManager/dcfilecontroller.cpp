//
// Created by MoonFeather on 24-7-28.
//

#include "dcfilecontroller.h"

#include "dcmenubar.h"

DCFileController::DCFileController
(QObject *parent, DCFileModel *model, DCMainWindow *view) :
QObject(parent), _model(model), _view(view)
{
    connect(qobject_cast<DCMenuBar*>(_view->menuBar()), &DCMenuBar::fileNewTriggerd, this, &DCFileController::newFile);
}

void DCFileController::newFile(QString filename) {
    qDebug() << filename;
}

void DCFileController::openFile(QString filename) {
    qDebug() << filename;
}