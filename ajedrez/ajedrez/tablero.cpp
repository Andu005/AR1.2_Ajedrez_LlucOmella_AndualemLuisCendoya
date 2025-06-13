#include <iostream>
#include <cctype>
#include "const.h"
#include "logica.h"
using namespace std;

//generación de tablero
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

//impresión del tablero
void mostrarTablero() {
    cout << "\n  1 2 3 4 5 6 7 8" << endl;
    for (int i = 0; i < 8; ++i) {
        cout << 8 - i << " ";
        for (int j = 0; j < 8; ++j) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
