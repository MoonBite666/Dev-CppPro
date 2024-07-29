//
// Created by MoonFeather on 24-7-27.
//

#ifndef DCEDITOR_H
#define DCEDITOR_H
#include "ElaScrollPage.h"

class QFile;
class ElaTabWidget;
class DCEditor : public ElaScrollPage{
    Q_OBJECT
public:
    DCEditor(QWidget* parent = nullptr);
    ~DCEditor() = default;
public slots:
    void addTab(QFile* tabFile);


private:
    ElaTabWidget *_tabWidget;
};



#endif //DCEDITOR_H
