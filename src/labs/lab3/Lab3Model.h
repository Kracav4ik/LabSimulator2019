#pragma once

#include "common/LabModel.h"

#include <QList>
#include <QPoint>

class Lab3Model : public LabModel {
Q_OBJECT
private:
    int _dipoleRadius;
    int _distance;
    QList<QPoint> _measurements;
    QPoint _nextMeasurement;

public:
    Lab3Model();
    int distance() const;
    int dipoleRadius() const;
    float calculateMeasurement(const QPoint& p) const;

    const QList<QPoint>& measurements() const;
    const QPoint& nextMeasurement() const;

    void addNextMeasurement(const QPoint& nextMeasurement);
    void removeLastMeasurement();
    bool canAddNextMeasurement() const;
    void clear() override;

public slots:
    void setNextMeasurement(const QPoint& nextMeasurement);
};
