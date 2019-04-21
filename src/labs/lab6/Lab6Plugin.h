#pragma once

#include "common/LabPluginBase.h"

class Lab6Plugin : public QObject, public LabPluginBase {
Q_OBJECT
Q_PLUGIN_METADATA(IID LabPluginBase_iid)
Q_INTERFACES(LabPluginBase)

public:
    QString tabTitle() const override;
};
