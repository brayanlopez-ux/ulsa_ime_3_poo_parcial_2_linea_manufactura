#include "Motor.h"

#include <iostream>

Motor::Motor(int vida) : vidaUtil(50), usos(0) {
    if (vida > 0) {
        vidaUtil = vida;
    } else {
        std::cout << "  [Motor] Vida util no valida (" << vida
                  << "). Se usan 50.\n";
    }
}

void Motor::desgastar() {
    usos++;
}

bool Motor::estaDesgastado() const {
    return usos >= vidaUtil;
}

void Motor::reparar() {
    usos = 0;
}

void Motor::mostrar() const {
    std::cout << "    Motor: " << usos << "/" << vidaUtil << " piezas\n";
}
