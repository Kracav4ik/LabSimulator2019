#include "Lab3Plugin.h"

#include "Lab3RootWidget.h"

#include <QString>

QString Lab3Plugin::tabTitle() const {
    return "Lab 3";
}

std::unique_ptr<LabRootWidget> Lab3Plugin::createRoot() const {
    return std::make_unique<Lab3RootWidget>();
}
