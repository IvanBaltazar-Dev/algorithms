//
// Created by Ivan Piero Baltazar on 17/06/2026.
//

#include "Funciones.h"

void resuelve(int *arr, int inicio, int final, int T, int &result) {
    if (inicio > final) return;
    int mitad = inicio + (final - inicio)/2;
    if (arr[mitad] < T) {
        result = mitad;
        return resuelve(arr, inicio, mitad-1, T, result);
    }else {
        return resuelve(arr, mitad+1, final, T, result);
    }
}
