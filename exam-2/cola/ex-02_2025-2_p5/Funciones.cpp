//
// Created by Ivan Piero Baltazar on 10/07/2026.
//

#include "Funciones.h"

void cargarDatos(int arr[],int size,Cola &cola) {
    ElementoCola elemento{};
    for (int i=0;i<size;i++) {
        elemento.codigo = arr[i];
        encolar(cola,elemento);
    }
}

void invertirColaN(Cola &cola,int k) {

    invertirColaRecursivo(cola,k);

    // imprimir(cola);

    int longitud = cola.longitud;
    for (int i=0;i<longitud-k;i++) {
        ElementoCola elemento{};
        elemento = desencolar(cola);
        encolar(cola,elemento);
    }
}

void invertirColaRecursivo(Cola &cola,int k) {
    if (k == 0) {
        return;
    }
    ElementoCola elemento{};

    elemento = desencolar(cola);

    invertirColaRecursivo(cola,k-1);

    encolar (cola,elemento);
}