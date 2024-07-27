

#ifndef DCTOOLBAR_H
#define DCTOOLBAR_H
#include "dw_classdock.h"
#include "dw_projectdock.h"
#include "ElaMenuBar.h"
#include "ElaToolBar.h"
#include "ElaToolButton.h"

class DCMenuBar : public ElaMenuBar{
    Q_OBJECT
public:
    DCMenuBar(QWidget* parent = nullptr, ProjectDock *project_dock = nullptr, ClassDock *class_dock = nullptr);
    ~DCMenuBar() = default;

};



#endif //DCTOOLBAR_H
