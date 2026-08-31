//
// Created by Ivan Piero Baltazar on 9/07/2026.
//

#include "Funciones.h"

NodoArbolBinarioBusqueda* construirNodo(int numero) {
    NodoArbolBinarioBusqueda* nodo = new NodoArbolBinarioBusqueda{};
    nodo->elemento.numero = numero;
    nodo->derecha = nullptr;
    nodo->izquierda = nullptr;
    return nodo;
}
void cargarDatos(ArbolBinarioBusqueda &ABB, int arr[],int  size) {
    ElementoArbolBinarioBusqueda elemento{};
    for (int i = 0; i < size; i++) {
        elemento.numero = arr[i];
        insertar(ABB, elemento);
    }
}

void imprimirPorNiveles(ArbolBinarioBusqueda ABB) {
    if (esArbolVacio(ABB)) return;
    Cola cola{};
    construir(cola);

    ElementoCola elementoCola{};
    elementoCola.nodo = ABB.raiz;
    encolar(cola, elementoCola);

    int nivel = 1;
    bool izquierdaDerecha = true;
    while (!esColaVacia(cola)) {
        int cantidad = longitud(cola);

        int arr[100]{};

        for (int i = 0; i < cantidad; i++) {
            ElementoCola elementoActual = desencolar(cola);
            NodoArbolBinarioBusqueda *nodoActual = elementoActual.nodo;
            arr[i]= nodoActual->elemento.numero;
            if (nodoActual->izquierda != nullptr) {
                ElementoCola elemento{};
                elemento.nodo = nodoActual->izquierda;
                encolar(cola, elemento);
            }
            if (nodoActual->derecha != nullptr) {
                ElementoCola elemento{};
                elemento.nodo = nodoActual->derecha;
                encolar(cola, elemento);
            }
        }
        cout<<"Nivel "<<nivel<<": "<<endl;
        if (izquierdaDerecha) {
            for (int i=0; i<cantidad; i++) {
                cout << arr[i] << " ";
            }
        }else {
            for (int i=cantidad-1; i>=0; i--) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
        izquierdaDerecha = !izquierdaDerecha;
        nivel++;
    }

}
