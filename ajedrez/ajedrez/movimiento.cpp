#include <iostream>
#include <cctype>
#include "const.h"
#include "logica.h"
using namespace std;


bool movimientoValido(int xInicio, int yInicio, int xFin, int yFin) {
    char pieza = tablero[xInicio][yInicio];
    char piezaDestino = tablero[xFin][yFin];

    if (pieza == '*') return false;
    if (turnoBlancas && islower(pieza)) return false;
    if (!turnoBlancas && isupper(pieza)) return false;


    if (piezaDestino != '*') {
        if (turnoBlancas && isupper(piezaDestino)) return false;
        if (!turnoBlancas && islower(piezaDestino)) return false;
    }


    if (pieza == 'P') {
        if (yInicio == yFin && tablero[xFin][yFin] == '*' && (xInicio - xFin == 1)) return true;
        if (xInicio == 6 && yInicio == yFin && xFin == 4 && tablero[5][yFin] == '*' && tablero[4][yFin] == '*') return true;
        if ((xInicio - xFin == 1) && abs(yInicio - yFin) == 1 && islower(tablero[xFin][yFin])) return true;
    }

    if (pieza == 'p') {
        if (yInicio == yFin && tablero[xFin][yFin] == '*' && (xFin - xInicio == 1)) return true;
        if (xInicio == 1 && yInicio == yFin && xFin == 3 && tablero[2][yFin] == '*' && tablero[3][yFin] == '*') return true;
        if ((xFin - xInicio == 1) && abs(yInicio - yFin) == 1 && isupper(tablero[xFin][yFin])) return true;
    }

    if (pieza == 'R' || pieza == 'r') {
        if (xInicio != xFin && yInicio != yFin) return false;

        if (xInicio == xFin) { 
            int inicio = yInicio < yFin ? yInicio + 1 : yFin + 1;
            int fin = yInicio < yFin ? yFin : yInicio;
            for (int y = inicio; y < fin; ++y) {
                if (tablero[xInicio][y] != '*') return false;
            }
        }
        else {
            int inicio = xInicio < xFin ? xInicio + 1 : xFin + 1;
            int fin = xInicio < xFin ? xFin : xInicio;
            for (int x = inicio; x < fin; ++x) {
                if (tablero[x][yInicio] != '*') return false;
            }
        }
        return true;
    }

    return false;
}