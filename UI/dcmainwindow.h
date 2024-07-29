#ifndef DCMAINWINDOW_H
#define DCMAINWINDOW_H

#include "ElaWindow.h"


class DCEditor;
class DCFileController;
class DCToolDock;
class DCMenuBar;

class DCMainWindow : public ElaWindow
{
    Q_OBJECT

public:
    DCMainWindow(QWidget* parent = nullptr);
    ~DCMainWindow() = default;
    signals:
    void fileNewTriggerd(QString filename);


private:
    DCMenuBar* _menubar = nullptr;
    DCToolDock* _tooldock = nullptr;
    DCEditor *_editor = nullptr;

public:
    DCEditor * editor()  {
        return _editor;
    }

private:
    DCFileController* _file_controller = nullptr;

};
#endif // DCMAINWINDOW_H
