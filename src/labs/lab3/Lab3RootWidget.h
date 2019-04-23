#pragma once

#include "common/LabRootWidget.h"
#include "ui_lab3.h"

class Lab3RootWidget : public LabRootWidget, private Ui::Lab3RootWidget {
Q_OBJECT
private:
    QGraphicsScene scene;

public:
    Lab3RootWidget();
};


