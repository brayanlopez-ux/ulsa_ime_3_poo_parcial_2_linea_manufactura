#include "HerramientaCorte.h"

#include <iostream>

HerramientaCorte::HerramientaCorte(int vida) : vidaUtil(20), usos(0) {
    if (vida > 0) {
        vidaUtil = vida;
    } else {
        std::cout << "  [Herramienta de corte] Vida util no valida (" << vida
                  << "). Se usan 20.\n";
    }
}

void HerramientaCorte::desgastar() {
    usos++;
}

bool HerramientaCorte::estaDesgastada() const {
    return usos >= vidaUtil;
}

void HerramientaCorte::afilar() {
    usos = 0;
}

void HerramientaCorte::mostrar() const {
    std::cout << "    Herramienta de corte: " << usos << "/" << vidaUtil << " piezas\n";
}
