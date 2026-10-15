#include "BandaT.h"

#include <iostream>

BandaT::BandaT(int id, const std::string& nombre, int segundos, int valor2, int vidaMotor)
    : Maquina(id, nombre),
      segundosPorPieza(5),
      velocidadMmS(200),
      motor(vidaMotor) {
    setSegundosPorPieza(segundos);
    setVelocidadMmS(valor2);
}

void BandaT::setSegundosPorPieza(int segundos) {
    if (segundos > 0) {
        segundosPorPieza = segundos;
    } else {
        std::cout << "  [" << getNombre() << "] Segundos por pieza no valido: "
                  << segundos << "\n";
    }
}

void BandaT::setVelocidadMmS(int valor) {
    if (valor > 0) {
        velocidadMmS = valor;
    } else {
        std::cout << "  [" << getNombre() << "] Velocidad de la banda no valida: "
                  << valor << "\n";
    }
}

bool BandaT::procesarPieza() {
    // Solo procesa si esta encendida y sin falla.
    if (!puedeProcesar()) {
        std::cout << "  [" << getNombre() << "] Rechaza la pieza ("
                  << (estaEncendida() ? "en falla" : "apagada") << ")\n";
        return false;
    }

    // Hace su trabajo y le avisa a la base.
    motor.desgastar();
    registrarPieza();
    agregarTiempo(segundosPorPieza);
    std::cout << "  [" << getNombre() << "] Traslada la pieza a la siguiente estacion ("
              << segundosPorPieza << " s)\n";

    // Si esta pieza agoto el componente, la maquina entra en falla.
    if (motor.estaDesgastado()) {
        reportarFalla();
        std::cout << "  [" << getNombre() << "] FALLA: motor desgastado\n";
    }
    return true;
}

void BandaT::darMantenimiento() {
    motor.reparar();
    registrarMantenimiento();
    std::cout << "  [" << getNombre() << "] Mantenimiento: motor reparado\n";
}

void BandaT::mostrarEstado() const {
    Maquina::mostrarEstado();   // reutiliza la version de la base
    std::cout << "    Banda transportadora: " << velocidadMmS << " mm/s, "
              << segundosPorPieza << " s por pieza\n";
    motor.mostrar();
}
