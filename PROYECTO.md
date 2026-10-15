# Proyecto Parcial 2: Simulador de una Planta de Manufactura Automatizada

**Materia:** Programación Orientada a Objetos

**Alcance:** Unidades I a III

**Repositorio base:** https://github.com/narizwallace/ulsa_ime_3_poo_parcial_2_linea_manufactura

**Entrega:** jueves 15 de octubre, 11:59 PM, en Classroom

**Exposición:** viernes 16 de octubre

## 1. Objetivo

Diseñar, programar y documentar en C++ una simulación de una línea de manufactura, aplicando herencia, composición y agregación.

El equipo responde por la solución completa. Cada integrante responde por su propia clase, de principio a fin: la diseña, la programa, la documenta y la expone.

## 2. El problema

Una empresa fabrica soportes metálicos en una línea de cinco estaciones. Cada pieza pasa por las cinco, siempre en el mismo orden. El programa simula un turno de trabajo: procesa un lote de piezas, detecta cuándo una máquina falla, le da mantenimiento y al final entrega un reporte del turno.

La simulación es determinista (sin números aleatorios), para que el resultado se pueda calcular a mano y comprobar.

Los equipos son de cinco o de seis integrantes, y la línea tiene una estación por integrante: cinco estaciones en un equipo de cinco, seis en un equipo de seis.

### 2.1 Lo que toda máquina hace

1. Tiene identificador y nombre, y puede estar apagada, encendida o en falla.
2. Solo procesa piezas si está encendida y sin falla. Si no, rechaza la operación con un mensaje.
3. Lleva la cuenta de las piezas procesadas, del tiempo trabajado y de sus paros.
4. Puede mostrar su estado en pantalla.

### 2.2 Lo que cada máquina agrega

1. **Operación propia:** al procesar una pieza hace su trabajo y tarda un tiempo propio, en segundos por pieza.
2. **Componente con desgaste:** tiene un componente que pierde vida útil con cada pieza.
3. **Falla:** cuando el componente llega a su límite, la máquina entra en falla y deja de procesar.
4. **Mantenimiento:** una operación que restaura el componente y quita la falla, y que cuenta como un paro.
5. **Estado completo:** muestra los datos generales de la máquina, los suyos y los de su componente.

### 2.3 Catálogo de máquinas

| Máquina | Operación | Componente que se desgasta |
| --- | --- | --- |
| Torno CNC | Cilindrar la pieza | Husillo |
| Fresadora | Ranurar | Herramienta de corte |
| Robot soldador | Soldar | Antorcha (alambre) |
| Banda transportadora | Trasladar a la siguiente estación | Motor |
| Estación de inspección | Medir la pieza | Sensor (calibración) |
| Cortadora láser | Cortar el perfil | Lente |
| Prensa | Doblar | Troquel |
| Impresora 3Dw | Imprimir un inserto | Extrusor (filamento) |

El equipo elige sus máquinas de este catálogo o propone otras. Qué atributos y métodos lleva cada clase, y cómo se modela el desgaste, lo decide cada responsable y lo justifica en su documentación.

### 2.4 Lo que hace la planta

- Conoce las máquinas de la línea, que se crean fuera de ella, y su orden.
- Procesa un lote: cada pieza pasa por todas las estaciones en orden.
- Si una máquina está en falla, la línea se detiene, se le da mantenimiento y la pieza continúa.
- Al terminar genera el reporte del turno.

### 2.5 Escenario obligatorio de `main`

1. Crear las máquinas y registrarlas en la planta.
2. Intentar procesar una pieza con las máquinas apagadas, para mostrar el rechazo.
3. Encender todas las máquinas.
4. Procesar un lote de 20 piezas. Los límites de desgaste se eligen de modo que al menos dos máquinas fallen durante el lote.
5. Mostrar el reporte del turno y apagar.

El reporte debe incluir piezas terminadas, tiempo total, paros por máquina y el estado final de cada una. Por ejemplo:

```
=== Reporte del turno ===
Piezas terminadas: 20
Tiempo total: 2200 s
Paros por mantenimiento: 3
  Torno CNC ................ 20 piezas, 2 paros, sin falla
  Fresadora ................ 20 piezas, 0 paros, sin falla
  Robot soldador ........... 20 piezas, 1 paro, sin falla
  Banda transportadora ..... 20 piezas, 0 paros, sin falla
  Estación de inspección ... 20 piezas, 0 paros, sin falla
```

## 3. Bloques y responsables

| Bloque | Responsable | Contenido | Relación que practica |
| --- | --- | --- | --- |
| 0 | Equipo | Implementar `Maquina.cpp` a partir de `Maquina.h` | Clase base |
| 1 a 5 | Un integrante por bloque | Una máquina derivada y su componente | Herencia y composición |
| 6 | Equipo | `Planta` y `main` | Agregación e integración |

> **Importante:** en el equipo de seis integrantes hay un bloque individual más.

### 3.1 Contrato mínimo de cada bloque individual

- La clase hereda de `Maquina` y su constructor invoca al de la base con lista de inicialización.
- Tiene al menos dos atributos propios, con validación.
- Tiene al menos dos métodos propios que la base no tiene.
- Redefine al menos un método de la base y reutiliza la versión base dentro de la suya.
- Contiene por composición un componente escrito por el mismo integrante, como clase independiente.
- Los archivos van en `include/` y `src/`, con los miembros privados primero.

### 3.2 Bloques de equipo

- `Maquina.h` no se modifica sin acuerdo del equipo. Cualquier cambio se documenta en el `README.md`.
- `Planta` guarda apuntadores a las máquinas creadas en `main` (agregación).
- `Maquina.cpp`, `Planta` y `main.cpp` deben tener aportaciones de todos los integrantes. Cada quien integra su propia máquina.

## 4. Entregables

| Entregable | Responsable | Ubicación |
| --- | --- | --- |
| Máquina derivada y su componente | Individual | `include/`, `src/` |
| Documentación y diagrama de su clase | Individual | `docs/<Clase>.md` |
| Propuesta de mejora | Individual | `docs/mejoras/<matrícula>/` |
| `Maquina.cpp`, `Planta`, `main` | Equipo | `src/`, `include/` |
| Diagrama general y README | Equipo | `README.md`, `docs/` |
| Cálculo a mano del reporte | Equipo | `README.md` |

### 4.1 Documentación individual

Se crea a partir de `docs/PLANTILLA_CLASE.md` y contiene:

- Propósito de la clase y de su componente.
- Decisiones de diseño: atributos, métodos, cómo se modela el desgaste y por qué.
- Diagrama de la clase y su componente, hecho en draw.io.
- Bitácora de dudas y errores encontrados.

### 4.2 Propuesta de mejora (individual)

Cada integrante entrega una propuesta para mejorar o corregir la solución que construyó el equipo. Es solo diseño: no se programa.

Dónde y cómo se entrega:

- Cada integrante crea una carpeta dentro de `docs/mejoras/` cuyo nombre es su número de matrícula, por ejemplo `docs/mejoras/123456/`.
- Dentro de esa carpeta van el documento de mejora (`mejora.md`) y la imagen de su diagrama.
- El documento se crea copiando la plantilla `docs/mejoras/PLANTILLA_MEJORA.md`, incluida en el repositorio base.
- El documento debe incluir el nombre del autor con la etiqueta **"Propuesta de mejora elaborada por: "**.

El documento contiene como mínimo:

1. **Impacto.** Qué mejora o qué corrige del proceso actual y por qué vale la pena. Debe decir si es una mejora (algo que la planta hoy no hace) o una corrección (algo que hace mal o de forma limitada), y partir de una observación concreta sobre la solución del equipo.
2. **Qué implica.** Los cambios necesarios en el diseño: clases nuevas, comportamiento nuevo en clases existentes, interacciones nuevas entre objetos, o relaciones nuevas de herencia, composición o agregación. Cada relación nueva se justifica.
3. **Diagrama de clases.** Hecho en draw.io, muestra la solución con la mejora incorporada y distingue lo nuevo de lo existente. Sin implementación.

Reglas:

- Dentro de un equipo no puede haber dos propuestas iguales.
- La propuesta puede tocar cualquier parte de la solución, no solo la clase propia.
- Debe resolverse con temas de las Unidades I a III.

### 4.3 Cálculo a mano del reporte (equipo)

Como la simulación no usa números aleatorios, el reporte del turno se puede predecir antes de ejecutar el programa. El equipo hace esa predicción en una tabla dentro del `README.md`, y debe coincidir con lo que imprime el programa.

La tabla incluye una fila por cada máquina de la línea, con los valores que el equipo eligió. El siguiente ejemplo corresponde al reporte de la sección 2.5, con un lote de 20 piezas:

| Máquina | Segundos por pieza | Límite del componente | Fallas en 20 piezas | Tiempo trabajado |
| --- | --- | --- | --- | --- |
| Torno CNC | 30 | 8 piezas | 2 (después de las piezas 8 y 16) | 20 × 30 = 600 s |
| Fresadora | 45 | 25 piezas | 0 | 20 × 45 = 900 s |
| Robot soldador | 20 | 12 piezas | 1 (después de la pieza 12) | 20 × 20 = 400 s |
| Banda transportadora | 5 | 50 piezas | 0 | 20 × 5 = 100 s |
| Estación de inspección | 10 | 30 piezas | 0 | 20 × 10 = 200 s |

De esa tabla se deduce el reporte esperado: 20 piezas terminadas, 2200 s de trabajo y 3 paros (2 del torno y 1 del robot soldador). En este ejemplo el mantenimiento no suma tiempo al turno. Si el programa imprime otra cosa, hay un error en el código o en la forma en que el equipo entendió su propia regla de desgaste.

Para hacer el cálculo, el equipo debe dejar por escrito sus reglas:

- En qué momento exacto falla una máquina: al procesar la pieza que agota el componente, o al intentar la siguiente.
- Si el mantenimiento suma tiempo al turno, y cuánto.

Los números del ejemplo son ilustrativos; cada equipo usa los suyos.

## 5. Repositorio base

El repositorio base es un punto de partida. No incluye archivos de las clases que el equipo debe crear.

**https://github.com/narizwallace/ulsa_ime_3_poo_parcial_2_linea_manufactura**

El equipo debe hacer **fork** de este repositorio y trabajar sobre su fork.

| Archivo | Contenido |
| --- | --- |
| `PROYECTO.md` | Esta guía |
| `README.md` | Plantilla del equipo: integrantes, asignación de bloques, cómo compilar, diagrama general, cálculo a mano |
| `include/Maquina.h` | Interfaz de la clase base, sin implementación |
| `src/main.cpp` | Esqueleto del programa principal, con los pasos del escenario |
| `docs/PLANTILLA_CLASE.md` | Plantilla de la documentación individual |
| `docs/mejoras/PLANTILLA_MEJORA.md` | Plantilla de la propuesta de mejora |
| `.gitignore`, `.vscode/settings.json` | Configuración del entorno |

`Maquina.h` declara:

- Constructor con identificador y nombre.
- `encender()`, `apagar()`, `estaEncendida()`, `estaEnFalla()`, `puedeProcesar()`.
- `registrarPieza()`: suma una pieza procesada.
- `agregarTiempo(segundos)`: acumula el tiempo trabajado. Cada máquina derivada lo llama con su propio tiempo por pieza.
- `reportarFalla()`, `registrarMantenimiento()`.

Los cuatro métodos anteriores son protegidos: los usan las clases derivadas para avisarle a la base lo que ocurrió.
- Accesores de piezas procesadas, tiempo trabajado y paros.
- `mostrarEstado()`.

## 6. Colaboración en GitHub

- Un integrante hace fork del repositorio base y agrega a los demás como colaboradores. Hay un solo repositorio por equipo.
- Cada quien hace commits desde su propia cuenta, con su nombre y correo configurados en git. La autoría se revisa con git-fame.
- Los archivos de un bloque individual solo los modifica su responsable.
- Un bloque sin commits de su responsable no recibe la calificación individual.

## 7. Entrega

- La fecha límite es el **jueves 15 de octubre a las 11:59 PM**. Los commits posteriores no se toman en cuenta.
- **Todos** los integrantes deben entregar en Classroom, de forma individual, el enlace al repositorio de su equipo.
- Quien no entregue en Classroom tendrá una **penalización de 10 puntos**.

## 8. Exposición

- Cada integrante presenta su clase: diseño y código, y la muestra funcionando dentro del escenario del equipo.
- Cada integrante responde una pregunta sobre la clase de un compañero.
- Cada integrante cierra con su propuesta de mejora.
- El equipo ejecuta el escenario completo y explica el reporte.

## 9. Evaluación

| Individual (60) | Puntos |
| --- | --- |
| Código de su clase y componente | 30 |
| Documentación y diagrama | 10 |
| Propuesta de mejora | 10 |
| Exposición | 10 |

| Equipo (40) | Puntos |
| --- | --- |
| Integración: escenario completo y correcto | 25 |
| Diagrama general y README | 10 |
| Cálculo a mano que coincide con el reporte | 5 |

> **Importante:** no entregar en Classroom resta 10 puntos a la calificación del integrante.

## 10. Criterios de aceptación

- El proyecto compila sin advertencias con `-Wall -Wextra -std=c++17`.
- El escenario corre completo y el reporte coincide con el cálculo a mano.
- Cada integrante tiene su código, su documentación con diagrama y su propuesta de mejora en el repositorio, con commits propios.
