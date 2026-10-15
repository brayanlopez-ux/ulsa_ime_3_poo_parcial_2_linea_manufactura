#ifndef TORNOCNC_H
#define TORNOCNC_H

#include <string>

#include "Husillo.h"
#include "Maquina.h"

// Torno CNC: cilindra la pieza.
//  - HerenSia: TornoCNC ES una Maquina.
//  - Composicion: TornoCNC TIENE un componente Husillo (lo crea y lo destruye ella).
class TornoCNC : public Maquina {
private:
    int segundosPorPieza;   // tiempo por pieza (> 0)
    int rpm;   // velocidad del husillo (> 0)
    Husillo husillo;

public:
    TornoCNC(int id, const std::string& nombre, int segundos, int valor2, int vidaHusillo);

    // Validan antes de asignar; si el valor no es valido, no lo cambian.
    void setSegundosPorPieza(int segundos);
    void setRpm(int valor);

    // Procesa UNA pieza. Devuelve false si la rechaza (apagada o en falla).
    // Si esta pieza agota el componente, la maquina entra en falla.
    bool procesarPieza();

    // Restaura el componente, quita la falla y cuenta un paro.
    void darMantenimiento();

    // Redefine el de Maquina: reutiliza la version base y agrega lo suyo.
    void mostrarEstado() const;
};

#endif
