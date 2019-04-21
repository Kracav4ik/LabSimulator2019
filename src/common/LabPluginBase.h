#pragma once

#include <QtPlugin>

struct QString;

class LabPluginBase {
public:
    virtual QString tabTitle() const = 0;

    virtual ~LabPluginBase() = default;
};

#define LabPluginBase_iid "LabPluginBase"
Q_DECLARE_INTERFACE(LabPluginBase, LabPluginBase_iid)
