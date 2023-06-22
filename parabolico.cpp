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

std::vector<Resultado> Simulador::run(std::vector<Objeto> objetos) {
    std::vector<Resultado> resultados;
    for (const auto& objeto : objetos) {
        double t = 0.0;
        double x, y;
        double angulo_objeto_rad = objeto.alpha * (M_PI / 180);
        do {
            x = objeto.x0 + objeto.v0 * cos(angulo_objeto_rad) * t * objeto.d_dir;
            y = objeto.h + objeto.v0 * sin(angulo_objeto_rad) * t - 0.5 * gravity * t * t;
            resultados.push_back({t, x, y});
            t += 0.1;
        } while (y > 0.0);
    }
    return resultados;
}


bool Simulador::collide(Objeto o1, Objeto o2) {
    double t = 0.0;
    double angulo_o1_rad = o1.alpha*(M_PI/180);
    double angulo_o2_rad = o2.alpha*(M_PI/180);
    while (true) {
        double x1 = o1.x0 + o1.v0 * cos(angulo_o1_rad) * t * o1.d_dir;
        double y1 = o1.h + o1.v0 * sin(angulo_o1_rad) * t - 0.5 * gravity * t * t;
        
        double x2 = o2.x0 + o2.v0 * cos(angulo_o2_rad) * t * o2.d_dir;
        double y2 = o2.h + o2.v0 * sin(angulo_o2_rad) * t - 0.5 * gravity * t * t;

        double distancia_minima = (o1.d + o2.d) / 2.0;
        double distancia_actual = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        
        if (distancia_actual<=distancia_minima) {
            return true; // Colisión detectada
        }
        
        if (y1 <= 0.0 && y2 <= 0.0) {
            return false; // No hay colisión antes de tocar el suelo
        }
        
        t += 0.1;
    }
}

double Simulador::distance(Objeto o1) {
    double t = 0.0;
    double angulo_o1_rad = o1.alpha*(M_PI/180);
    while (true) {
        double x = o1.x0 + o1.v0 * cos(angulo_o1_rad) * t * o1.d_dir;
        double y = o1.h + o1.v0 * sin(angulo_o1_rad) * t - 0.5 * gravity * t * t;
        
        if (y <= 0.0) {
            return x; // Distancia alcanzada en el eje x al tocar el suelo
        }
        
        t += 0.1;
    }
}
