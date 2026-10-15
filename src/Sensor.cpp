#include "Sensor.h"

#include <iostream>

Sensor::Sensor(int vida) : vidaUtil(30), usos(0) {
    if (vida > 0) {
        vidaUtil = vida;
    } else {
        std::cout << "  [Sensor] Vida util no valida (" << vida
                  << "). Se usan 30.\n";
    }
}

void Sensor::medir() {
    usos++;
}

bool Sensor::perdioCalibracion() const {
    return usos >= vidaUtil;
}

void Sensor::calibrar() {
    usos = 0;
}

void Sensor::mostrar() const {
    std::cout << "    Sensor: " << usos << "/" << vidaUtil << " mediciones\n";
}
