//
// Created by Ivan Piero Baltazar on 7/07/2026.
//

#include "Funciones.h"


int resolverParidad(int *arr,int inicio, int fin) {
    if (inicio > fin) return -1;
    if (inicio == fin) {
        return inicio;
    }

    int mitad = inicio + (fin - inicio)/2;

    if (mitad%2 == 1) mitad--;

    if (arr[mitad] != arr[mitad+1]) {
        return resolverParidad(arr,inicio,mitad);
    }else {
        return resolverParidad(arr,mitad+2,fin);
    }
}