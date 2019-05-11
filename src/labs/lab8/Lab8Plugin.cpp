#include "Lab8Plugin.h"

#include "Lab8RootWidget.h"

#include <QString>

QString Lab8Plugin::tabTitle() const {
    return "Lab 8";
}

std::unique_ptr<LabRootWidget> Lab8Plugin::createRoot() const {
    return std::make_unique<Lab8RootWidget>();
}
