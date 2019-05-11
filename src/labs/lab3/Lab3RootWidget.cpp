#include "Lab3RootWidget.h"

#include "commands/AddMeasurementCommand.h"

#include <QDebug>
#include <QAction>
#include <QMouseEvent>

Lab3RootWidget::Lab3RootWidget()
    : scene(this)
    , view(&scene, &model)
{
    setupUi(this);
    labInstallment->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    labInstallment->setMouseTracking(true);
    labInstallment->setScene(&scene);
    labInstallment->centerOn(0, 0);
    connect(&model, &Lab3Model::modelChanged, this, &Lab3RootWidget::modelChange);
    connect(&view, &Lab3View::mousePressed, this, &Lab3RootWidget::viewClicked);
    connect(&view, &Lab3View::mouseDragBegin, this, &Lab3RootWidget::dragMousePress);
    connect(&view, &Lab3View::mouseDragEnd, this, &Lab3RootWidget::dragMouseRelease);
    connect(&view, &Lab3View::wheelMoved, this, &Lab3RootWidget::zoom);
    connect(undoButton, &QPushButton::clicked, this, &Lab3RootWidget::undo);
    connect(redoButton, &QPushButton::clicked, this, &Lab3RootWidget::redo);
    connect(resetButton, &QPushButton::clicked, this, &Lab3RootWidget::reset);
    connect(&undoStack, &QUndoStack::canUndoChanged, undoButton, &QPushButton::setEnabled);
    connect(&undoStack, &QUndoStack::canRedoChanged, redoButton, &QPushButton::setEnabled);
    undoButton->setEnabled(undoStack.canUndo());
    redoButton->setEnabled(undoStack.canRedo());
    struct Column {
        int number;
        int width;
        QString text;
    };

    auto columns = {
            Column{0, 50, u8"x (см)"},
            Column{1, 50, u8"y (см)"},
            Column{2, 70, u8"Значение"}
    };

    tableWidget->setColumnCount(columns.size());
    for (const Column& column : columns) {
        tableWidget->setHorizontalHeaderItem(column.number, new QTableWidgetItem(column.text));
        tableWidget->setColumnWidth(column.number, column.width);
    }
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
    if (model.canAddNextMeasurement()) {
        undoStack.push(new AddMeasurementCommand(model));
    }
}

void Lab3RootWidget::modelChange() {
    const QList<QPoint>& measurements = model.measurements();
    tableWidget->setRowCount(measurements.size());
    for (int i = 0; i < measurements.size(); ++i) {
        QVector<float> measurement = {
            measurements[i].x() / 10.f,
            measurements[i].y() / 10.f,
            model.calculateMeasurement(measurements[i]),
        };
        for (int j = 0; j < measurement.size(); ++j) {
            QTableWidgetItem* el = new QTableWidgetItem(QString("%1").arg(measurement[j]));
            el->setTextAlignment(Qt::AlignCenter);
            tableWidget->setItem(i, j, el);
        }
    }
}

bool Lab3RootWidget::canUndo() {
    return undoStack.canUndo();
}

bool Lab3RootWidget::canRedo() {
    return undoStack.canRedo();
}

void Lab3RootWidget::undo() {
    undoStack.undo();
}

void Lab3RootWidget::redo() {
    undoStack.redo();
}

void Lab3RootWidget::reset() {
    undoStack.clear();
    model.clear();
}
