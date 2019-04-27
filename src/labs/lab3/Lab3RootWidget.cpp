#include "Lab3RootWidget.h"

#include <QDebug>
#include <QMouseEvent>

Lab3RootWidget::Lab3RootWidget()
    : scene(this)
    , view(&scene, &model)
{
    setupUi(this);
    labInstallment->setMouseTracking(true);
    labInstallment->setScene(&scene);
    connect(&view, &Lab3View::mouseDragBegin, this, &Lab3RootWidget::dragMousePress);
    connect(&view, &Lab3View::mouseDragEnd, this, &Lab3RootWidget::dragMouseRelease);
}

void Lab3RootWidget::dragMousePress() {
    labInstallment->setDragMode(QGraphicsView::ScrollHandDrag);
}

void Lab3RootWidget::dragMouseRelease() {
    labInstallment->setDragMode(QGraphicsView::NoDrag);
}
