// Bloque 6 (equipo): Planta.

#include "Planta.h"

#include <iomanip>
#include <iostream>

Planta::Planta()
    : torno(nullptr),
      fresadora(nullptr),
      robot(nullptr),
      banda(nullptr),
      inspeccion(nullptr),
      piezasTerminadas(0) {
}

// ---- Registro (agregacion: solo se guarda el apuntador) ----

void Planta::registrarTorno(TornoCNC* maquina) {
    torno = maquina;
}

void Planta::registrarFresadora(Fresadora* maquina) {
    fresadora = maquina;
}

void Planta::registrarRobot(RobotSoldador* maquina) {
    robot = maquina;
}

void Planta::registrarBanda(BandaT* maquina) {
    banda = maquina;
}

void Planta::registrarInspeccion(EstacionI* maquina) {
    inspeccion = maquina;
}

// ---- Operacion ----

void Planta::encenderTodas() {
    torno->encender();
    fresadora->encender();
    robot->encender();
    banda->encender();
    inspeccion->encender();
}

void Planta::apagarTodas() {
    torno->apagar();
    fresadora->apagar();
    robot->apagar();
    banda->apagar();
    inspeccion->apagar();
}

bool Planta::procesarPieza() {
    // Estacion 1: Torno CNC
    if (torno->estaEnFalla()) {
        std::cout << "  >> Linea detenida: " << torno->getNombre() << " en falla\n";
        torno->darMantenimiento();
    }
    if (!torno->procesarPieza()) {
        return false;
    }

    // Estacion 2: Fresadora
    if (fresadora->estaEnFalla()) {
        std::cout << "  >> Linea detenida: " << fresadora->getNombre() << " en falla\n";
        fresadora->darMantenimiento();
    }
    if (!fresadora->procesarPieza()) {
        return false;
    }

    // Estacion 3: Robot soldador
    if (robot->estaEnFalla()) {
        std::cout << "  >> Linea detenida: " << robot->getNombre() << " en falla\n";
        robot->darMantenimiento();
    }
    if (!robot->procesarPieza()) {
        return false;
    }

    // Estacion 4: Banda transportadora
    if (banda->estaEnFalla()) {
        std::cout << "  >> Linea detenida: " << banda->getNombre() << " en falla\n";
        banda->darMantenimiento();
    }
    if (!banda->procesarPieza()) {
        return false;
    }

    // Estacion 5: Estacion de inspeccion
    if (inspeccion->estaEnFalla()) {
        std::cout << "  >> Linea detenida: " << inspeccion->getNombre() << " en falla\n";
        inspeccion->darMantenimiento();
    }
    if (!inspeccion->procesarPieza()) {
        return false;
    }

    piezasTerminadas++;
    return true;
}

void Planta::procesarLote(int cantidad) {
    for (int i = 1; i <= cantidad; i++) {
        std::cout << "Pieza " << i << ":\n";
        if (!procesarPieza()) {
            std::cout << "  >> No se pudo completar la pieza " << i
                      << ". Se detiene el lote.\n";
            return;
        }
    }
}

void Planta::generarReporte() const {
    // Las cinco maquinas en orden. Como arreglo de Maquina* solo se usan
    // los metodos de la base (nombre, piezas, tiempo, paros, falla).
    const Maquina* maquinas[5] = {torno, fresadora, robot, banda, inspeccion};

    int tiempoTotal = 0;
    int parosTotal = 0;
    for (int i = 0; i < 5; i++) {
        tiempoTotal += maquinas[i]->getTiempoTrabajado();
        parosTotal += maquinas[i]->getParos();
    }

    std::cout << "=== Reporte del turno ===\n"
              << "Piezas terminadas: " << piezasTerminadas << "\n"
              << "Tiempo total: " << tiempoTotal << " s\n"
              << "Paros por mantenimiento: " << parosTotal << "\n";

    for (int i = 0; i < 5; i++) {
        const Maquina* m = maquinas[i];
        // Nombre + espacio + puntos hasta la columna 26.
        std::cout << "  " << std::left << std::setfill('.') << std::setw(26)
                  << (m->getNombre() + " ") << std::setfill(' ') << " "
                  << m->getPiezasProcesadas() << " piezas, "
                  << m->getParos() << (m->getParos() == 1 ? " paro, " : " paros, ")
                  << (m->estaEnFalla() ? "en falla" : "sin falla") << "\n";
    }
}
