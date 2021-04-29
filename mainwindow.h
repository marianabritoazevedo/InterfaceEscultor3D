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
    void drawShape(int, int);

private slots:
<<<<<<< HEAD
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
=======
    void on_action_novo_triggered();
    void on_action_salvar_triggered();
    void on_action_inserir_voxel_triggered();
    void on_action_retirar_voxel_triggered();
    void on_action_inserir_caixa_triggered();
    void on_action_retirar_caixa_triggered();
    void on_action_inserir_esfera_triggered();
    void on_action_retirar_esfera_triggered();
    void on_action_inserir_elipse_triggered();
    void on_action_retirar_elipse_triggered();
>>>>>>> 1c73a1de87b96b93348b8af250cb7faa88dae9f0


};
#endif // MAINWINDOW_H
