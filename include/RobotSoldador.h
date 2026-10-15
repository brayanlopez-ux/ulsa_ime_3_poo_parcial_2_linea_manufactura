#ifndef ROBOTSOLDADOR_H
#define ROBOTSOLDADOR_H

#include <string>

#include "Antorcha.h"
#include "Maquina.h"

// Robot soldador: suelda la pieza.
//  - Herencia: RobotSoldador ES una Maquina.
//  - Composicion: RobotSoldador TIENE un componente Antorcha (lo crea y lo destruye ella).
class RobotSoldador : public Maquina {
private:
    int segundosPorPieza;   // tiempo por pieza (> 0)
    int corrienteAmperes;   // corriente de soldadura (> 0)
    Antorcha antorcha;

public:
    RobotSoldador(int id, const std::string& nombre, int segundos, int valor2, int vidaAntorcha);

    // Validan antes de asignar; si el valor no es valido, no lo cambian.
    void setSegundosPorPieza(int segundos);
    void setCorrienteAmperes(int valor);

    // Procesa UNA pieza. Devuelve false si la rechaza (apagada o en falla).
    // Si esta pieza agota el componente, la maquina entra en falla.
    bool procesarPieza();

    // Restaura el componente, quita la falla y cuenta un paro.
    void darMantenimiento();

    // Redefine el de Maquina: reutiliza la version base y agrega lo suyo.
    void mostrarEstado() const;
};

#endif
