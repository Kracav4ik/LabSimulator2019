#include "Lab3RootWidget.h"

Lab3RootWidget::Lab3RootWidget()
    : scene(this)
    , view(&scene, &model)
{
    setupUi(this);
    labInstallment->setScene(&scene);
}
