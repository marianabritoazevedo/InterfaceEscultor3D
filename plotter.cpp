#include "plotter.h"
#include <QPainter>
#include <QSize>
#include <QPen>
#include <QBrush>
#include <QPoint>
#include <QMouseEvent>
#include <QGradient>
#include <cmath>
#include <iostream>
#include <escultor.h>
#include <qdebug.h>

Plotter::Plotter(QWidget *parent) : QWidget(parent)
{
    nl = 10;
    nc = 10;
    //Escultor(nl,nc,10);
    pressed = false;
    larguraTela = rect().width();
    alturaTela = rect().height();
    larguraCelula = larguraTela/nc;
    alturaCelula = alturaTela/nl;
    if (alturaCelula > larguraCelula){
        dimCelula = larguraCelula;
    }else{
        dimCelula = alturaCelula;
    }
    setTamanho(nl,nc);
}

void Plotter::paintEvent(QPaintEvent *e)
{

    QPen pen;
    QPainter p(this);
    QBrush brush;
    QColor color;
    QRadialGradient gradient(QPointF(1,1),20);
    gradient.setColorAt(0, Qt::black);
    gradient.setColorAt(1, Qt::white);
    p.setRenderHint(QPainter::Antialiasing, true);
    pen.setWidth(1);
    larguraTela = rect().width();
    alturaTela = rect().height();
    larguraCelula = larguraTela/nc;
    alturaCelula = alturaTela/nl;
    if (alturaCelula > larguraCelula){
        dimCelula = larguraCelula;
    }else{
        dimCelula = alturaCelula;
    }
    borderh = (larguraTela - nc*dimCelula)/2;
    borderv = (alturaTela - nl*dimCelula)/2;
    gradient.setRadius(dimCelula);
    gradient.setFocalPoint(-0.15*dimCelula, -0.15*dimCelula);
    gradient.setCenter(-0.15*dimCelula, -0.15*dimCelula);
    p.setPen(pen);
    p.drawRect(rect());
    qDebug() << nl << nc << v.size() << v[0].size();
    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++){
            if(v[i][j].isOn == true){
                p.save();
                p.translate(j*dimCelula+borderh+dimCelula/2,
                            i*dimCelula+borderv+dimCelula/2);
                p.setPen(Qt::NoPen);
                color.setRgb(qRgb(v[i][j].r, v[i][j].g, v[i][j].b));
                gradient.setColorAt(0, Qt::white);
                gradient.setColorAt(0.3, color);
                gradient.setColorAt(1, color.darker());
                p.setBrush(gradient);
                p.drawEllipse(-dimCelula/2+1, -dimCelula/2+1, dimCelula-1, dimCelula-1);
                p.restore();
            }else{
                brush.setColor(QColor(255,255,255,0));
                p.setBrush(brush);
                p.drawRect(j*dimCelula+borderh,i*dimCelula+borderv,dimCelula, dimCelula);
            }
        }
    }

}

void Plotter::setTamanho(int _nl, int _nc)
{
    nl = _nl;
    nc = _nc;
    repaint();
}

void Plotter::mousePressEvent(QMouseEvent *event)
{
    int posh, posv;
    QRect ret;
    ret = rect();
    pressed = true;
    ret.adjust(borderh, borderv, -borderh, -borderv);
    if(ret.contains(event->pos())){
        posh = (event->pos().x()-borderh)*nc/ret.width();
        posv = (event->pos().y()-borderv)*nl/ret.height();
        emit atualizaPosicao(posh, posv);
    }
}

void Plotter::mouseMoveEvent(QMouseEvent *event)
{
    int posh, posv;
    QRect ret;
    ret = rect();
    ret.adjust(borderh, borderv, -borderh, -borderv);
    if(ret.contains(event->pos())&& pressed == true){
        posh = (event->pos().x()-borderh)*nc/ret.width();
        posv = (event->pos().y()-borderv)*nl/ret.height();
        emit atualizaPosicao(posh, posv);
    }

}

void Plotter::mouseReleaseEvent(QMouseEvent *event)
{
    pressed = false;
}

void Plotter::loadMatriz(vector<vector<Voxel> > m)
{
    nl = m.size();
    nc = m[0].size();
    v = m;
    repaint();
}
