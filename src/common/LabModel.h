#pragma once

#include "symbols_export.h"

#include <QObject>

class SYMBOLS_EXPORT LabModel : public QObject {
Q_OBJECT
public:
    virtual void clear() = 0;

signals:
    void modelChanged();
};


