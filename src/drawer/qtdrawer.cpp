#include "drawer/qtdrawer.h"


QtDrawer::QtDrawer(QGraphicsScene* s) : scene(s) {
    pen = QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
}

QtDrawer::~QtDrawer() {
    delete scene;
}

void QtDrawer::drawPolygon(Face& face) {
     const QVector<QPointF> points = {
            QPointF(face.vertices[0].x, face.vertices[0].y),
            QPointF(face.vertices[1].x, face.vertices[1].y),
            QPointF(face.vertices[2].x, face.vertices[2].y),
    };

    QPolygonF polygon(points);

    scene->addPolygon(polygon, this->pen);

    scene->update();
}

void QtDrawer::drawModel(BaseModel& model) {
    auto f = model.getFaces();
    for (int i = 0; i < f.size(); i++) {
        drawPolygon(f[i]);
    }
}
