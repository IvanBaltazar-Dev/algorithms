//
// Created by Ivan Piero Baltazar on 6/07/2026.
//

#include "Funciones.h"

int resolver(int *arr,int inicio,int fin) {
    if (inicio == fin) {
        return arr[inicio];
    }

    int mitad = inicio + (fin - inicio)/2;

    if (arr[mitad] < arr[mitad+1]) {//DERECHA
        return resolver(arr,mitad+1,fin);
    }else {//ESTAMOS EN EL MAXIMO O A LA IZQUIERDA
        return resolver(arr,inicio,mitad);
    }
}