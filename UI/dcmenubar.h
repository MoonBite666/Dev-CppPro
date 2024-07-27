

#ifndef DCTOOLBAR_H
#define DCTOOLBAR_H
#include "ElaMenuBar.h"
#include "ElaToolBar.h"
#include "ElaToolButton.h"

class DCMenuBar : public ElaMenuBar{
    Q_OBJECT
public:
    DCMenuBar(QWidget* parent = nullptr);
    ~DCMenuBar() = default;

};



#endif //DCTOOLBAR_H
