//
// Created by Ivan Piero Baltazar on 10/07/2026.
//

#include "Funciones.h"

void construirABB(NodoArbolBinarioBusqueda* &nodo,int arr[],int inicio,int fin) {
    if (inicio>fin) {
        return;
    }

    int mitad = inicio + (fin-inicio)/2;
    ElementoArbolBinarioBusqueda elemento{};
    elemento.numero = arr[mitad];

    plantarNodoArbolBinario(nodo,nullptr,elemento,nullptr);
    construirABB(nodo->izquierda,arr,inicio,mitad-1);
    construirABB(nodo->derecha,arr,mitad+1,fin);

}
