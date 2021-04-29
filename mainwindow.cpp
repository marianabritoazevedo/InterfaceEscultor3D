#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dimX = 10; dimY = 10; dimZ = 10;
    ui->horizontalSliderDimX->setMaximum(dimX-1);
    ui->horizontalSliderDimY->setMaximum(dimY-1);
    ui->horizontalSliderDimZ->setMaximum(dimZ-1);
    ui->widgetDraw->loadMatriz(e->getPlano(ui->horizontalSliderDimZ->value()));

    connect(ui->actionAbreDialogo,
            SIGNAL(triggered(bool)),
            this,
            SLOT(abreDialogo()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sair()
{
    exit(0);
}

void MainWindow::abreDialogo()
{
    Dialog d;
    if(d.exec() == QDialog::Accepted){
        dimX = d.pegaDimXDialogo().toInt();
        dimY = d.pegaDimYDialogo().toInt();
        dimZ = d.pegaDimZDialogo().toInt();
        qDebug() << dimX << dimY << dimZ;
        ui->horizontalSliderDimX->setMaximum(dimX-1);
        ui->horizontalSliderDimY->setMaximum(dimY-1);
        ui->horizontalSliderDimZ->setMaximum(dimZ-1);
    }


}

void MainWindow::setRed(int _r)
{
    r = _r;
    updateColor();
}

void MainWindow::setGreen(int _g)
{
    g = _g;
    updateColor();
}

void MainWindow::setBlue(int _b)
{
    b = _b;
    updateColor();
}

void MainWindow::on_action_inserir_voxel_triggered()
{
    currentObject = VOXEL;
}

void MainWindow::on_action_retirar_voxel_triggered()
{
    currentObject = NOVOXEL;
}

void MainWindow::on_action_inserir_caixa_triggered()
{
    currentObject = CAIXA;
}

void MainWindow::on_action_retirar_caixa_triggered()
{
    currentObject = NOCAIXA;
}

void MainWindow::on_action_inserir_esfera_triggered()
{
    currentObject = ESFERA;
}

void MainWindow::on_action_retirar_esfera_triggered()
{
    currentObject = NOESFERA;
}

void MainWindow::on_action_inserir_elipse_triggered()
{
    currentObject = ELIPSE;
}

void MainWindow::on_action_retirar_elipse_triggered()
{
    currentObject = NOELIPSE;
}

void MainWindow::updateColor()
{
    QString color;
    color = "QPushButton { background-color: rgb(" +
            QString().setNum(r) + "," +
            QString().setNum(g) + "," +
            QString().setNum(b) + ");}";
    ui->pushButtonMostraColor->setStyleSheet(color);
    e->setColor(r,g,b);
}



