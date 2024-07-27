
#include "dcmenubar.h"
#include "ElaMenu.h"
#include "ElaToolButton.h"
#include <QAction>



DCMenuBar::DCMenuBar(QWidget* parent, const QList <ElaDockWidget*>& dockList): ElaMenuBar(parent)
{
    auto *file = new ElaMenu(tr("File(&F)"),this);
        auto *new_ = file->addMenu(tr("New"));
            auto *newfile = new_->addElaIconAction(ElaIconType::FileCode, tr("File"));
            auto *newproject = new_->addElaIconAction(ElaIconType::Book, tr("Project"));
        auto *open = file->addMenu(tr("Open"));
            auto *openfile = open->addElaIconAction(ElaIconType::FileCode, tr("File"), QKeySequence::Open);
            auto *openproject = open->addElaIconAction(ElaIconType::BookBookmark, tr("Project"));
        auto *save = file->addElaIconAction(ElaIconType::FileCheck, tr("Save"), QKeySequence::Save);
        auto *saveas = file->addElaIconAction(ElaIconType::FileCheck, tr("Save As..."), QKeySequence::SaveAs);
        auto *close = file->addElaIconAction(ElaIconType::X, tr("Close"), QKeySequence::Close);
        auto *closeall = file->addElaIconAction(ElaIconType::X, tr("Close All"));
        auto *prefer = file->addElaIconAction(ElaIconType::Gear, tr("Preferences..."), QKeySequence::Preferences);
        auto *quit = file->addElaIconAction(ElaIconType::PowerOff, tr("Quit"), QKeySequence::Quit);

    // file->setContentsMargins(10,2,2,2);
        file->addMenu(new_);
        file->addMenu(open);
        file->addSeparator();
        file->addActions({save,saveas,close,closeall});
        file->addSeparator();
        file->addAction(prefer);
        file->addSeparator();
        file->addAction(quit);

    auto *edit = new ElaMenu(tr("Edit(&E)"),this);
        auto *undo = edit->addElaIconAction(ElaIconType::ArrowRotateLeft, tr("Undo"), QKeySequence::Undo);
        auto *redo = edit->addElaIconAction(ElaIconType::ArrowRotateRight, tr("Redo"), QKeySequence::Redo);
        auto *cut = edit->addElaIconAction(ElaIconType::Scissors, tr("Cut"), QKeySequence::Cut);
        auto *copy = edit->addElaIconAction(ElaIconType::Copy, tr("Copy"), QKeySequence::Copy);
        auto *paste = edit->addElaIconAction(ElaIconType::Clipboard, tr("Paste"), QKeySequence::Paste);
        auto *selectall = edit->addElaIconAction(ElaIconType::Tick, tr("Select All"), QKeySequence::SelectAll);

        edit->addActions({undo,redo});
        edit->addSeparator();
        edit->addActions({cut,copy,paste,selectall});
        edit->addSeparator();

    auto *view = new ElaMenu(tr("View(&V)"), this);

    for(const ElaDockWidget* dock : dockList){
        auto *dockview = dock->toggleViewAction();
        dockview->setCheckable(true);
        view->addAction(dockview);
    }

    addMenu(file);
    addMenu(edit);
    addMenu(view);

}
