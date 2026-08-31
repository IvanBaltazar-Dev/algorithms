//
// Created by Ivan Piero Baltazar on 6/07/2026.
//

#include "Funciones.h"


void cargarElementos(ArbolBinarioBusqueda &ABB, int* arr, int size) {
    for (int i=0;i<size;i++) {
        ElementoArbolBinarioBusqueda elemento{};
        elemento.numero = arr[i];
        insertar(ABB, elemento);
    }
}

void zigZagOrder(const ArbolBinarioBusqueda ABB) {
    if (esArbolVacio(ABB)) return;

    Cola cola{};
    construir(cola);

    ElementoCola elemento{};
    NodoArbolBinarioBusqueda *nodo = ABB.raiz;
    elemento.nodo = nodo;
    encolar(cola, elemento);

    int nivel = 1;
    bool izquierdaDerecha = true;

    while (!esColaVacia(cola)) {
        int cantElementos = longitud(cola);

        NodoArbolBinarioBusqueda *arrNodos[100]{};

        for (int i=0;i<cantElementos;i++) {
            ElementoCola eCola = desencolar(cola);
            NodoArbolBinarioBusqueda *nodo_actual = eCola.nodo;
            arrNodos[i] = nodo_actual;

            if (nodo_actual->izquierda != nullptr) {
                ElementoCola aux{};
                aux.nodo = nodo_actual->izquierda;
                encolar(cola,aux);
            }
            if (nodo_actual->derecha != nullptr) {
                ElementoCola aux{};
                aux.nodo = nodo_actual->derecha;
                encolar(cola,aux);
            }
        }
        cout<<"Nivel "<<nivel<<": ";

        if (izquierdaDerecha) {
            for (int i=0;i<cantElementos;i++) {
                cout<<arrNodos[i]->elemento.numero<<" ";
            }
        }else {
            for (int i=cantElementos-1;i>=0;i--) {
                cout<<arrNodos[i]->elemento.numero<<" ";
            }
        }
        cout<<endl;
        izquierdaDerecha = !izquierdaDerecha;
        nivel++;
    }
}