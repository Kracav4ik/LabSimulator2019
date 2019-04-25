#include "Ldb3View.h"

#include "Ldb3Model.h"

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

void Ldb3View::setModel(Ldb3Model *model) {
    _model = model;
    connect(_model, &Ldb3Model::modelChanged, this, &Ldb3View::modelChange);
    modelChange();
}

Ldb3View::Ldb3View(QGraphicsScene *scene, Ldb3Model* model) : _scene(scene), _model(nullptr) {
    setModel(model);
}

void Ldb3View::modelChange() {
    _scene->clear();
    int pxCount = 6;
    int gridSize = 50;
    int dipoleRadius = pxCount * 30;
    QPen gridPen({255, 196, 255});
    QRect roundRect(-dipoleRadius / 2, -dipoleRadius / 2, dipoleRadius, dipoleRadius);
    QColor roundColor(0, 255, 255);
    for (int i = -gridSize; i <= gridSize; ++i) {
        if (i % 10 == 0) {
            gridPen.setWidth(3);
        } else if (i % 5 == 0) {
            gridPen.setWidth(2);
        } else {
            gridPen.setWidth(1);
        }
        _scene->addLine(pxCount * i, -gridSize * pxCount, pxCount * i, gridSize * pxCount, gridPen);
        _scene->addLine(-gridSize * pxCount, pxCount * i, gridSize * pxCount, pxCount * i, gridPen);
    }
    _scene->addEllipse(roundRect, roundColor, roundColor);

    QPointF measurementRadius(pxCount * 2, pxCount * 2);
    QRectF rectRad(-measurementRadius / 2, measurementRadius / 2);
    for (int i = 0; i < _model->measurements().size(); ++i) {
        QPointF measurement = _model->measurements()[i];
        _scene->addEllipse(rectRad.translated(measurement), QColor(255, 255, 0), QColor(255, 255, 0));
        QGraphicsTextItem* text = _scene->addText(QString("%1").arg(i + 10));
        text->setPos(measurement - text->boundingRect().center());
    }
    _scene->addEllipse(rectRad.translated(_model->nextMeasurement()), QColor(0, 255, 0), QColor(0, 255, 0));
}
