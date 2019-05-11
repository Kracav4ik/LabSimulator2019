#pragma once

#include "Lab3Model.h"
#include "Lab3View.h"
#include "common/LabRootWidget.h"
#include "ui_lab3.h"

class Lab3RootWidget : public LabRootWidget, private Ui::Lab3RootWidget {
Q_OBJECT
private:
    QGraphicsScene _scene;
    Lab3Model _model;
    Lab3View _view;

protected:
    LabModel& model() override;

public:
    Lab3RootWidget();

public slots:
    void saveToCSV();
    void modelChange();
    void viewClicked();
    void dragMousePress();
    void dragMouseRelease();
    void zoom(double sc);
};


