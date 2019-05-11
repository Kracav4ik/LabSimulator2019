#include "Grid.h"

#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

const int HALF_CM = 5;
const double SCALE_FACTOR = 1.25;
const int PX_PER_MM = 6;
const QColor GRID_COLOR(255, 196, 255);

QRect Grid::boundingRectMm() const {
    return QRect(-100, -100, 410, 200);
}

QRectF Grid::boundingRect() const {
    QRect boundsMm = boundingRectMm();
    QPoint margin(1, 1);
    return QRectF((boundsMm.topLeft() - 2*margin) * PX_PER_MM, (boundsMm.bottomRight() + 3*margin) * PX_PER_MM);
}

void Grid::paintLines(QPainter* painter, QPoint p1, QPoint p2, QPoint step, int stepMul, int count) const {
    step *= stepMul;
    for (int i = 0; i <= count; i += stepMul) {
        painter->drawLine(p1 * PX_PER_MM, p2 * PX_PER_MM);
        p1 += step;
        p2 += step;
    }
}

void Grid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    struct Lines {
        int offset;
        qreal width;
        QColor color;
    };
    auto listOfLines = {
            Lines{1, 1, GRID_COLOR},
            Lines{HALF_CM, 2, GRID_COLOR.darker(115)},
            Lines{HALF_CM * 2, 3, GRID_COLOR.darker(130)}
    };
    QRect boundsMm = boundingRectMm();
    QPoint dx(1, 0);
    QPoint dy(0, 1);
    for (const Lines& lines : listOfLines) {
        painter->setPen(QPen(lines.color, lines.width));
        paintLines(painter, boundsMm.topLeft(), boundsMm.bottomLeft() + dy, dx, lines.offset, boundsMm.width());
        paintLines(painter, boundsMm.topLeft(), boundsMm.topRight() + dx, dy, lines.offset, boundsMm.height());
    }

    painter->setPen(QPen(Qt::black, 3));
    painter->drawLine(boundsMm.left() * PX_PER_MM, 0, boundsMm.right() * PX_PER_MM, 0);
    painter->drawLine(0, boundsMm.top() * PX_PER_MM, 0, boundsMm.bottom() * PX_PER_MM);
}

int Grid::getPxPerMm() const {
    return PX_PER_MM;
}

void Grid::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
    QPointF pos = event->pos();
    if (boundingRect().contains(pos)) {
        emit mouseMove(snapToGridCoord(pos) / PX_PER_MM);
    }
}

QPoint Grid::snapToGridCoord(const QPointF& pos) const {
    int cmInPx = HALF_CM * PX_PER_MM;
    QPointF p = pos / cmInPx;
    return QPoint(qRound(p.x()) * cmInPx, qRound(p.y()) * cmInPx);
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
