#ifndef BANDAT_H
#define BANDAT_H

#include <string>

#include "Motor.h"
#include "Maquina.h"

// Banda transportadora: traslada la pieza a la siguiente estacion.
//  - Herencia: BandaT ES una Maquina.
//  - Composicion: BandaT TIENE un componente Motor (lo crea y lo destruye ella).
class BandaT : public Maquina {
private:
    int segundosPorPieza;   // tiempo por pieza (> 0)
    int velocidadMmS;   // velocidad de la banda (> 0)
    Motor motor;

public:
    BandaT(int id, const std::string& nombre, int segundos, int valor2, int vidaMotor);

    // Validan antes de asignar; si el valor no es valido, no lo cambian.
    void setSegundosPorPieza(int segundos);
    void setVelocidadMmS(int valor);

    // Procesa UNA pieza. Devuelve false si la rechaza (apagada o en falla).
    // Si esta pieza agota el componente, la maquina entra en falla.
    bool procesarPieza();

    // Restaura el componente, quita la falla y cuenta un paro.
    void darMantenimiento();

    // Redefine el de Maquina: reutiliza la version base y agrega lo suyo.
    void mostrarEstado() const;
};

#endif
