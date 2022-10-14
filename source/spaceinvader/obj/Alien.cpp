#include "Alien.h"
#include <stdint.h>
#include <stdlib.h>

    Alien::Alien(){}
    Alien::Alien(uint8_t _x, uint8_t _y, uint8_t _radius) : x(_x), y(_y), radius(_radius){}

    uint8_t Alien::getX(){
        return x;
    }
    uint8_t Alien::getY(){
        return y;
    }
    uint8_t Alien::getRadius(){
        return radius;
    }

    void Alien::moveX(uint8_t _x){
        x += _x;
    }
    void Alien::moveY(uint8_t _y){
        y += _y;
    }