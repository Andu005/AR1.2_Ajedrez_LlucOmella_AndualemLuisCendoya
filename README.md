# ♟️ Simulador del juego del Ajedrez
Simulación del juego del ajedrez en C++, jugable mediante terminal.

---

## Índice
1. [Tablero](#tablero)
2. [Muestra del tablero](#muestra-del-tablero)
3. [Movimiento](#movimiento)
4. [Fichas](#fichas)
5. [Juego](#juego)
6. [Repositorio](#repositorio)
7. [Créditos](#créditos)
8. [Licencia](#licencia)

---

## ⬜⬛ Tablero <a name="tablero"></a>

Para generar el tablero hemos hecho como en prácticas anteriores y hemos creado un array bidimensional. Para evitar usar *magic numbers* hemos hecho un `#define` con el valor del tablero, en este caso ajedrez, 8x8.

### `const.h`
```cpp
#define TABLERO 8
extern char tablero[TABLERO][TABLERO];
```
En la cabecera hemos hecho el define y luego hemos creado el array. Su valor es el del define, así hemos evitado el uso de **"magic numbers"**.

### `const.cpp`
```cpp
char tablero[TABLERO][TABLERO];
```
En el cpp simplemente es repetir el array con el tablero.

Para generar el tablero tenemos que ir hasta **tablero.cpp**. Allí nos encontramos con dos funciones: una que coloca las piezas e inicializa el tablero, y otra que lo muestra.

### `void inicializarTablero()`
```cpp
void inicializarTablero() {
    char piezasNegras[] = { 't', 'h', 'b', 'k', 'q', 'b', 'h', 't' };
    char piezasBlancas[] = { 'T', 'H', 'B', 'Q', 'K', 'B', 'H', 'T' };
    for (int i = 0; i < 8; ++i) {
        tablero[0][i] = piezasNegras[i];
        tablero[7][i] = piezasBlancas[i];
        tablero[1][i] = 'p';
        tablero[6][i] = 'P';
    }

    for (int i = 2; i < 6; ++i) {
        for (int j = 0; j < 8; ++j) {
            tablero[i][j] = '*';
        }
    }
}
```

Aquí hemos hecho dos cadenas de texto, una corresponde a las piezas blancas y otra a las negras. Luego las colocamos en sus respectivos sitios. Como están por orden, ponemos solo la primera posición. Luego en la casilla de arriba vamos poniendo `P` y `p` hasta la última columna. Finalmente, el resto lo llenamos con asteriscos que representan las posiciones vacías.

### `void mostrarTablero()`
```cpp
void mostrarTablero() {
    cout << "\n  1 2 3 4 5 6 7 8" << endl;
    for (int i = 0; i < 8; ++i) {
        cout << 8 - i << " ";
        for (int j = 0; j < 8; ++j) {
            cout << tablero[i][j] << " ";
        }
        cout << 8 - i << endl;
    }
    cout << "  1 2 3 4 5 6 7 8" << endl;
}
```

Aquí hacemos un `cout` de los números. La única finalidad que tienen es ayudar a que los jugadores sepan qué posición es cuál y facilitar el juego. Luego hacemos un `for` para ir imprimiendo el tablero hasta su totalidad.

- Generación de un tablero.
- Colocación de fichas en posición inicial.

[▲ Volver al índice](#índice)

---

## 🖼️ Muestra de la inicialización del tablero <a name="muestra-del-tablero"></a>

<p align="center">
  <img src="/tableroreal.png" alt="Tablero real" width="300" />
  <img src="/tablerojuego.png" alt="Tablero ASCII" width="280" />
</p>

[▲ Volver al índice](#índice)

---

## 🔛 Movimiento <a name="movimiento"></a>

El movimiento de las piezas funciona de la siguiente manera: el usuario introduce la posición inicial (que corresponde a la pieza que quiere mover) y luego la posición final (donde la quiere mover). En el código ponemos de ejemplo la posición `"12 13"`, esto como se puede apreciar en la captura corresponde a un movimiento del peón:

<p align="center"><img src="/movimientoentablero.png" alt="Movimiento en tablero" width="300" /></p>

- Los jugadores alternan su turno. Tal y como en el juego original, sacan siempre las blancas.
- Si el movimiento no es válido, se le indica al usuario y se permite un nuevo movimiento.

Todos los movimientos son comprobados por el código, tanto en que sea un movimiento posible para la ficha (por ejemplo, un peón no se podrá mover más de 2 fichas en su primer movimiento y más de 1 en los posteriores), como que la posición a la que va esté vacía. Esto lo hacemos comprobando si hay un asterisco en la posición del tablero. Por ejemplo, con los peones lo hacemos aquí:

```cpp
if (yInicio == yFin && tablero[xFin][yFin] == '*' && (xInicio - xFin == 1)) return true;
```

Esta línea sirve para avanzar. Lo que hace es comprobar que la casilla a la que va esté vacía, eso lo hace viendo si el carácter que hay es un asterisco o no. Y una vez hecho eso, le resta 1 a la fila (esto permite "subir" visualmente aunque en el array baja) y devuelve `true` porque así la booleana es verdadera y el movimiento se realiza al ser válido.

Con todos los movimientos hemos añadido esa comprobación y, en caso de que haya una pieza, nos aseguramos de que la pueda matar. Por ejemplo, un peón no puede matar avanzando; mata en diagonal. Por lo que si tiene una pieza delante, no podrá avanzar ni matar. Esto lo hemos hecho con esta línea:

```cpp
if ((xInicio - xFin == 1) && abs(yInicio - yFin) == 1 && islower(tablero[xFin][yFin])) return true;
```

Esta línea lo que hace es simple: la primera parte hace que el peón avance una posición, la segunda es para que gire a la derecha o a la izquierda (diagonal), pero solo una posición. Finalmente verifica que haya una pieza y que sea minúscula. Eso nos sirve porque todas las piezas rivales son minúsculas, por lo que el peón blanco solo puede matar a negras (que son minúsculas) y viceversa.

[▲ Volver al índice](#índice)

---

## ♟️ Fichas <a name="fichas"></a>

En nuestro juego tenemos las mismas fichas y movimientos que en el juego clásico. Hemos añadido también que cuando el peón llega al final del tablero corona y se convierte en reina. Cuando matas a una pieza no la puedes recuperar coronando como se podría hacer en el juego original, solo puedes recuperar a la reina, y no hay máximo de reinas.

| Nombre    | Cantidad (por jugador) | Movimiento                          | Elimina                      |
|-----------|------------------------|-------------------------------------|------------------------------|
| Peón      | 8                      | 1 casilla adelante (2 en primer movimiento) | Diagonal adelante (1 casilla) |
| Torre     | 2                      | Horizontal/Vertical (ilimitado)     | Igual que movimiento         |
| Caballo   | 2                      | En "L" (2+1 casillas)               | Igual que movimiento         |
| Alfil     | 2                      | Diagonal (ilimitado)                | Igual que movimiento         |
| Reina     | 1                      | Horizontal/Vertical/Diagonal (ilimitado) | Igual que movimiento         |
| Rey       | 1                      | 1 casilla en cualquier dirección    | Igual que movimiento         |

[▲ Volver al índice](#índice)

---

## 🏁 Juego <a name="juego"></a>

- La partida se desarrolla de la siguiente manera: empiezan blancas y continúan negras, y se van intercalando hasta que uno de los dos mata al rey rival.
- Para mover las fichas, el juego pedirá al usuario que ingrese la posición y el movimiento que va a realizar, por ejemplo: `a2 a3`.
- La ficha se mueve una vez pase las verificaciones; puede avanzar y/o matar a otra ficha.

[▲ Volver al índice](#índice)

---

## 📁 Repositorio <a name="repositorio"></a>

El repositorio contiene:

```text
ajedrez/
├── Archivos de encabezado/
│   ├── const.h
│   └── logica.h
│
├── Archivos de origen/
│   ├── const.cpp
│   ├── juego.cpp
│   ├── main.cpp
│   ├── movimiento.cpp
│   └── tablero.cpp
│
└── Otros archivos de configuración
```

[▲ Volver al índice](#índice)

---

## 📚 Créditos <a name="créditos"></a>

Práctica realizada por:

- Lluc Omella  
- Andualem

[▲ Volver al índice](#índice)

---

## 🪪 Licencia <a name="licencia"></a>

Licencia GNU-GPL  
[https://www.gnu.org/licenses/gpl-3.0.html](https://www.gnu.org/licenses/gpl-3.0.html)

[▲ Volver al índice](#índice)
