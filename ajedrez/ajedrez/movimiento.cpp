#include <iostream>
#include <cctype>
#include "const.h"
#include "logica.h"
using namespace std;


bool movimientoValido(int xInicio, int yInicio, int xFin, int yFin) {
    char pieza = tablero[xInicio][yInicio];
    char piezaDestino = tablero[xFin][yFin];

    if (pieza == '*') return false;
    if (turnoBlancas && islower(pieza)) return false; //Islower o Isupper comprueban si es menor o mayor a...
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
    } //abs devuelve el valor absoluto de un parametro 

    if (pieza == 'T' || pieza == 't') {
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

    // Movimiento de la Reina
    if (pieza == 'Q' || pieza == 'q') {
    // Movimiento diagonal (como alfil)
    if (abs(xFin - xInicio) == abs(yFin - yInicio)) {
        int dx = (xFin - xInicio) > 0 ? 1 : -1;
        int dy = (yFin - yInicio) > 0 ? 1 : -1;
        int x = xInicio + dx, y = yInicio + dy;
        while (x != xFin && y != yFin) {
            if (tablero[x][y] != '*') return false;
            x += dx;
            y += dy;
        }
        return true;
    }
    // Movimiento recto (como torre)
    if (xInicio == xFin || yInicio == yFin) {
        return caminoLibreTorre(xInicio, yInicio, xFin, yFin);
    }

    return false;
}


    // Movimiento del Alfil
    if (pieza == 'B' || pieza == 'b') {
        if (abs(xFin - xInicio) == abs(yFin - yInicio)) {
            int dx = (xFin - xInicio) > 0 ? 1 : -1;
            int dy = (yFin - yInicio) > 0 ? 1 : -1;
            int x = xInicio + dx, y = yInicio + dy;
            while (x != xFin && y != yFin) {
                if (tablero[x][y] != '*') return false;
                x += dx;
                y += dy;
            }
            return true;
        }
        return false;
    }

    // Movimiento del Caballo
    if (pieza == 'H' || pieza == 'h') {
        int dx = abs(xFin - xInicio);
        int dy = abs(yFin - yInicio);
        if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) return true;
        return false;
    }

    // Movimiento del Rey
    if (pieza == 'K' || pieza == 'k') {
        int dx = abs(xFin - xInicio);
        int dy = abs(yFin - yInicio);
        if (dx <= 1 && dy <= 1) return true;
        return false;
    }

    return false;
}

bool caminoLibreTorre(int xInicio, int yInicio, int xFin, int yFin) {
    if (xInicio == xFin) {
        int inicio = yInicio < yFin ? yInicio + 1 : yFin + 1;
        int fin = yInicio < yFin ? yFin : yInicio;
        for (int y = inicio; y < fin; ++y) {
            if (tablero[xInicio][y] != '*') return false;
        }
    } else if (yInicio == yFin) {
        int inicio = xInicio < xFin ? xInicio + 1 : xFin + 1;
        int fin = xInicio < xFin ? xFin : xInicio;
        for (int x = inicio; x < fin; ++x) {
            if (tablero[x][yInicio] != '*') return false;
        }
    } else {
        return false;  // no es movimiento recto
    }

    return true;
}
