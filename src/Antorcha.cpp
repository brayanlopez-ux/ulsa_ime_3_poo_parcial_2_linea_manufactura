#include "Antorcha.h"

#include <iostream>

Antorcha::Antorcha(int vida) : vidaUtil(15), usos(0) {
    if (vida > 0) {
        vidaUtil = vida;
    } else {
        std::cout << "  [Antorcha] Vida util no valida (" << vida
                  << "). Se usan 15.\n";
    }
}

void Antorcha::desgastar() {
    usos++;
}

bool Antorcha::estaDesgastada() const {
    return usos >= vidaUtil;
}

void Antorcha::cambiarAlambre() {
    usos = 0;
}

void Antorcha::mostrar() const {
    std::cout << "    Antorcha: " << usos << "/" << vidaUtil << " piezas\n";
}
