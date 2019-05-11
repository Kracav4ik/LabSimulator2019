#include "LabContainer.h"

#include "common/LabRootWidget.h"

LabContainer::LabContainer(LabRootWidget* rootWidget)
    : rootWidget(rootWidget)
{
    setupUi(this);

    rootContainer->addWidget(rootWidget);
    rootWidget->setTableWidget(tableWidget);

    connect(undoButton, &QPushButton::clicked, rootWidget, &LabRootWidget::undo);
    connect(redoButton, &QPushButton::clicked, rootWidget, &LabRootWidget::redo);
    connect(resetButton, &QPushButton::clicked, rootWidget, &LabRootWidget::reset);
    connect(copyTable, &QPushButton::clicked, rootWidget, &LabRootWidget::copyTable);
    connect(saveCSV, &QPushButton::clicked, rootWidget, &LabRootWidget::saveToCSV);
    connect(rootWidget->undoStack(), &QUndoStack::canUndoChanged, undoButton, &QPushButton::setEnabled);
    connect(rootWidget->undoStack(), &QUndoStack::canRedoChanged, redoButton, &QPushButton::setEnabled);
    undoButton->setEnabled(rootWidget->undoStack()->canUndo());
    redoButton->setEnabled(rootWidget->undoStack()->canRedo());
}
