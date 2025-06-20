#include <iostream>
#include <cctype> //Se usa para funciones de manejo de caracteres, como verificar si un carácter es una letra o un número
#include "const.h"
#include "logica.h"
using namespace std;

void jugar() {
    inicializarTablero();  // Configura el tablero con las piezas en la posición inicial
    
    while (true) {  // Bucle principal del juego que se ejecuta hasta que hay un ganador
        mostrarTablero(); // impresion del tablero
        string entrada1, entrada2;
        cout << (turnoBlancas ? "Blancas" : "Negras") << ", ingrese movimiento (ej. 12 13): ";
        cin >> entrada1 >> entrada2;

        if (entrada1.size() != 2 || entrada2.size() != 2) {
            cout << "Formato incorrecto! Usar ej. 12 13\n";
            continue;
        }
        // Conversión de coordenadas (por ejemplo, "12": fila 1, columna 2)
        int yInicio = entrada1[0] - '1';
        int xInicio = 8 - (entrada1[1] - '0');
        int yFin = entrada2[0] - '1';
        int xFin = 8 - (entrada2[1] - '0');

        // Verificación de las cordenadas
        if (xInicio < 0 || xInicio > 7 || yInicio < 0 || yInicio > 7 ||
            xFin < 0 || xFin > 7 || yFin < 0 || yFin > 7) {
            cout << "Posición inválida!\n";
            continue;
        }
            
        //captura del rey (jaque)
        if (movimientoValido(xInicio, yInicio, xFin, yFin)) {
            if (tablero[xFin][yFin] == 'K' || tablero[xFin][yFin] == 'k') {
                tablero[xFin][yFin] = tablero[xInicio][yInicio];
                tablero[xInicio][yInicio] = '*';
                mostrarTablero();
                cout << (turnoBlancas ? "¡Las blancas ganan!" : "¡Las negras ganan!") << endl;
                break;
            }

            tablero[xFin][yFin] = tablero[xInicio][yInicio];
            tablero[xInicio][yInicio] = '*';

            if (tablero[xFin][yFin] == 'P' && xFin == 0) {
                tablero[xFin][yFin] = 'Q';
                cout << "¡Peón promovido a reina!" << endl;
            }
            if (tablero[xFin][yFin] == 'p' && xFin == 7) {
                tablero[xFin][yFin] = 'q';
                cout << "¡Peón promovido a reina!" << endl;
            }

            turnoBlancas = !turnoBlancas; //cambio de turno
        }
        else {
            cout << "Movimiento no válido!\n";
        }
    }
}
