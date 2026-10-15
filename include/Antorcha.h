#ifndef ANTORCHA_H
#define ANTORCHA_H

// Componente de Robot soldador: la antorcha (con su alambre).
//
// Desgaste: cada uso gasta 1 de la vida util (medida en piezas).
// Cuando se gasta toda, el componente llego a su limite y la maquina
// que lo contiene entra en falla.
class Antorcha {
private:
    int vidaUtil;   // piezas que aguanta (> 0)
    int usos;       // piezas desde que es nuevo

public:
    // Si vida <= 0 se usan 15 y se avisa en pantalla.
    Antorcha(int vida);

    void desgastar();      // suma un uso
    bool estaDesgastada() const; // true si ya llego a su limite
    void cambiarAlambre();     // lo deja como nuevo
    void mostrar() const;
};

#endif
