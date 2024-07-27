#include "dcstatus.h"

#include <QLabel>
#include "ElaText.h"

DCStatus::DCStatus(QWidget* parent)
    : ElaStatusBar(parent)
{
    auto *statusText = new ElaText(tr("Ready!"), this);
    statusText->setTextPixelSize(14);
    addWidget(statusText);
}
