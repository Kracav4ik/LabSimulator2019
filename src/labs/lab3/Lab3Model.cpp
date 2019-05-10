#include "Lab3Model.h"

const QList<QPoint>& Lab3Model::measurements() const {
    return _measurements;
}

QPoint Lab3Model::nextMeasurement() const {
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
