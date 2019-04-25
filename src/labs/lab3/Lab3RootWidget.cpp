#include "Lab3RootWidget.h"

#include <QDebug>
#include <QMouseEvent>

Lab3RootWidget::Lab3RootWidget()
    : scene(this)
    , view(&scene, &model)
{
    setupUi(this);
    labInstallment->setScene(&scene);
}
