#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "escultor.h"
#include <QDebug>
#include <QString>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dimX = 10; dimY = 10; dimZ = 10;
    e = new Escultor(dimX,dimY,dimZ);
    ui->horizontalSliderDimX->setMaximum(dimX-1);
    ui->horizontalSliderDimY->setMaximum(dimY-1);
    ui->horizontalSliderDimZ->setMaximum(dimZ-1);
    ui->widgetDraw->loadMatriz(e->getPlano(ui->horizontalSliderDimZ->value(),XY));
    //Action group -> Um botão é selecionado quando outro desseleciona
    actionGroup = new QActionGroup(this);

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

void MainWindow::drawShape(int hClick, int vClick)
{
    switch(currentObject){
    case(ESFERA):
        e->putSphere(vClick,hClick,ui->horizontalSliderDimZ->value(),ui->horizontalSliderRaio->value());
        ui->widgetDraw->loadMatriz(e->getPlano(ui->horizontalSliderDimZ->value(),XY));
        break;
    case(NOESFERA):
        e->cutSphere(vClick,hClick,ui->horizontalSliderDimZ->value(),ui->horizontalSliderRaio->value());
        ui->widgetDraw->loadMatriz(e->getPlano(ui->horizontalSliderDimZ->value(),XY));
        break;
    case(VOXEL):
        e->putVoxel(vClick,hClick,ui->horizontalSliderDimZ->value());
        ui->widgetDraw->loadMatriz(e->getPlano(ui->horizontalSliderDimZ->value(),XY));
        break;
    case(NOVOXEL):
        e->cutVoxel(vClick,hClick,ui->horizontalSliderDimZ->value());
        ui->widgetDraw->loadMatriz(e->getPlano(ui->horizontalSliderDimZ->value(),XY));
        break;
    case(CAIXA):
        e->putBox(vClick-ui->horizontalSliderCaixaX->value()/2,
                     vClick+ui->horizontalSliderCaixaX->value()/2,
                     hClick-ui->horizontalSliderCaixaY->value()/2,
                     hClick+ui->horizontalSliderCaixaY->value()/2,
                     ui->horizontalSliderDimZ->value()-ui->horizontalSliderCaixaZ->value()/2,
                     ui->horizontalSliderDimZ->value()+ui->horizontalSliderCaixaZ->value()/2);
        ui->widgetDraw->loadMatriz(e->getPlano(ui->horizontalSliderDimZ->value(),XY));
        break;
    case(NOCAIXA):
        e->cutBox(vClick-ui->horizontalSliderCaixaX->value()/2,
                     vClick+ui->horizontalSliderCaixaX->value()/2,
                     hClick-ui->horizontalSliderCaixaY->value()/2,
                     hClick+ui->horizontalSliderCaixaY->value()/2,
                     ui->horizontalSliderDimZ->value()-ui->horizontalSliderCaixaZ->value()/2,
                     ui->horizontalSliderDimZ->value()+ui->horizontalSliderCaixaZ->value()/2);
        ui->widgetDraw->loadMatriz(e->getPlano(ui->horizontalSliderDimZ->value(),XY));
        break;
    case(ELIPSE):
        e->putEllipsoid(vClick,hClick,ui->horizontalSliderDimZ->value(),
                      ui->horizontalSliderElipseRx->value(),
                      ui->horizontalSliderElipseRy->value(),
                      ui->horizontalSliderElipseRz->value());
        ui->widgetDraw->loadMatriz(e->getPlano(ui->horizontalSliderDimZ->value(),XY));
        break;
    case(NOELIPSE):
        e->cutEllipsoid(vClick,hClick,ui->horizontalSliderDimZ->value(),
                      ui->horizontalSliderElipseRx->value(),
                      ui->horizontalSliderElipseRy->value(),
                      ui->horizontalSliderElipseRz->value());
        ui->widgetDraw->loadMatriz(e->getPlano(ui->horizontalSliderDimZ->value(),XY));
        break;

    }
}

void MainWindow::on_action_novo_triggered()
{
    Dialog *dialog;
    dialog = new Dialog();
    dialog->exec();
    if(dialog->result() == QDialog::Accepted){
        dimX = dialog->pegaDimXDialogo().toInt();
        dimY = dialog->pegaDimYDialogo().toInt();
        dimZ = dialog->pegaDimZDialogo().toInt();
        if(e != NULL)
           delete e;
        e = new Escultor(dimX,dimY,dimZ);
        //ui->actionXY->trigger();
        ui->horizontalSliderDimX->setMaximum(dimX-1);
        ui->horizontalSliderDimY->setMaximum(dimY-1);
        ui->horizontalSliderDimZ->setMaximum(dimZ-1);
    }
}

void MainWindow::on_action_salvar_triggered()
{
    QFileDialog dialog;
    QString selectedFilter;
    QString filename = dialog.getSaveFileName(this,tr("Salvar"),
                                              QDir::currentPath(),
                                              tr("Arquivo OFF(*.off);;Arquivo VECT(*.vect)"),
                                              &selectedFilter);
    if(filename.isNull()){
        return;
    }
    e->writeOFF(filename.toStdString());


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



