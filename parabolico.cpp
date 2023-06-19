#include <iostream>
#include <cmath>
#include "parabolico.h"

Objeto::Objeto(double dia, double vo, double xo, double height, double alphas, int dir) {
    d = dia;
    v0 = vo;
    x0 = xo;
    h = height;
    alpha = alphas;
    d_dir = dir;
}


Simulador::Simulador(double g) {
    gravity = g;
}

void Simulador::run(std::vector<Objeto> objetos) {
    for (const auto& objeto : objetos) {
        double t = 0.0;
        double x, y;
        
        do {
            x = objeto.x0 + objeto.v0 * cos(objeto.alpha) * t * objeto.d_dir;
            y = objeto.h + objeto.v0 * sin(objeto.alpha) * t - 0.5 * gravity * t * t;
            
            std::cout << "x: " << x << ", y: " << y << std::endl;
            
            t += 0.1;
        } while (y > 0.0);
    }
}

bool Simulador::collide(Objeto o1, Objeto o2) {
    double t1 = 0.0;
    double t2 = 0.0;
    
    while (true) {
        double x1 = o1.x0 + o1.v0 * cos(o1.alpha) * t1 * o1.d_dir;
        double y1 = o1.h + o1.v0 * sin(o1.alpha) * t1 - 0.5 * gravity * t1 * t1;
        
        double x2 = o2.x0 + o2.v0 * cos(o2.alpha) * t2 * o2.d_dir;
        double y2 = o2.h + o2.v0 * sin(o2.alpha) * t2 - 0.5 * gravity * t2 * t2;
        
        if (std::abs(x1 - x2) < 0.001 && std::abs(y1 - y2) < 0.001) {
            return true; // Colisión detectada
        }
        
        if (y1 <= 0.0 && y2 <= 0.0) {
            return false; // No hay colisión antes de tocar el suelo
        }
        
        t1 += 0.1;
        t2 += 0.1;
    }
}

double Simulador::distance(Objeto o1) {
    double t = 0.0;
    
    while (true) {
        double x = o1.x0 + o1.v0 * cos(o1.alpha) * t * o1.d_dir;
        double y = o1.h + o1.v0 * sin(o1.alpha) * t - 0.5 * gravity * t * t;
        
        if (y <= 0.0) {
            return x; // Distancia alcanzada en el eje x al tocar el suelo
        }
        
        t += 0.1;
    }
}
