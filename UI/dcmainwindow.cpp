#include "dcmainwindow.h"
#include "ElaPushButton.h"


DCMainWindow::DCMainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    resize(1200,800);
    setWindowTitle("DevCppPro");
    auto *button = new ElaPushButton(this);
    button->setText("123");
    button->resize(50,50);
    button->move(100,100);
}

DCMainWindow::~DCMainWindow()
{
}
