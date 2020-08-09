#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    drawer = new QtDrawer(new QGraphicsScene(this));

    ui->graphicsView->centerOn(0, 0);
    ui->graphicsView->setScene(drawer->getScene());

    drawer->getScene()->setSceneRect(-ui->graphicsView->width(), -ui->graphicsView->height(),
                                    ui->graphicsView->width() * 2, ui->graphicsView->height() * 2);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    auto fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/ekaterinaalekseeva", tr("Text files (*.txt)"));
    std::cout << fileName.toStdString() << std::endl;

    if (!fileName.size()) {
        return;
    }

    try {
        app.loadModel(fileName.toStdString());
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;

        QMessageBox msg;
        msg.setText(e.what());
        msg.exec();
    }

    drawer->getScene()->clear();
    app.drawModel(*drawer);
}

void MainWindow::on_btnResize_clicked() {
    app.scale(ui->boxResizeK->value());
    drawer->getScene()->clear();
    app.drawModel(*drawer);
}

void MainWindow::on_btnMove_clicked() {
    app.move(ui->boxMoveX->value(), ui->boxMoveY->value());
    drawer->getScene()->clear();
    app.drawModel(*drawer);
}

void MainWindow::on_btnRotateX_clicked() {
    app.rotateX(ui->boxRotateX->value());
    drawer->getScene()->clear();
    app.drawModel(*drawer);
}

void MainWindow::on_btnRotateY_clicked() {
    app.rotateY(ui->boxRotateY->value());
    drawer->getScene()->clear();
    app.drawModel(*drawer);
}

