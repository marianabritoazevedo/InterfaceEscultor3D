#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "escultor.h"
#include "dialog.h"

enum{
    CAIXA, NOCAIXA, ESFERA, NOESFERA, VOXEL, NOVOXEL, ELIPSE, NOELIPSE
};

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int dimX, dimY, dimZ;
    int r, g, b;
    int currentObject;
    void updateColor();
    Escultor *e;

public slots:
    void sair();
    void abreDialogo(void);
    void setRed(int _r);
    void setGreen(int _g);
    void setBlue(int _b);

private slots:
    void on_action_inserir_voxel_triggered();
    void on_action_retirar_voxel_triggered();
    void on_action_inserir_caixa_triggered();
    void on_action_retirar_caixa_triggered();
    void on_action_inserir_esfera_triggered();
    void on_action_retirar_esfera_triggered();
    void on_action_inserir_elipse_triggered();
    void on_action_retirar_elipse_triggered();


};
#endif // MAINWINDOW_H
