# ♟️ Simulador del juego del Ajedrez
Simulación del juego del ajedrez en C++, jugable mediante terminal.

---

## Índice
1. [Tablero](#id1)
2. [Muestra del tablero](#id2)
3. [Movimiento](#id3)
4. [Fichas](#id4)
5. [Juego](#id5)
6. [Repositorio](#id6)
7. [Creditos](#id7)
8. [Licencia](#id8)

---

## ⬜⬛ Tablero <a name="id1"></a>

- Generación de un tablero.
- Colocación de fichas en posición inicial

[▲ Volver al índice](#índice)

---

## Muestra de la inicialización del tablero <a name="id2"></a>
![Muestra de la inicialización del tablero generado](/tablero.png) ![Muestra de un tablero real](/tableroreal.png)

[▲ Volver al índice](#índice)

---

## 🔛 Movimiento <a name="id3"></a>

- Los jugadores alternan su turno. Tal y como en el juego original sacan simpre las blancas.
- Si el movimiento no es válido, se le indica al usuario y permitirá un nuevo movimiento.

[▲ Volver al índice](#índice)

---

## Fichas <a name="id4"></a>

| Nombre    | Cantidad (por jugador) | Movimiento                  | Elimina                              |
|-----------|------------------------|-----------------------------|--------------------------------------|
| Peón      | 8                      | 1 casilla adelante (2 en primer movimiento) | Diagonal adelante (1 casilla) |
| Torre     | 2                      | Horizontal/Vertical (ilimitado) | Igual que movimiento               |
| Caballo   | 2                      | En "L" (2+1 casillas)       | Igual que movimiento               |
| Alfil     | 2                      | Diagonal (ilimitado)        | Igual que movimiento               |
| Reina     | 1                      | Horizontal/Vertical/Diagonal (ilimitado) | Igual que movimiento    |
| Rey       | 1                      | 1 casilla en cualquier dirección | Igual que movimiento          |

[▲ Volver al índice](#índice)

---

## 🏁 Juego <a name="id5"></a>

- El juego pedirá al usuario que ingrese la posición y el movimiento que va a realizar: ej. a2 a3.
- La ficha se mueve sí, puede avanzar y/o matar a otra ficha.

[▲ Volver al índice](#índice)

---

## 📁 Repositorio <a name="id6"></a>

El repositorio contiene:
```text
ajedrez/
├── 📁 Archivos de encabezado/
│   ├── 📄 const.h
│   └── 📄 logica.h
│
├── 📁 Archivos de origen/
│   ├── 📄 const.cpp
│   ├── 📄 juego.cpp
│   ├── 📄 main.cpp
│   ├── 📄 movimiento.cpp
│   └── 📄 tablero.cpp
│
└── 📁 Otros archivos de configuración
```

[▲ Volver al índice](#índice)

---

## 📚 Creditos <a name="id7"></a>

Practica realitzada por:

- Lluc Omella
- Andualem

[▲ Volver al índice](#índice)

---

Licencia <a name="id8"></a>
--------

Licencia GNU-GPL <[https://www.gnu.org/licenses/gpl-3.0.html](https://www.gnu.org/licenses/gpl-3.0.html)\>

[▲ Volver al índice](#índice)
