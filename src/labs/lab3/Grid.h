#pragma once

#include <QGraphicsItem>
#include <QPen>

class Grid : public QObject, public QGraphicsItem {
Q_OBJECT
private:
    const int size = 50;
    const int pxPerMm = 6;
    QPen gridPen = QColor(255, 196, 255);
    const QPointF bb{(double)size * pxPerMm, (double)size * pxPerMm};
    QPoint toGridCoord(const QPointF& pos) const;

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
