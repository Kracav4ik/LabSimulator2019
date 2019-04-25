#pragma once

#include <QList>
#include <QPointF>
#include <QObject>

class Lab3Model : public QObject {
Q_OBJECT
private:
    // TODO: remove hardcode
    QList<QPointF> _measurements = {{150, 150}, {-150, 150}, {150, -150}, {-150, -150}};
    QPointF _nextMeasurement = {150, 0};

public:
    const QList<QPointF>& measurements() const;
    QPointF nextMeasurement() const;

signals:
    void modelChanged();
};
