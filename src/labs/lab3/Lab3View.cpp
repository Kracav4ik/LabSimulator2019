#include "Lab3View.h"

#include "Lab3Model.h"

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

void Lab3View::setModel(Lab3Model *model) {
    _model = model;
    _scene->addItem(&grid);
    connect(_model, &LabModel::modelChanged, this, &Lab3View::modelChange);
    connect(&grid, &Grid::mouseMove, _model, &Lab3Model::setNextMeasurement);
    connect(&grid, &Grid::mousePress, this, &Lab3View::mousePressed);
    connect(&grid, &Grid::mouseDragStart, this, &Lab3View::mouseDragBegin);
    connect(&grid, &Grid::mouseDragStop, this, &Lab3View::mouseDragEnd);
    connect(&grid, &Grid::wheelMove, this, &Lab3View::wheelMoved);
    modelChange();
}

Lab3View::Lab3View(QGraphicsScene *scene, Lab3Model* model) : _scene(scene), _model(nullptr) {
    setModel(model);
}

void Lab3View::modelChange() {
    _scene->removeItem(&grid);
    _scene->clear();
    _scene->addItem(&grid);

    grid.grabMouse();
    int pxCount = grid.getPxPerMm();

    int pixelRadius =_model->dipoleRadius() * pxCount;
    QPointF dipoleRadius(pixelRadius, pixelRadius);
    QRectF dipoleBounds(-dipoleRadius, dipoleRadius);
    QColor dipoleColor(0, 255, 255);
    _scene->addEllipse(dipoleBounds.translated(_model->distance() * pxCount, 0), dipoleColor, dipoleColor);
    _scene->addEllipse(dipoleBounds, dipoleColor, dipoleColor);

    QColor measurementsColor = QColor(255, 255, 0);
    QPointF measurementRadius(pxCount, pxCount);
    QRectF measurementBounds(-measurementRadius, measurementRadius);
    for (int i = 0; i < _model->measurements().size(); ++i) {
        QPointF measurement = _model->measurements()[i] * pxCount;
        _scene->addEllipse(measurementBounds.translated(measurement), measurementsColor, measurementsColor);
        QGraphicsTextItem* text = _scene->addText(QString("%1").arg(i + 1));
        text->setPos(measurement - text->boundingRect().center());
    }

    QColor nextMeasurementColor = QColor(0, 255, 0);
    _scene->addEllipse(measurementBounds.translated(_model->nextMeasurement() * pxCount), nextMeasurementColor, nextMeasurementColor);
}
