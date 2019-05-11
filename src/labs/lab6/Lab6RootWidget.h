#pragma once

#include "Lab6Model.h"
#include "common/LabRootWidget.h"
#include "ui_lab6.h"

class Lab6RootWidget : public LabRootWidget, private Ui::Lab6RootWidget {
Q_OBJECT
private:
    Lab6Model _model;

protected:
    LabModel& model() override;

public:
    Lab6RootWidget();
};
