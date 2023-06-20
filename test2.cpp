#include "parabolico.h"
#include <vector>
#include <iostream>

int main(){
    Objeto obj1(5,10,0,5,45,1);
    Objeto obj2(12,1,10,10,30,-1);
    Simulador simulador(9.81);
    simulador.run({obj1,obj2});
    bool isCollision = simulador.collide(obj1, obj2); // Check if the objects collide
    double distanceCovered = simulador.distance(obj1); // Calculate the distance covered by the object
    std::cout<< isCollision << std::endl;
    std::cout<< distanceCovered << std::endl;
}