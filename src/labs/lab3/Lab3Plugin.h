#pragma once

#include "common/LabPluginBase.h"

class Lab3Plugin : public QObject, public LabPluginBase {
Q_OBJECT
Q_PLUGIN_METADATA(IID LabPluginBase_iid)
Q_INTERFACES(LabPluginBase)

public:
    QString tabTitle() const override;
    std::unique_ptr<LabRootWidget> createRoot() const override;
};
