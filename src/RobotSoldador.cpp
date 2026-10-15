#include "RobotSoldador.h"

#include <iostream>

RobotSoldador::RobotSoldador(int id, const std::string& nombre, int segundos, int valor2, int vidaAntorcha)
    : Maquina(id, nombre),
      segundosPorPieza(20),
      corrienteAmperes(200),
      antorcha(vidaAntorcha) {
    setSegundosPorPieza(segundos);
    setCorrienteAmperes(valor2);
}

void RobotSoldador::setSegundosPorPieza(int segundos) {
    if (segundos > 0) {
        segundosPorPieza = segundos;
    } else {
        std::cout << "  [" << getNombre() << "] Segundos por pieza no valido: "
                  << segundos << "\n";
    }
}

void RobotSoldador::setCorrienteAmperes(int valor) {
    if (valor > 0) {
        corrienteAmperes = valor;
    } else {
        std::cout << "  [" << getNombre() << "] Corriente de soldadura no valida: "
                  << valor << "\n";
    }
}

bool RobotSoldador::procesarPieza() {
    // Solo procesa si esta encendida y sin falla.
    if (!puedeProcesar()) {
        std::cout << "  [" << getNombre() << "] Rechaza la pieza ("
                  << (estaEncendida() ? "en falla" : "apagada") << ")\n";
        return false;
    }

    // Hace su trabajo y le avisa a la base.
    antorcha.desgastar();
    registrarPieza();
    agregarTiempo(segundosPorPieza);
    std::cout << "  [" << getNombre() << "] Suelda la pieza ("
              << segundosPorPieza << " s)\n";

    // Si esta pieza agoto el componente, la maquina entra en falla.
    if (antorcha.estaDesgastada()) {
        reportarFalla();
        std::cout << "  [" << getNombre() << "] FALLA: antorcha sin alambre\n";
    }
    return true;
}

void RobotSoldador::darMantenimiento() {
    antorcha.cambiarAlambre();
    registrarMantenimiento();
    std::cout << "  [" << getNombre() << "] Mantenimiento: alambre nuevo\n";
}

void RobotSoldador::mostrarEstado() const {
    Maquina::mostrarEstado();   // reutiliza la version de la base
    std::cout << "    Robot soldador: " << corrienteAmperes << " A, "
              << segundosPorPieza << " s por pieza\n";
    antorcha.mostrar();
}
