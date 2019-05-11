#pragma once

#include <QList>
#include <QPoint>
#include <QObject>

class Lab3Model : public QObject {
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

    const QList<QPoint>& measurements() const;
    const QPoint& nextMeasurement() const;

    void addNextMeasurement(const QPoint& nextMeasurement);
    void removeLastMeasurement();
    bool canAddNextMeasurement() const;
    void clear();

public slots:
    void setNextMeasurement(const QPoint& nextMeasurement);

signals:
    void modelChanged();
};
