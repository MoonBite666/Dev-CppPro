
#include "dcmenubar.h"
#include "ElaMenu.h"

DCMenuBar::DCMenuBar(QWidget* parent): ElaMenuBar(parent)
{
    auto *file = new ElaMenu(tr("File"),this);
    auto *newfile = new ElaMenu(tr("New File"),file);
    auto *newproject = new ElaMenu(tr("New Project"),file);
    auto *openfile = new ElaMenu(tr("Open File"),file);
    auto *openproject = new ElaMenu(tr("Open Project"),file);
    auto *save = new ElaMenu(tr("Save"),file);
    auto *saveas = new ElaMenu(tr("Save As"),file);
    auto *exit = new ElaMenu(tr("Exit"),file);
    file->addMenu(newfile);
    file->addMenu(newproject);
    file->addMenu(openfile);
    file->addMenu(openproject);
    file->addMenu(save);
    file->addMenu(saveas);
    file->addMenu(exit);
    this->addMenu(file);

    auto *edit = new ElaMenu(tr("Edit"),this);
    auto *undo = new ElaMenu(tr("Undo"),edit);
    auto *redo = new ElaMenu(tr("Redo"),edit);
    auto *cut = new ElaMenu(tr("Cut"),edit);
    auto *copy = new ElaMenu(tr("Copy"),edit);
    auto *paste = new ElaMenu(tr("Paste"),edit);
    edit->addMenu(undo);
    edit->addMenu(redo);
    edit->addMenu(cut);
    edit->addMenu(copy);
    edit->addMenu(paste);
    this->addMenu(edit);

    auto *view = new ElaMenu(tr("View"),this);
    auto *zoomin = new ElaMenu(tr("Zoom In"),view);
    auto *zoomout = new ElaMenu(tr("Zoom Out"),view);
    auto *fullscreen = new ElaMenu(tr("Full Screen"),view);
    view->addMenu(zoomin);
    view->addMenu(zoomout);
    view->addMenu(fullscreen);
    this->addMenu(view);

    auto *help = new ElaMenu(tr("Help"),this);
    auto *about = new ElaMenu(tr("About"),help);
    help->addMenu(about);
    this->addMenu(help);
}