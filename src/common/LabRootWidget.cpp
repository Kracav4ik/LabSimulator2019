#include "LabRootWidget.h"

#include <QDebug>

LabRootWidget::LabRootWidget() {
    qDebug() << "+ create " << this;
}

LabRootWidget::~LabRootWidget() {
    qDebug() << "- delete " << this;
}
