#include "Ldb3Model.h"

const QList<QPointF>& Ldb3Model::measurements() const {
    return _measurements;
}

QPointF Ldb3Model::nextMeasurement() const {
    return _nextMeasurement;
}
