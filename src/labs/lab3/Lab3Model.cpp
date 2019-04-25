#include "Lab3Model.h"

const QList<QPointF>& Lab3Model::measurements() const {
    return _measurements;
}

QPointF Lab3Model::nextMeasurement() const {
    return _nextMeasurement;
}
