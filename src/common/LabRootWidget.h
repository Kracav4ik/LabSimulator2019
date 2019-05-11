#pragma once

#include "symbols_export.h"

#include <QWidget>
#include <QUndoStack>

class LabModel;

class SYMBOLS_EXPORT LabRootWidget : public QWidget {
Q_OBJECT
protected:
    virtual LabModel& model() = 0;

    QUndoStack _undoStack;

public:
    LabRootWidget();
    ~LabRootWidget();

    QUndoStack* undoStack();

public slots:
    void undo();
    void redo();
    void reset();

};


