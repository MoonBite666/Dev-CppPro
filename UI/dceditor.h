//
// Created by MoonFeather on 24-7-27.
//

#ifndef DCEDITOR_H
#define DCEDITOR_H
#include "ElaScrollPage.h"

class ElaTabWidget;
class DCEditor : public ElaScrollPage{
    Q_OBJECT
public:
    DCEditor(QWidget* parent = nullptr);
    ~DCEditor() = default;
private:
    ElaTabWidget *_tabWidget;
};



#endif //DCEDITOR_H
