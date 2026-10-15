// Bloque 0 (equipo): implementación de la clase base Maquina.

#include "Maquina.h"

#include <iostream>

// La lista de inicialización respeta el orden en que se declaran los
// atributos en Maquina.h (si no, -Wall -Wextra avisa con -Wreorder).
Maquina::Maquina(int id, const std::string& nombre)
    : id(id),
      nombre(nombre),
      encendida(false),
      enFalla(false),
      piezasProcesadas(0),
      tiempoTrabajado(0),
      paros(0) {
}

// ---- Métodos protegidos: los usan las clases derivadas ----

void Maquina::registrarPieza() {
    piezasProcesadas++;
}

void Maquina::agregarTiempo(int segundos) {
    if (segundos < 0) {
        std::cout << "  [" << nombre << "] Tiempo negativo rechazado: "
                  << segundos << " s\n";
        return;
    }
    tiempoTrabajado += segundos;
}

void Maquina::reportarFalla() {
    enFalla = true;
}

void Maquina::registrarMantenimiento() {
    enFalla = false;
    paros++;
}

// ---- Métodos públicos ----

void Maquina::encender() {
    encendida = true;   // encender NO quita la falla
}

void Maquina::apagar() {
    encendida = false;
}

bool Maquina::estaEncendida() const {
    return encendida;
}

bool Maquina::estaEnFalla() const {
    return enFalla;
}

bool Maquina::puedeProcesar() const {
    return encendida && !enFalla;
}

int Maquina::getId() const {
    return id;
}

std::string Maquina::getNombre() const {
    return nombre;
}

int Maquina::getPiezasProcesadas() const {
    return piezasProcesadas;
}

int Maquina::getTiempoTrabajado() const {
    return tiempoTrabajado;
}

int Maquina::getParos() const {
    return paros;
}

void Maquina::mostrarEstado() const {
    std::cout << "[" << id << "] " << nombre << "\n"
              << "    Estado: " << (encendida ? "encendida" : "apagada")
              << ", " << (enFalla ? "EN FALLA" : "sin falla") << "\n"
              << "    Piezas procesadas: " << piezasProcesadas << "\n"
              << "    Tiempo trabajado: " << tiempoTrabajado << " s\n"
              << "    Paros (mantenimientos): " << paros << "\n";
}
