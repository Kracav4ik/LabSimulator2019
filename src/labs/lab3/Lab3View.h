#pragma once

#include <QObject>

class Lab3Model;
class QGraphicsScene;

class Lab3View : public QObject {
Q_OBJECT
private:
    Lab3Model* _model;
    QGraphicsScene* _scene;

public:
    explicit Lab3View(QGraphicsScene* scene, Lab3Model* model);
    void setModel(Lab3Model* model);

private slots:
    void modelChange();
};


