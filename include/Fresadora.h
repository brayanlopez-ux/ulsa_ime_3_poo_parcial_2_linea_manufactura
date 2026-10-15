#ifndef FRESADORA_H
#define FRESADORA_H

#include <string>

#include "HerramientaCorte.h"
#include "Maquina.h"

// Fresadora: ranura la pieza.
//  - Herencia: Fresadora ES una Maquina.
//  - Composicion: Fresadora TIENE un componente HerramientaCorte (lo crea y lo destruye ella).
class Fresadora : public Maquina {
private:
    int segundosPorPieza;   // tiempo por pieza (> 0)
    int profundidadMm;   // profundidad de la ranura (> 0)
    HerramientaCorte herramienta;

public:
    Fresadora(int id, const std::string& nombre, int segundos, int valor2, int vidaHerramienta);

    // Validan antes de asignar; si el valor no es valido, no lo cambian.
    void setSegundosPorPieza(int segundos);
    void setProfundidadMm(int valor);

    // Procesa UNA pieza. Devuelve false si la rechaza (apagada o en falla).
    // Si esta pieza agota el componente, la maquina entra en falla.
    bool procesarPieza();

    // Restaura el componente, quita la falla y cuenta un paro.
    void darMantenimiento();

    // Redefine el de Maquina: reutiliza la version base y agrega lo suyo.
    void mostrarEstado() const;
};

#endif
