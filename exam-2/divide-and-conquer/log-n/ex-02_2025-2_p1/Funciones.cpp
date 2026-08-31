//
// Created by Ivan Piero Baltazar on 6/07/2026.
//

#include "Funciones.h"

void resolver(int *arr, int inicio, int fin, int filtro, int &index) {
    if (inicio > fin) return;

    int mitad = inicio + (fin-inicio)/2;

    if (arr[mitad]<filtro) {
        index = mitad;
        return resolver(arr,inicio,mitad-1,filtro,index);
    }else {
        return resolver(arr,mitad+1,fin,filtro,index);
    }
}