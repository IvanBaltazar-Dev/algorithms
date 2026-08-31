//
// Created by Ivan Piero Baltazar on 4/07/2026.
//

#include "Funciones.h"

void cargarDatos(ArbolBinarioBusqueda &ABB,int matrix[][2]) {
    ElementoArbolBinarioBusqueda lista[N]{};

    for(int i=0;i<N;i++) {
        lista[i].numero = matrix[i][0];
        lista[i].cantidad = matrix[i][1];
    }
    for (int i=0;i<N;i++) {
        insertar(ABB,lista[i]);
    }
}

int despachar(ArbolBinarioBusqueda &ABB,int cantidad) {
    if (esArbolVacio(ABB) || cantidad == 0) {
        return cantidad;
    }

    NodoArbolBinarioBusqueda *pMin = minimoArbol(ABB.raiz);

    if (pMin->elemento.cantidad <= cantidad) {
        //CASO MENOR A LA CANTIDAD SOLICITADA
        int restante = cantidad - pMin->elemento.cantidad;
        eliminar(ABB,pMin->elemento);
        return despachar(ABB,restante);
    }else {
        //CASO MAYOR A LA CANTIDAD SOLICITADA
        pMin->elemento.cantidad -= cantidad;
        return 0;
    }
}