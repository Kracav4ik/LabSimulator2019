#pragma once

#include "Ldb3Model.h"
#include "Ldb3View.h"
#include "common/LabRootWidget.h"
#include "ui_lab3.h"

class Lab3RootWidget : public LabRootWidget, private Ui::Lab3RootWidget {
Q_OBJECT
private:
    QGraphicsScene scene;
    Ldb3Model model;
    Ldb3View view;

public:
    Lab3RootWidget();
};


