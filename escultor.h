#ifndef ESCULTOR_H
#define ESCULTOR_H

struct Voxel {
  float r,g,b; // Colors

  bool isOn; // Included or not
};

class Escultor{
protected:
  Voxel ***v; //Matriz 3D
  int nx,ny,nz; // Dimensões da matriz
  float r,g,b; // Cores da matriz

public:
    Escultor(int _nx, int _ny, int _nz);
    ~Escultor();
    void setColor(float _r, float _g, float _b); //pronto
    void putVoxel(int x0, int y0, int z0); //pronto
    void cutVoxel(int x0, int y0, int z0); //pronto
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1); //pronto
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1); //pronto
    void putSphere(int xcenter, int ycenter, int zcenter, int radius); //pronto
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius); //pronto
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void writeOFF(char *filename); //pronto
};

#endif // ESCULTOR_H
