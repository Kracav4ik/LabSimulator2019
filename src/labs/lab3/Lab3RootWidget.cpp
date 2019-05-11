#include "Lab3RootWidget.h"

#include "commands/AddMeasurementCommand.h"

#include <QMouseEvent>
#include <QTableWidget>

Lab3RootWidget::Lab3RootWidget()
    : LabRootWidget({ {50, u8"x (см)"}, {50, u8"y (см)"}, {70, u8"Значение"} })
    , _scene(this)
    , _view(&_scene, &_model)
{
    setupUi(this);
    labInstallment->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    labInstallment->setMouseTracking(true);
    labInstallment->setScene(&_scene);
    labInstallment->centerOn(0, 0);
    connect(&_model, &LabModel::modelChanged, this, &Lab3RootWidget::modelChange);
    connect(&_view, &Lab3View::mousePressed, this, &Lab3RootWidget::viewClicked);
    connect(&_view, &Lab3View::mouseDragBegin, this, &Lab3RootWidget::dragMousePress);
    connect(&_view, &Lab3View::mouseDragEnd, this, &Lab3RootWidget::dragMouseRelease);
    connect(&_view, &Lab3View::wheelMoved, this, &Lab3RootWidget::zoom);
}

LabModel& Lab3RootWidget::model() {
    return _model;
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

void Lab3RootWidget::viewClicked() {
    if (_model.canAddNextMeasurement()) {
        _undoStack.push(new AddMeasurementCommand(_model));
    }
}

void Lab3RootWidget::modelChange() {
    const QList<QPoint>& measurements = _model.measurements();
    tableWidget->setRowCount(measurements.size());
    for (int i = 0; i < measurements.size(); ++i) {
        QVector<float> measurement = {
            measurements[i].x() / 10.f,
            measurements[i].y() / 10.f,
            _model.calculateMeasurement(measurements[i]),
        };
        for (int j = 0; j < measurement.size(); ++j) {
            QTableWidgetItem* el = new QTableWidgetItem(QString("%1").arg(measurement[j]));
            el->setTextAlignment(Qt::AlignCenter);
            tableWidget->setItem(i, j, el);
        }
    }
}
