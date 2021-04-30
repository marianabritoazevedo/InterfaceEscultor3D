#ifndef ESCULTOR_H
#define ESCULTOR_H
#include <vector>
#include <string>

using namespace std;

/**
 * @brief Estrutura para a criação de um Voxel.
 */
struct Voxel {
  float r,g,b; // Colors

  bool isOn; // Included or not
};

enum{XY,ZX,YZ};

/**
 * @brief A classe Escultor gera uma matriz 3D com várias funções de desenho. Ela é responsável por criar um escultor, alocando dinamicamente uma matriz 3D de dimensões nx, ny, nz.
 */

class Escultor{
protected:
  Voxel ***v; //Matriz 3D
  int nx,ny,nz; // Dimensões da matriz
  float r,g,b; // Cores da matriz

public:
  /**
     * @brief Constroi um novo objeto Escultor com dimensões _nx, _ny e _nz.
     * @param _nx dimensão do construtor no eixo x
     * @param _ny dimensão do construtor no eixo y
     * @param _nz dimensão do construtor no eixo z
     */

    Escultor(int _nx, int _ny, int _nz);
    /**
       * @brief Destrutor de um objeto Escultor.
       */
    ~Escultor();

    /**
       * @brief Função para atribuição de cor ao Voxel.
       * @param _r vermelho
       * @param _g verde
       * @param _b azul
       */
    void setColor(float _r, float _g, float _b); //pronto

    /**
       * @brief Adiciona um Voxel nas posições x0, y0 e z0 da matriz.
       * @param x0 valor da coordenada x0
       * @param y0 valor da coordenada y0
       * @param z0 valor da coordenada z0
       */
    void putVoxel(int x0, int y0, int z0); //pronto

    /**
      * @brief Retira um Voxel nas posições x0, y0 e z0 da matriz.
      * @param x0 valor da coordenada x0
      * @param y0 valor da coordenada y0
      * @param z0 valor da coordenada z0
      */
    void cutVoxel(int x0, int y0, int z0); //pronto

    /**
       * @brief Adiciona um conjunto de Voxels, formando um paralelepípedo.
       * @param x0 valor da coordenada x0 (x inicial)
       * @param x1 valor da coordenada x1 (x final)
       * @param y0 valor da coordenada y0 (y inicial)
       * @param y1 valor da coordenada y1 (y final)
       * @param z0 valor da coordenada z0 (z inicial)
       * @param z1 valor da coordenada z1 (z final)
       */
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1); //pronto

    /**
       * @brief Retira um conjunto de Voxels do paralelepípedo.
       * @param x0 valor da coordenada x0 (x inicial)
       * @param x1 valor da coordenada x1 (x final)
       * @param y0 valor da coordenada y0 (y inicial)
       * @param y1 valor da coordenada y1 (y final)
       * @param z0 valor da coordenada z0 (z inicial)
       * @param z1 valor da coordenada z1 (z final)
       */
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1); //pronto

    /**
       * @brief Adiciona um conjunto de Voxels em formato de esfera no escultor.
       * @param xcenter coordenada do centro da esfera no eixo x
       * @param ycenter coordenada do centro da esfera no eixo y
       * @param zcenter coordenada do centro da esfera no eixo z
       * @param radius raio da esfera
       */
    void putSphere(int xcenter, int ycenter, int zcenter, int radius); //pronto

    /**
       * @brief Retira um conjunto de Voxels em formato de esfera no escultor.
       * @param xcenter coordenada do centro da esfera no eixo x
       * @param ycenter coordenada do centro da esfera no eixo y
       * @param zcenter coordenada do centro da esfera no eixo z
       * @param radius raio da esfera
       */
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius); //pronto

    /**
       * @brief Adiciona um conjunto de Voxels em formato de elipsoide no escultor.
       * @param xcenter coordenada do centro do elipsoide no eixo x
       * @param ycenter coordenada do centro do elipsoide no eixo y
       * @param zcenter coordenada do centro do elipsoide no eixo z
       * @param rx parâmetro que determina forma do elipsoide no eixo x
       * @param ry parâmetro que determina forma do elipsoide no eixo y
       * @param rz parâmetro que determina forma do elipsoide no eixo z
       */
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

    /**
       * @brief Retira um conjunto de Voxels em formato de elipsoide no escultor.
       * @param xcenter coordenada do centro do elipsoide no eixo x
       * @param ycenter coordenada do centro do elipsoide no eixo y
       * @param zcenter coordenada do centro do elipsoide no eixo z
       * @param rx parâmetro que determina forma do elipsoide no eixo x
       * @param ry parâmetro que determina forma do elipsoide no eixo y
       * @param rz parâmetro que determina forma do elipsoide no eixo z
       */
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

    /**
      * @brief Escreve o arquivo .OFF para a geração do desenho 3D.
      * @param filename nome do arquivo
      */
    void writeOFF(string filename); //pronto

    /**
     * @brief getPlano lê o plano da interface
     * @param i eixo z
     * @param plano XY
     */
    vector< vector<Voxel> > getPlano(int i, int plano=XY);
};

#endif // ESCULTOR_H
