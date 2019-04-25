#pragma once

#include <QObject>

class Ldb3Model;
class QGraphicsScene;

class Ldb3View : public QObject {
Q_OBJECT
private:
    Ldb3Model* _model;
    QGraphicsScene* _scene;

public:
    explicit Ldb3View(QGraphicsScene* scene, Ldb3Model* model);
    void setModel(Ldb3Model* model);

private slots:
    void modelChange();
};


