#include <iostream>
#include <cctype>
#include "const.h"
#include "logica.h"
using namespace std;


void inicializarTablero() {
    char piezasNegras[] = { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' };
    char piezasBlancas[] = { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' };
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


void mostrarTablero() {
    cout << "\n  a b c d e f g h" << endl;
    for (int i = 0; i < 8; ++i) {
        cout << 8 - i << " ";
        for (int j = 0; j < 8; ++j) {
            cout << tablero[i][j] << " ";
        }
        cout << 8 - i << endl;
    }
    cout << "  a b c d e f g h" << endl;
}