#include "parabolico.h"
#include <vector>
#include <iostream>
// g++ test2.cpp parabolico.cpp -o p
// ./p
int main(){
    Objeto obj1(5,10,0,5,45,1);
    Objeto obj2(12,1,10,10,30,-1);
    Simulador simulador(9.81);
    simulador.run({obj1,obj2}); // Va imprimiendo el reccorrido, recibe un vector
    bool isCollision = simulador.collide(obj1, obj2); // Si es que chocan
    double distanceCovered = simulador.distance(obj1); // Distancia recorrida
    std::cout<< isCollision << std::endl;
    std::cout<< distanceCovered << std::endl;
}