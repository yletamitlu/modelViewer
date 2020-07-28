#ifndef VIEWER_QTDRAWER_H
#define VIEWER_QTDRAWER_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsScene>
#include "basedrawer.h"


class QtDrawer : public BaseDrawer {
public:
    QtDrawer() : scene(nullptr) {}
    explicit QtDrawer(QGraphicsScene* s);
    ~QtDrawer();

    void drawPolygon(Face& face) override;

    void drawModel(BaseModel& model) override;

    QGraphicsScene* getScene() {
        return scene;
    }

private:
    QPen pen;
    QGraphicsScene* scene;
};


#endif //VIEWER_QTDRAWER_H
