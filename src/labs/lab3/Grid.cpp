#include "Grid.h"

#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

const int HALF_CM = 5;
const double SCALE_FACTOR  = 1.25;

QRectF Grid::boundingRect() const {
    return QRectF(-bb, bb);
}

void Grid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QColor baseColor = gridPen.color();
    struct Lines {
        int offset;
        int width;
        QColor darker;
    };
    auto listOfLines = {Lines{1, 1, baseColor}, Lines{HALF_CM, 2, baseColor.darker(115)}, Lines{HALF_CM * 2, 3, baseColor.darker(130)}};
    for (Lines lines : listOfLines) {
        for (int i = -size; i <= size; i += lines.offset) {
            gridPen.setWidth(lines.width);
            gridPen.setColor(lines.darker);
            painter->setPen(gridPen);
            painter->drawLine(pxPerMm * i, -size * pxPerMm, pxPerMm * i, size * pxPerMm);
            painter->drawLine(-size * pxPerMm, pxPerMm * i, size * pxPerMm, pxPerMm * i);
        }
    }
    gridPen.setColor(baseColor);
}

int Grid::getPxPerMm() const {
    return pxPerMm;
}

void Grid::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
    QPointF pos = event->pos();
    if (boundingRect().contains(pos)) {
        emit mouseMove(toGridCoord(pos));
    }
}

QPoint Grid::toGridCoord(const QPointF& pos) const {
    int cmInPx = HALF_CM * pxPerMm;
    QPointF p = pos / cmInPx;
    return {qRound(p.x()) * cmInPx, qRound(p.y()) * cmInPx};
}

void Grid::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() & Qt::RightButton) {
        emit mousePress();
    }
    if (event->button() & Qt::LeftButton) {
        emit mouseDragStart();
    }
}

void Grid::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() & Qt::LeftButton) {
        emit mouseDragStop();
    }
}

void Grid::wheelEvent(QGraphicsSceneWheelEvent *event) {
    if (event->delta() > 0) {
        emit wheelMove(SCALE_FACTOR);
    } else {
        emit wheelMove(1 / SCALE_FACTOR);
    }
}
