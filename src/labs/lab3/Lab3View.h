#pragma once

#include <QObject>

#include "Grid.h"

class Lab3Model;
class QGraphicsScene;

class Lab3View : public QObject {
Q_OBJECT
private:
    Grid grid;
    Lab3Model* _model;
    QGraphicsScene* _scene;

public:
    Lab3View(QGraphicsScene* scene, Lab3Model* model);
    void setModel(Lab3Model* model);

private slots:
    void modelChange();

signals:
    void mousePressed();
    void mouseDragBegin();
    void mouseDragEnd();
    void wheelMoved(double sc);
};


