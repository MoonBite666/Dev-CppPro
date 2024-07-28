

#ifndef DCTOOLBAR_H
#define DCTOOLBAR_H
#include "dw_classdock.h"
#include "dw_projectdock.h"
#include "ElaMenuBar.h"

#include <QList>


class DCMenuBar : public ElaMenuBar{
    Q_OBJECT
public:
    explicit DCMenuBar(QWidget* parent = nullptr, const QList <ElaDockWidget*>& dockList = QList<ElaDockWidget*>());
    ~DCMenuBar() override = default;
    signals:
    void fileNewTriggerd(QString filename);
private:

};



#endif //DCTOOLBAR_H
