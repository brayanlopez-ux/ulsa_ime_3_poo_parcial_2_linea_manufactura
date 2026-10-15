#include "Husillo.h"

#include <iostream>

Husillo::Husillo(int vida) : vidaUtil(10), usos(0) {
    if (vida > 0) {
        vidaUtil = vida;
    } else {
        std::cout << "  [Husillo] Vida util no valida (" << vida
                  << "). Se usan 10.\n";
    }
}

void Husillo::desgastar() {
    usos++;
}

bool Husillo::estaDesgastado() const {
    return usos >= vidaUtil;
}

void Husillo::reemplazar() {
    usos = 0;
}

void Husillo::mostrar() const {
    std::cout << "    Husillo: " << usos << "/" << vidaUtil << " piezas\n";
}
