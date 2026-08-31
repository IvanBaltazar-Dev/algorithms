//
// Created by Ivan Piero Baltazar on 17/06/2026.
//

#include "Funciones.h"


void encuentraZero(int * arr, int inicio, int fin, int& posPrimerZero) {
    if (inicio > fin) return;
    int medio = inicio + (fin - inicio)/2;
    if (arr[medio] == 0) { //si el centro es 0 debe estar atrás
        posPrimerZero = medio;
        return encuentraZero(arr, inicio, medio-1, posPrimerZero);
    }else {//si es 1, existen 0's a la derecha
        return encuentraZero(arr, medio+1, fin, posPrimerZero);
    }
}