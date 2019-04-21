#include "Lab3Plugin.h"

#include "common/LabRootWidget.h"

#include <QString>

QString Lab3Plugin::tabTitle() const {
    return "Lab 3";
}

std::unique_ptr<LabRootWidget> Lab3Plugin::createRoot() const {
    return std::make_unique<LabRootWidget>();
}
