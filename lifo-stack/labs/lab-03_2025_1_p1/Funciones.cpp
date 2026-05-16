//
// Created by Ivan Piero Baltazar on 15/05/2026.
//

#include "Funciones.h"

void solucion(int mapa[N][M], int n, int m) {
    Pila pila{};
    construir(pila);

    ElementoPila inicio{0,0};
    apilar(pila, inicio);

    bool exito = false;

    while (!esPilaVacia(pila)) {
        ElementoPila actual = desapilar(pila);
        int fila = actual.fila;
        int columna = actual.columna;

        mapa[fila][columna] = 9;

        if (fila == N-1 && columna == M-1) {
            exito = true;
            break;
        }

        if (columna+1 < M && mapa[fila][columna+1] == 0) {
            ElementoPila posDerecha{fila,columna+1};
            apilar(pila, posDerecha);
        }
        if (fila+1 < N && mapa[fila+1][columna] == 0) {
            ElementoPila posAbajo{fila+1,columna};
            apilar(pila, posAbajo);
        }
        // imprimir(pila);
    }

    if (exito) {
        cout << "!Ruta encontrada con exito!" << endl;
    }else {
        cout << "No existe una ruta viable a la salida" << endl;
    }

    destruir(pila);
}
