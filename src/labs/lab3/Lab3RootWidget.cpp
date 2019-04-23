#include "Lab3RootWidget.h"

Lab3RootWidget::Lab3RootWidget()
    : scene(this)
{
    setupUi(this);
    labInstallment->setScene(&scene);
    int pxCount = 6;
    int gridSize = 50;
    int radius = pxCount * 30;
    QPen gridPen({255, 0, 255});
    QRect roundRect(-radius / 2, -radius / 2, radius, radius);
    QColor roundColor(0, 255, 255);
    for (int i = -gridSize; i <= gridSize; ++i) {
        if (i % 5 == 0) {
            gridPen.setWidth(2);
        } else {
            gridPen.setWidth(1);
        }
        scene.addLine(pxCount * i, -gridSize * pxCount, pxCount * i, gridSize * pxCount, gridPen);
        scene.addLine(-gridSize * pxCount, pxCount * i, gridSize * pxCount, pxCount * i, gridPen);
    }
    scene.addEllipse(roundRect, roundColor, roundColor);
}
