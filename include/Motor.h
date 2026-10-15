#ifndef MOTOR_H
#define MOTOR_H

// Componente de Banda transportadora: el motor.
//
// Desgaste: cada uso gasta 1 de la vida util (medida en piezas).
// Cuando se gasta toda, el componente llego a su limite y la maquina
// que lo contiene entra en falla.
class Motor {
private:
    int vidaUtil;   // piezas que aguanta (> 0)
    int usos;       // piezas desde que es nuevo

public:
    // Si vida <= 0 se usan 50 y se avisa en pantalla.
    Motor(int vida);

    void desgastar();      // suma un uso
    bool estaDesgastado() const; // true si ya llego a su limite
    void reparar();     // lo deja como nuevo
    void mostrar() const;
};

#endif
