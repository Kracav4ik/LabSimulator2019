#include "Lab6RootWidget.h"

Lab6RootWidget::Lab6RootWidget()
    : LabRootWidget({ {100, u8"Колонка"}, {150, u8"Еще колонка"} })
{
    setupUi(this);
}

LabModel& Lab6RootWidget::model() {
    return _model;
}
