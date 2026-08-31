//
// Created by Ivan Piero Baltazar on 7/07/2026.
//

#include "Funciones.h"

int resolver_rot(int *arr,int inicio,int fin) {
    if (inicio>fin) return -1;
    if (inicio == fin) {
        return inicio;
    }

    int mitad = inicio + (fin -inicio)/2;

    if (arr[mitad] <= arr[fin]) { //IZQUIERDA O LO ENCONTRAMOS
        return resolver_rot(arr,inicio,mitad);
    }else {//DERECHA
        return resolver_rot(arr,mitad+1,fin);
    }
}

int busquedaBinaria(int *arr,int inicio,int fin,int codigo) {
    if (inicio>fin) return -1;

    int mitad = inicio + (fin-inicio)/2;

    if (codigo == arr[mitad]) return mitad;

    if (codigo < arr[mitad]) {
        //IZQUIERDA
        return busquedaBinaria(arr,inicio,mitad-1,codigo);
    }else {//DERECHA
        return busquedaBinaria(arr,mitad+1,fin,codigo);
    }
}