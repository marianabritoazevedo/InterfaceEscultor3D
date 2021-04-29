#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "escultor.h"
#include "dialog.h"
#include <QActionGroup>

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
    QActionGroup *actionGroup;

public slots:
    void sair();
    void abreDialogo(void);
    void setRed(int _r);
    void setGreen(int _g);
    void setBlue(int _b);

private slots:
    void novo_escultor();
    void salvar();
    void inserir_voxel();
    void remover_voxel();
    void inserir_caixa();
    void remover_caixa();
    void inserir_esfera();
    void remover_esfera();
    void inserir_elipse();
    void remover_elipse();


};
#endif // MAINWINDOW_H
