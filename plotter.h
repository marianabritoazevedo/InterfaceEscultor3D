#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <vector>
#include <QVector>
#include "escultor.h"

using namespace std;

/**
 * @brief A classe Plotter é responsável pelo desenho do widget personalizado, que é o escultor
 */
class Plotter : public QWidget
{
    Q_OBJECT
public:
    explicit Plotter(QWidget *parent = nullptr);

    /**
     * @brief paintEvent sobrecarga para desenhar o escultor na interface
     * @param e evento
     */
    void paintEvent(QPaintEvent *e);

    /**
     * @brief setTamanho responsável por dimensionar o tamanho do escultor
     * @param _nl número de linhas
     * @param _nc número de colunas
     */
    void setTamanho(int _nl, int _nc);

    /**
     * @brief mousePressEvent sobrecarga para controlar o click do mouse
     * @param event evento
     */
    void mousePressEvent(QMouseEvent *event);

    /**
     * @brief mouseMoveEvent sobrecarga para controlar o movimento do mouse
     * @param event evento
     */
    void mouseMoveEvent(QMouseEvent *event);

    /**
     * @brief mouseReleaseEvent sobrecarga para liberar o click do mouse
     * @param event evento
     */
    void mouseReleaseEvent(QMouseEvent *event);

    /**
     * @brief loadMatriz carrega a matriz para mostrar o escultor de acordo com suas dimensões
     * @param m matriz
     */
    void loadMatriz(vector <vector <Voxel> > m);

private:
    int nl, nc;
    vector <vector <Voxel> > v;
    int borderv, borderh;
    int dimCelula;
    int larguraTela, alturaTela;
    int larguraCelula, alturaCelula;
    bool pressed;

signals:
    /**
     * @brief atualizaPosicao atualiza a posição do click do mouse
     */
    void atualizaPosicao(int,int);

};

#endif // PLOTTER_H
