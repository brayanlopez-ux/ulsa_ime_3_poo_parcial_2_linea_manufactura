#ifndef PLANTA_H
#define PLANTA_H

#include "BandaT.h"
#include "EstacionI.h"
#include "Fresadora.h"
#include "RobotSoldador.h"
#include "TornoCNC.h"

// Planta (bloque 6, equipo): conoce las maquinas de la linea y las hace
// trabajar en orden.
//
// AGREGACION: la Planta guarda APUNTADORES a maquinas que se crean fuera de
// ella (en main). No las crea ni las destruye.
//
// Orden de la linea: Torno CNC -> Fresadora -> Robot soldador ->
// Banda transportadora -> Estacion de inspeccion.
class Planta {
private:
    TornoCNC* torno;
    Fresadora* fresadora;
    RobotSoldador* robot;
    BandaT* banda;
    EstacionI* inspeccion;
    int piezasTerminadas;

    // Pasa UNA pieza por las cinco estaciones. Si una maquina esta en falla,
    // detiene la linea, le da mantenimiento y la pieza continua.
    // Devuelve false si alguna maquina rechaza la pieza (por ejemplo, apagada).
    bool procesarPieza();

public:
    Planta();

    void registrarTorno(TornoCNC* maquina);
    void registrarFresadora(Fresadora* maquina);
    void registrarRobot(RobotSoldador* maquina);
    void registrarBanda(BandaT* maquina);
    void registrarInspeccion(EstacionI* maquina);

    void encenderTodas();
    void apagarTodas();

    // Procesa un lote de piezas. Se detiene si una pieza es rechazada.
    void procesarLote(int cantidad);

    // Imprime el reporte del turno.
    void generarReporte() const;
};

#endif
