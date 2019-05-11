#pragma once

#include "Lab3Model.h"
#include "Lab3View.h"
#include "common/LabRootWidget.h"
#include "ui_lab3.h"
#include <QUndoStack>

class Lab3RootWidget : public LabRootWidget, private Ui::Lab3RootWidget {
Q_OBJECT
private:
    QGraphicsScene scene;
    Lab3Model model;
    Lab3View view;
    QUndoStack undoStack;

public:
    bool canUndo();
    bool canRedo();
    Lab3RootWidget();

public slots:
    void modelChange();
    void viewClicked();
    void undo();
    void redo();
    void dragMousePress();
    void dragMouseRelease();
    void zoom(double sc);
    void reset();
};


