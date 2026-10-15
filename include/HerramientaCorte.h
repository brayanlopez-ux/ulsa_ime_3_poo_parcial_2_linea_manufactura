#ifndef HERRAMIENTACORTE_H
#define HERRAMIENTACORTE_H

// Componente de la Fresadora: la herramienta de corte.
//
// Desgaste: cada uso gasta 1 de la vida util (medida en piezas).
// Cuando se gasta toda, el componente llego a su limite y la maquina
// que lo contiene entra en falla.
class HerramientaCorte {
private:
    int vidaUtil;   // piezas que aguanta (> 0)
    int usos;       // piezas desde que es nuevo

public:
    // Si vida <= 0 se usan 20 y se avisa en pantalla.
    HerramientaCorte(int vida);

    void desgastar();      // suma un uso
    bool estaDesgastada() const; // true si ya llego a su limite
    void afilar();     // lo deja como nuevo
    void mostrar() const;
};

#endif
