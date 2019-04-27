#pragma once

#include "Lab3Model.h"
#include "Lab3View.h"
#include "common/LabRootWidget.h"
#include "ui_lab3.h"

class Lab3RootWidget : public LabRootWidget, private Ui::Lab3RootWidget {
Q_OBJECT
private:
    QGraphicsScene scene;
    Lab3Model model;
    Lab3View view;

public:
    Lab3RootWidget();

public slots:
    void dragMousePress();
    void dragMouseRelease();
    void zoom(double sc);
};


