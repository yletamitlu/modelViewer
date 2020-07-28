#include "drawer/qtdrawer.h"


QtDrawer::QtDrawer(QGraphicsScene* s) : scene(s) {
    pen = QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    //система координат привет
    scene->addLine(QLine(-250, 0, 250, 0), this->pen);
    scene->addLine(QLine(245, 5, 250, 0), this->pen);
    scene->addLine(QLine(245, -5, 250, 0), this->pen);

    scene->addLine(QLine(0, -250, 0, 250), this->pen);
    scene->addLine(QLine(5, -245, 0, -250), this->pen);
    scene->addLine(QLine(-5, -245, 0, -250), this->pen);

    //а это X и Y соотетственно, ведь у куграфиксцены нет добавить текст в нужную точку))0
    scene->addLine(QLine(250, 20, 245, 10), this->pen);
    scene->addLine(QLine(245, 20, 250, 10), this->pen);

    scene->addLine(QLine(15, -250, 18, -245), this->pen);
    scene->addLine(QLine(21, -250, 18, -245), this->pen);
    scene->addLine(QLine(18, -240, 18, -245), this->pen);
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
