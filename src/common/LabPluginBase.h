#pragma once

#include <QtPlugin>
#include <memory>

class QString;
class LabRootWidget;

class LabPluginBase {
public:
    virtual QString tabTitle() const = 0;

    virtual std::unique_ptr<LabRootWidget> createRoot() const = 0;

    virtual ~LabPluginBase() = default;
};

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!                                                                                                         !!!
// !!!   we MUST INCREMENT iid version after ANY signature change of ANY class/function used in the lab dlls   !!!
// !!!                                                                                                         !!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#define LabPluginBase_iid "LabPluginBase/v0.1"
Q_DECLARE_INTERFACE(LabPluginBase, LabPluginBase_iid)
