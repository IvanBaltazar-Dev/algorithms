//
// Created by Ivan Piero Baltazar on 6/07/2026.
//

#include "Funciones.h"

int resolver(int *arr,int inicio, int fin) {
    if (inicio == fin) return arr[inicio];

    int mitad = inicio + (fin-inicio)/2;

    if (arr[mitad] > arr[fin]) { //DERECHA
        return resolver(arr, mitad+1, fin);
    }else { //estamos en FRONTERA o es para la izquierda
        return resolver(arr, inicio, mitad);
    }

}