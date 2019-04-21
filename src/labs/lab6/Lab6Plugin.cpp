#include "Lab6Plugin.h"

#include "common/LabRootWidget.h"

#include <QString>

QString Lab6Plugin::tabTitle() const {
    return "Lab 6";
}

std::unique_ptr<LabRootWidget> Lab6Plugin::createRoot() const {
    return std::make_unique<LabRootWidget>();
}
