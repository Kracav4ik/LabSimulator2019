#include "Lab3Model.h"
#include <QRect>
#include <QMap>

const QList<QPoint>& Lab3Model::measurements() const {
    return _measurements;
}

const QPoint& Lab3Model::nextMeasurement() const {
    return _nextMeasurement;
}

void Lab3Model::setNextMeasurement(const QPoint& nextMeasurement) {
    if (_nextMeasurement != nextMeasurement) {
        _nextMeasurement = nextMeasurement;
        emit modelChanged();
    }
}

bool Lab3Model::canAddNextMeasurement() const {
    return !_measurements.contains(_nextMeasurement);
}

void Lab3Model::addNextMeasurement(const QPoint& nextMeasurement) {
    if (canAddNextMeasurement()) { // TODO: forbid setting measurements near center.
        _measurements.append(nextMeasurement);
        emit modelChanged();
    }
}

void Lab3Model::removeLastMeasurement() {
    Q_ASSERT(!_measurements.empty());
    _measurements.removeLast();
    emit modelChanged();
}

void Lab3Model::clear() {
    _measurements.clear();
    emit modelChanged();
}

Lab3Model::Lab3Model()
    : _dipoleRadius(15)
    , _distance(210)
{}

int Lab3Model::distance() const {
    return _distance;
}

int Lab3Model::dipoleRadius() const {
    return _dipoleRadius;
}

bool operator<(const QPoint& p1, const QPoint& p2) {
    if (p1.x() == p2.x()) {
        return p1.y() < p2.y();
    }
    return p1.x() < p2.x();
}

float Lab3Model::calculateMeasurement(const QPoint& p) const {
    static QMap<QPoint, float> hashMeasurements;
    if (!hashMeasurements.contains(p)) {
        int result = qRound(100 * 20.f * std::rand() / RAND_MAX);
        hashMeasurements[p] = result / 100.f;
    }
    return hashMeasurements[p];
}
