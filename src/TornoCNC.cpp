#include "../include/TornoCNC.h"

#include <iostream>

TornoCNC::TornoCNC(int id, const std::string& nombre, int segundos, int valor2, int vidaHusillo)
    : Maquina(id, nombre),
      segundosPorPieza(30),
      rpm(1500),
      husillo(vidaHusillo) {
    setSegundosPorPieza(segundos);
    setRpm(valor2);
}

void TornoCNC::setSegundosPorPieza(int segundos) {
    if (segundos > 0) {
        segundosPorPieza = segundos;
    } else {
        std::cout << "  [" << getNombre() << "] Segundos por pieza no valido: "
                  << segundos << "\n";
    }
}

void TornoCNC::setRpm(int valor) {
    if (valor > 0) {
        rpm = valor;
    } else {
        std::cout << "  [" << getNombre() << "] Velocidad del husillo no valida: "
                  << valor << "\n";
    }
}

bool TornoCNC::procesarPieza() {
    // Solo procesa si esta encendida y sin falla.
    if (!puedeProcesar()) {
        std::cout << "  [" << getNombre() << "] Rechaza la pieza ("
                  << (estaEncendida() ? "en falla" : "apagada") << ")\n";
        return false;
    }

    // Hace su trabajo y le avisa a la base.
    husillo.desgastar();
    registrarPieza();
    agregarTiempo(segundosPorPieza);
    std::cout << "  [" << getNombre() << "] Cilindra la pieza ("
              << segundosPorPieza << " s)\n";

    // Si esta pieza agoto el componente, la maquina entra en falla.
    if (husillo.estaDesgastado()) {
        reportarFalla();
        std::cout << "  [" << getNombre() << "] FALLA: husillo desgastado\n";
    }
    return true;
}

void TornoCNC::darMantenimiento() {
    husillo.reemplazar();
    registrarMantenimiento();
    std::cout << "  [" << getNombre() << "] Mantenimiento: husillo nuevo\n";
}

void TornoCNC::mostrarEstado() const {
    Maquina::mostrarEstado();   // reutiliza la version de la base
    std::cout << "    Torno CNC: " << rpm << " rpm, "
              << segundosPorPieza << " s por pieza\n";
    husillo.mostrar();
}
