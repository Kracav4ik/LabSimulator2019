#include "Lab3View.h"

#include "Lab3Model.h"

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

void Lab3View::setModel(Lab3Model *model) {
    _model = model;
    _scene->addItem(&grid);
    connect(_model, &Lab3Model::modelChanged, this, &Lab3View::modelChange);
    connect(&grid, &Grid::mouseMove, _model, &Lab3Model::mouseMoved);
    connect(&grid, &Grid::mousePress, _model, &Lab3Model::mousePressed);
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
    int dipoleRadius = pxCount * 30;
    QRect roundRect(-dipoleRadius / 2, -dipoleRadius / 2, dipoleRadius, dipoleRadius);
    QColor roundColor(0, 255, 255);
    QColor measurementsColor = QColor(255, 255, 0);
    QColor nextMeasurementColor = QColor(0, 255, 0);
    _scene->addEllipse(roundRect, roundColor, roundColor);

    QPointF measurementRadius(pxCount * 2, pxCount * 2);
    QRectF rectRad(-measurementRadius / 2, measurementRadius / 2);
    for (int i = 0; i < _model->measurements().size(); ++i) {
        QPointF measurement = _model->measurements()[i];
        _scene->addEllipse(rectRad.translated(measurement), measurementsColor, measurementsColor);
        QGraphicsTextItem* text = _scene->addText(QString("%1").arg(i + 1));
        text->setPos(measurement - text->boundingRect().center());
    }
    _scene->addEllipse(rectRad.translated(_model->nextMeasurement()), nextMeasurementColor, nextMeasurementColor);
}
