#ifndef PARABOLICO_H
#define PARABOLICO_H

#include <vector>

class Objeto {
public:
    double d;    // diámetro del objeto
    double v0;   // velocidad inicial
    double x0;   // posición inicial horizontal
    double h;    // posición inicial vertical
    double alpha; // ángulo del tiro
    int d_dir;   // dirección del lanzamiento (1: izquierda a derecha, -1: derecha a izquierda)
    Objeto(double dia,double vo,double xo,double hight,double alpha,int dir);
    Objeto() = default;
};

class Simulador {
private:
    double gravity; // aceleración de gravedad

public:
    Simulador(double g);
    void run(std::vector<Objeto> objetos);
    bool collide(Objeto o1, Objeto o2);
    double distance(Objeto o1);
};

#endif
