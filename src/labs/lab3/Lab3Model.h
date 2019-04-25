#pragma once

#include <QList>
#include <QPoint>
#include <QObject>

class Lab3Model : public QObject {
Q_OBJECT
private:
    QList<QPoint> _measurements;
    QPoint _nextMeasurement;

public:
    const QList<QPoint>& measurements() const;
    QPoint nextMeasurement() const;

public slots:
    void mouseMoved(const QPoint& p);
    void mousePressed();

signals:
    void modelChanged();
};
