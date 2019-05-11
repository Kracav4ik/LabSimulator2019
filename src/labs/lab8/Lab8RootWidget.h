#pragma once

#include "Lab8Model.h"
#include "common/LabRootWidget.h"
#include "ui_lab8.h"


class Lab8RootWidget : public LabRootWidget, private Ui::Lab8RootWidget {
Q_OBJECT
private:
    Lab8Model _model;

protected:
    LabModel& model() override;

public:
    Lab8RootWidget();

};
