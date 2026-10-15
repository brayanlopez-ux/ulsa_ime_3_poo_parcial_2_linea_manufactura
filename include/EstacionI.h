#ifndef ESTACIONI_H
#define ESTACIONI_H

#include <string>

#include "Sensor.h"
#include "Maquina.h"

// Estacion de inspeccion: mide la pieza.
//  - Herencia: EstacionI ES una Maquina.
//  - Composicion: EstacionI TIENE un componente Sensor (lo crea y lo destruye ella).
class EstacionI : public Maquina {
private:
    int segundosPorPieza;   // tiempo por pieza (> 0)
    int toleranciaMicras;   // tolerancia de la medicion (> 0)
    Sensor sensor;

public:
    EstacionI(int id, const std::string& nombre, int segundos, int valor2, int medicionesSensor);

    // Validan antes de asignar; si el valor no es valido, no lo cambian.
    void setSegundosPorPieza(int segundos);
    void setToleranciaMicras(int valor);

    // Procesa UNA pieza. Devuelve false si la rechaza (apagada o en falla).
    // Si esta pieza agota el componente, la maquina entra en falla.
    bool procesarPieza();

    // Restaura el componente, quita la falla y cuenta un paro.
    void darMantenimiento();

    // Redefine el de Maquina: reutiliza la version base y agrega lo suyo.
    void mostrarEstado() const;
};

#endif
