#pragma once

#include <QWidget>

#include "ui_lab.h"

class LabRootWidget;

class LabContainer : public QWidget, private Ui::LabContainerWidget {
Q_OBJECT
public:
    explicit LabContainer(LabRootWidget* rootWidget);

private:
    LabRootWidget* rootWidget;
};


