#pragma once

#include <QGraphicsItem>
#include <QPen>

class Grid : public QObject, public QGraphicsItem {
Q_OBJECT
private:
    int size = 50;
    int pxPerMm = 6;
    QPen gridPen = QColor(255, 196, 255);
    QPoint toGridCoord(const QPointF& pos) const;

public:
    int getPxPerMm() const;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    void mouseMove(const QPoint& p);
    void mousePress();
};
