#include "Lab3RootWidget.h"

#include <QDebug>
#include <QMouseEvent>

Lab3RootWidget::Lab3RootWidget()
    : scene(this)
    , view(&scene, &model)
{
    setupUi(this);
    labInstallment->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    labInstallment->setMouseTracking(true);
    labInstallment->setScene(&scene);
    connect(&view, &Lab3View::mouseDragBegin, this, &Lab3RootWidget::dragMousePress);
    connect(&view, &Lab3View::mouseDragEnd, this, &Lab3RootWidget::dragMouseRelease);
    connect(&view, &Lab3View::wheelMoved, this, &Lab3RootWidget::zoom);
}

void Lab3RootWidget::dragMousePress() {
    labInstallment->setDragMode(QGraphicsView::ScrollHandDrag);
}

void Lab3RootWidget::dragMouseRelease() {
    labInstallment->setDragMode(QGraphicsView::NoDrag);
}

void Lab3RootWidget::zoom(double sc) {
    auto currentTransform = labInstallment->transform();
    currentTransform.scale(sc, sc);
    double scale = currentTransform.map(QPointF(1, 0)).x();
    if (0.25 < scale && scale < 4) {
        labInstallment->setTransform(currentTransform);
    }
}
