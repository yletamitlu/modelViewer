#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <iostream>
#include <QMessageBox>

#include "reader/basereader.h"
#include "reader/filereader.h"
#include "model/carcasemodel.h"
#include "drawer/qtdrawer.h"

#include "app/application.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    Application app;
    QtDrawer* drawer;
};
#endif // MAINWINDOW_H
