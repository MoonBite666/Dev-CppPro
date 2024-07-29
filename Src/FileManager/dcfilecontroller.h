//
// Created by MoonFeather on 24-7-28.
//

#ifndef DCFILECONTROLLER_H
#define DCFILECONTROLLER_H
#include <QObject>

#include "dcmainwindow.h"

class QFile;
class DCFileModel;
class DCMainWindow;
class DCFileController : public QObject
{
    Q_OBJECT
public:
    explicit DCFileController(QObject *parent = nullptr, DCFileModel *model = nullptr, DCMainWindow *view = nullptr);
    ~DCFileController() override = default;
    signals:
    void fileNewTriggerd(QString filename);
    void fileNewOpened(QFile *file);

private:
    DCFileModel *_model;
    DCMainWindow *_view;
    int _tempCount = 0;
private slots:
    void openFile(QString filename);
    void newFile(QString filename);
};

#endif //DCFILECONTROLLER_H
