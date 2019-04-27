#include "Grid.h"

#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

const int HALF_CM = 5;

QRectF Grid::boundingRect() const {
    QPointF bb(size * pxPerMm, size * pxPerMm);
    return QRectF(-bb, bb);
}

void Grid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    for (int i = -size; i <= size; ++i) {
        if (i % (HALF_CM * 2) == 0) {
            gridPen.setWidth(3);
        } else if (i % HALF_CM == 0) {
            gridPen.setWidth(2);
        } else {
            gridPen.setWidth(1);
        }
        painter->setPen(gridPen);
        painter->drawLine(pxPerMm * i, -size * pxPerMm, pxPerMm * i, size * pxPerMm);
        painter->drawLine(-size * pxPerMm, pxPerMm * i, size * pxPerMm, pxPerMm * i);
    }
}

int Grid::getPxPerMm() const {
    return pxPerMm;
}

void Grid::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
    emit mouseMove(toGridCoord(event->pos()));
}

QPoint Grid::toGridCoord(const QPointF& pos) const {
    int cmInPx = HALF_CM * pxPerMm;
    QPointF p = pos / cmInPx;
    return {qRound(p.x()) * cmInPx, qRound(p.y()) * cmInPx};
}

void Grid::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() & Qt::LeftButton) {
        emit mousePress();
    }
}
