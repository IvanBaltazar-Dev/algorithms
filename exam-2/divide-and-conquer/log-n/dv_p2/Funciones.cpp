//
// Created by Ivan Piero Baltazar on 6/07/2026.
//

#include "Funciones.h"

void resolver(int *arr, int inicio, int fin, int &posZero){
    if (inicio > fin) return; //NO SIEMPRE EXISTE

    int mitad = inicio + (fin-inicio)/2;

    if (arr[mitad]==0) {//ES EL PRIMER 0 o A LA IZQUIERDA
        posZero = mitad;
        resolver(arr,inicio,mitad-1,posZero);
    }else {
        resolver(arr,mitad+1,fin,posZero);
    }
}