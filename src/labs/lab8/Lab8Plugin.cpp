#include "Lab8Plugin.h"

#include "common/LabRootWidget.h"

#include <QString>

QString Lab8Plugin::tabTitle() const {
    return "Lab 8";
}

std::unique_ptr<LabRootWidget> Lab8Plugin::createRoot() const {
    return std::make_unique<LabRootWidget>();
}
