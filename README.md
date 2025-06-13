# ♟️ Simulador del juego del Ajedrez
Simulación del juego del ajedrez en C++, jugable mediante terminal.

---

## ⬜⬛ Tablero

- Generación de un tablero.
- Colocación de fichas en posición inicial

---

## Muestra de la inicialización del tablero
![Muestra de la inicialización del tablero](/tablero.png)

---

## 🔛 Movimiento

- Los jugadores alternan su turno.
- Si el movimiento no es válido, se le indica al usuario y permitirá un nuevo movimiento.

---

## Fichas

| Nombre    | Cantidad (por jugador) | Movimiento                  | Elimina                              |
|-----------|------------------------|-----------------------------|--------------------------------------|
| Peón      | 8                      | 1 casilla adelante (2 en primer movimiento) | Diagonal adelante (1 casilla) |
| Torre     | 2                      | Horizontal/Vertical (ilimitado) | Igual que movimiento               |
| Caballo   | 2                      | En "L" (2+1 casillas)       | Igual que movimiento               |
| Alfil     | 2                      | Diagonal (ilimitado)        | Igual que movimiento               |
| Reina     | 1                      | Horizontal/Vertical/Diagonal (ilimitado) | Igual que movimiento    |
| Rey       | 1                      | 1 casilla en cualquier dirección | Igual que movimiento          |


---

## 🏁 Juego

- El juego pedirá al usuario que ingrese la posición movimiento: ej. a2 a3.
- La ficha se mueve sí, puede avanzar y/o matar a otra ficha.

---

## 📁 Repositorio

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

## 📚 Creditos

Practica realitzada por:

- Lluc Omella
- Andualem

---

Licencia
--------

Licencia GNU-GPL <[https://www.gnu.org/licenses/gpl-3.0.html](https://www.gnu.org/licenses/gpl-3.0.html)\>
