//
// Created by Ivan Piero Baltazar on 17/06/2026.
//

#include "Funciones.h"

int resolver(int *arr, int inicio, int fin) {
    if (inicio == fin)
        return arr[inicio];
    int mitad = inicio + (fin - inicio)/2;
    if (arr[mitad] > arr[fin]) {
        return resolver(arr, mitad+1, fin );
    }else {
        return resolver(arr, inicio, mitad);
    }
}
