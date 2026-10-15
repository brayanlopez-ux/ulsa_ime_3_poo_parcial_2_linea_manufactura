#include "Fresadora.h"

#include <iostream>

Fresadora::Fresadora(int id, const std::string& nombre, int segundos, int valor2, int vidaHerramienta)
    : Maquina(id, nombre),
      segundosPorPieza(45),
      profundidadMm(5),
      herramienta(vidaHerramienta) {
    setSegundosPorPieza(segundos);
    setProfundidadMm(valor2);
}

void Fresadora::setSegundosPorPieza(int segundos) {
    if (segundos > 0) {
        segundosPorPieza = segundos;
    } else {
        std::cout << "  [" << getNombre() << "] Segundos por pieza no valido: "
                  << segundos << "\n";
    }
}

void Fresadora::setProfundidadMm(int valor) {
    if (valor > 0) {
        profundidadMm = valor;
    } else {
        std::cout << "  [" << getNombre() << "] Profundidad de la ranura no valida: "
                  << valor << "\n";
    }
}

bool Fresadora::procesarPieza() {
    // Solo procesa si esta encendida y sin falla.
    if (!puedeProcesar()) {
        std::cout << "  [" << getNombre() << "] Rechaza la pieza ("
                  << (estaEncendida() ? "en falla" : "apagada") << ")\n";
        return false;
    }

    // Hace su trabajo y le avisa a la base.
    herramienta.desgastar();
    registrarPieza();
    agregarTiempo(segundosPorPieza);
    std::cout << "  [" << getNombre() << "] Ranura la pieza ("
              << segundosPorPieza << " s)\n";

    // Si esta pieza agoto el componente, la maquina entra en falla.
    if (herramienta.estaDesgastada()) {
        reportarFalla();
        std::cout << "  [" << getNombre() << "] FALLA: herramienta de corte desgastada\n";
    }
    return true;
}

void Fresadora::darMantenimiento() {
    herramienta.afilar();
    registrarMantenimiento();
    std::cout << "  [" << getNombre() << "] Mantenimiento: herramienta nueva\n";
}

void Fresadora::mostrarEstado() const {
    Maquina::mostrarEstado();   // reutiliza la version de la base
    std::cout << "    Fresadora: " << profundidadMm << " mm, "
              << segundosPorPieza << " s por pieza\n";
    herramienta.mostrar();
}
