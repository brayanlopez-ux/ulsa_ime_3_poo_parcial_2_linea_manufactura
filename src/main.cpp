// Proyecto Parcial 2: Simulador de una Planta de Manufactura Automatizada
//
// Programa principal del equipo (bloque 6).
// La guia completa esta en PROYECTO.md, seccion 2.5.
//
// Compilar:
//   g++ -Wall -Wextra -std=c++17 -Iinclude src/*.cpp -o planta
// Ejecutar:
//   ./planta

#include <iostream>

#include "../include/BandaT.h"
#include "../include/EstacionI.h"
#include "../include/Fresadora.h"
#include "../include/Planta.h"
#include "../include/RobotSoldador.h"
#include "../include/TornoCNC.h"

int main() {
    // 1. Crear las maquinas y registrarlas en la planta.
    //    Las maquinas viven aqui en main; la planta solo guarda apuntadores.
    //    Parametros: id, nombre, segundos por pieza, dato propio, limite del
    //    componente (en piezas, o mediciones para el sensor).
    TornoCNC torno(1, "Torno CNC", 30, 1500, 9);
    Fresadora fresadora(2, "Fresadora", 45, 5, 25);
    RobotSoldador robot(3, "Robot soldador", 25, 200, 15);
    BandaT banda(4, "Banda transportadora", 5, 200, 50);
    EstacionI inspeccion(5, "Estacion de inspeccion", 12, 50, 30);

    Planta planta;
    planta.registrarTorno(&torno);
    planta.registrarFresadora(&fresadora);
    planta.registrarRobot(&robot);
    planta.registrarBanda(&banda);
    planta.registrarInspeccion(&inspeccion);

    // 2. Intentar procesar una pieza con las maquinas apagadas,
    //    para mostrar el rechazo.
    std::cout << "=== Intento con las maquinas apagadas ===\n";
    planta.procesarLote(1);

    // 3. Encender todas las maquinas.
    std::cout << "\n=== Encendiendo la linea ===\n";
    planta.encenderTodas();

    // 4. Procesar un lote de 20 piezas.
    std::cout << "\n=== Procesando un lote de 20 piezas ===\n";
    planta.procesarLote(20);

    // 5. Mostrar el reporte del turno y apagar.
    std::cout << "\n";
    planta.generarReporte();

    std::cout << "\n=== Estado final de cada maquina ===\n";
    torno.mostrarEstado();
    fresadora.mostrarEstado();
    robot.mostrarEstado();
    banda.mostrarEstado();
    inspeccion.mostrarEstado();

    planta.apagarTodas();
    return 0;
}
