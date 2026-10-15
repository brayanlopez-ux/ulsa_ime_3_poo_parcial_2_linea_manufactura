#ifndef SENSOR_H
#define SENSOR_H

// Componente de Estacion de inspeccion: el sensor (calibracion).
//
// Desgaste: cada uso gasta 1 de la vida util (medida en mediciones).
// Cuando se gasta toda, el componente llego a su limite y la maquina
// que lo contiene entra en falla.
class Sensor {
private:
    int vidaUtil;   // mediciones que aguanta (> 0)
    int usos;       // mediciones desde que es nuevo

public:
    // Si vida <= 0 se usan 30 y se avisa en pantalla.
    Sensor(int vida);

    void medir();      // suma un uso
    bool perdioCalibracion() const; // true si ya llego a su limite
    void calibrar();     // lo deja como nuevo
    void mostrar() const;
};

#endif
