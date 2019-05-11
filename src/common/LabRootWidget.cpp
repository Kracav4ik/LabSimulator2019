#include "LabRootWidget.h"

#include "LabModel.h"

#include <QDebug>

LabRootWidget::LabRootWidget() {
    qDebug() << "+ create " << this;
}

LabRootWidget::~LabRootWidget() {
    qDebug() << "- delete " << this;
}

QUndoStack* LabRootWidget::undoStack() {
    return &_undoStack;
}

void LabRootWidget::undo() {
    _undoStack.undo();
}

void LabRootWidget::redo() {
    _undoStack.redo();
}

void LabRootWidget::reset() {
    _undoStack.clear();
    model().clear();
}
