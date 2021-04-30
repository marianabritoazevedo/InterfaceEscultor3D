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

/**
 * @brief A classe MainWindow se trata da janela principal do programa
 */
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
    /**
     * @brief updateColor atualiza a cor do elemento a ser desenhado no escultor digital
     */
    void updateColor();
    Escultor *e;
    QActionGroup *actionGroup;

public slots:

    /**
     * @brief sair slot responsável pela função de sair do programa
     */
    void sair();

    /**
     * @brief abreDialogo slot responsável pela função de abrir a caixa de diálogo
     */
    void abreDialogo(void);

    /**
     * @brief setRed slot responsável pela atribuição de cor vermelha
     * @param _r vermelho
     */
    void setRed(int _r);

    /**
     * @brief setGreen slot responsável pela atribuição de cor verde
     * @param _g verde
     */
    void setGreen(int _g);

    /**
     * @brief setBlue slot responsável pela atribuição de cor azul
     * @param _b
     */
    void setBlue(int _b);

    /**
     * @brief drawShape responsável por fazer o desenho da forma selecionada pelo usuário
     */
    void drawShape(int, int);

    /**
     * @brief updateCoords slot responsável pela atualização das coordenadas
     */
    void updateCoords(int, int);

private slots:
    /**
     * @brief novo_escultor slot responável pela criação de um novo escultor
     */
    void novo_escultor();
    /**
     * @brief salvar slot responsável por salvar o arquivo de desenho
     */
    void salvar();
    /**
     * @brief inserir_voxel slot responsável por inserir um voxel na posição desejada
     */
    void inserir_voxel();
    /**
     * @brief remover_voxel slot responsável pela remoção de um voxel na posição desejada
     */
    void remover_voxel();
    /**
     * @brief inserir_caixa slot responsável por inserir uma caixa nas dimensões desejadas
     */
    void inserir_caixa();
    /**
     * @brief remover_caixa slot responsável pela remoção de uma caixa nas dimensões desejadas
     */
    void remover_caixa();
    /**
     * @brief inserir_esfera slot responsável por inserir uma esfera nas dimensões desejadas
     */
    void inserir_esfera();
    /**
     * @brief remover_esfera slot responsável pela remoção de uma esfera nas dimensões desejadas
     */
    void remover_esfera();
    /**
     * @brief inserir_elipse slot responsável por inserir uma elipse nas dimensões desejadas
     */
    void inserir_elipse();
    /**
     * @brief remover_elipse slot responsável por inserir uma elipse nas dimensões desejadas
     */
    void remover_elipse();
    /**
     * @brief slider_eixo_z slot responsável por posicionar o eixo z do escultor
     */
    void slider_eixo_z(int);

};
#endif // MAINWINDOW_H
