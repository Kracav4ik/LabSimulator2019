#pragma once

#include <QGraphicsItem>
#include <QPen>

class Grid : public QObject, public QGraphicsItem {
Q_OBJECT
private:
    QPoint snapToGridCoord(const QPointF& pos) const;
    QRect boundingRectMm() const;
    void paintLines(QPainter* painter, QPoint p1, QPoint p2, QPoint step, int stepMul, int count) const;

public:
    int getPxPerMm() const;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;

signals:
    void mouseMove(const QPoint& p);
    void mouseDragStart();
    void mouseDragStop();
    void mousePress();
    void wheelMove(double sc);
};
