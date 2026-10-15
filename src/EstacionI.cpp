#include "EstacionI.h"

#include <iostream>

EstacionI::EstacionI(int id, const std::string& nombre, int segundos, int valor2, int medicionesSensor)
    : Maquina(id, nombre),
      segundosPorPieza(10),
      toleranciaMicras(50),
      sensor(medicionesSensor) {
    setSegundosPorPieza(segundos);
    setToleranciaMicras(valor2);
}

void EstacionI::setSegundosPorPieza(int segundos) {
    if (segundos > 0) {
        segundosPorPieza = segundos;
    } else {
        std::cout << "  [" << getNombre() << "] Segundos por pieza no valido: "
                  << segundos << "\n";
    }
}

void EstacionI::setToleranciaMicras(int valor) {
    if (valor > 0) {
        toleranciaMicras = valor;
    } else {
        std::cout << "  [" << getNombre() << "] Tolerancia de la medicion no valida: "
                  << valor << "\n";
    }
}

bool EstacionI::procesarPieza() {
    // Solo procesa si esta encendida y sin falla.
    if (!puedeProcesar()) {
        std::cout << "  [" << getNombre() << "] Rechaza la pieza ("
                  << (estaEncendida() ? "en falla" : "apagada") << ")\n";
        return false;
    }

    // Hace su trabajo y le avisa a la base.
    sensor.medir();
    registrarPieza();
    agregarTiempo(segundosPorPieza);
    std::cout << "  [" << getNombre() << "] Mide la pieza ("
              << segundosPorPieza << " s)\n";

    // Si esta pieza agoto el componente, la maquina entra en falla.
    if (sensor.perdioCalibracion()) {
        reportarFalla();
        std::cout << "  [" << getNombre() << "] FALLA: sensor descalibrado\n";
    }
    return true;
}

void EstacionI::darMantenimiento() {
    sensor.calibrar();
    registrarMantenimiento();
    std::cout << "  [" << getNombre() << "] Mantenimiento: sensor calibrado\n";
}

void EstacionI::mostrarEstado() const {
    Maquina::mostrarEstado();   // reutiliza la version de la base
    std::cout << "    Estacion de inspeccion: " << toleranciaMicras << " micras, "
              << segundosPorPieza << " s por pieza\n";
    sensor.mostrar();
}
