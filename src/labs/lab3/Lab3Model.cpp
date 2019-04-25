#include "Lab3Model.h"

const QList<QPoint>& Lab3Model::measurements() const {
    return _measurements;
}

QPoint Lab3Model::nextMeasurement() const {
    return _nextMeasurement;
}

void Lab3Model::mouseMoved(const QPoint& p) {
    if (_nextMeasurement != p) {
        _nextMeasurement = p;
        emit modelChanged();
    }
}

void Lab3Model::mousePressed() {
    if (!_measurements.contains(_nextMeasurement)) { // TODO: forbid setting measurements near center.
        _measurements.append(_nextMeasurement);
        emit modelChanged();
    }
}
