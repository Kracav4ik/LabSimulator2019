#include "Lab8RootWidget.h"

Lab8RootWidget::Lab8RootWidget()
    : LabRootWidget({ {100, u8"Колонка"}, {150, u8"Еще колонка"} })
{
    setupUi(this);
}

LabModel& Lab8RootWidget::model() {
    return _model;
}
