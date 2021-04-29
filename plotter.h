#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <vector>
#include <QVector>
#include "escultor.h"

using namespace std;

class Plotter : public QWidget
{
    Q_OBJECT
public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *e);
    void setTamanho(int _nl, int _nc);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
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
    void atualizaPosicao(int,int);

};

#endif // PLOTTER_H
