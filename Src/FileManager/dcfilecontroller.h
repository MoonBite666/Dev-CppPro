//
// Created by MoonFeather on 24-7-28.
//

#ifndef DCFILECONTROLLER_H
#define DCFILECONTROLLER_H
#include <QObject>

#include "dcmainwindow.h"

class DCFileModel;
class DCMainWindow;
class DCFileController : public QObject
{
    Q_OBJECT
public:
    explicit DCFileController(QObject *parent = nullptr, DCFileModel *model = nullptr, DCMainWindow *view = nullptr);
    ~DCFileController() override = default;

private:
    DCFileModel *_model;
    DCMainWindow *_view;
private slots:
    void openFile(QString filename);
    void newFile(QString filename);
};

#endif //DCFILECONTROLLER_H
