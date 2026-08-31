//
// Created by Ivan Piero Baltazar on 6/07/2026.
//

#include "Funciones.h"
void cargarDatos(ArbolBinarioBusqueda &ABB, const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        ElementoArbolBinarioBusqueda elemento{};
        elemento.numero = arr[i];
        insertarRecursivo(ABB.raiz, elemento);
    }
}

void zigZagOrder(const ArbolBinarioBusqueda ABB) {
    if (ABB.raiz == nullptr) { //ARBOL VACIO
        return;
    }

    Cola cola{};
    construir(cola);

    ElementoCola elementoRaiz{};
    elementoRaiz.nodo = ABB.raiz;
    encolar(cola,elementoRaiz);

    bool izquierdaDerecha = true;

    int nivel = 1;

    while (!esColaVacia(cola)) {
        // imprimir(cola);
        //MIENTRAS NO SEA COLA VACIA PROCESA
        int cantidadElementos = longitud(cola);

        NodoArbolBinarioBusqueda *arr[100]{};
        for (int i = 0; i < cantidadElementos; i++) {
            //Desencolamos y guardamos
            ElementoCola elementoActual = desencolar(cola);
            NodoArbolBinarioBusqueda *nodoActual = elementoActual.nodo;
            arr[i] = nodoActual;
            //ENCOLAMOS HIJOS IZQUIERDA Y DERECHA SI EXISTEN
            if (nodoActual->izquierda != nullptr) {
                ElementoCola elemento{};
                elemento.nodo = nodoActual->izquierda;
                encolar(cola,elemento);
            }
            if (nodoActual->derecha != nullptr) {
                ElementoCola elemento{};
                elemento.nodo = nodoActual->derecha;
                encolar(cola,elemento);
            }
            // imprimir(cola);
        }
        //IMPRIMIR RESULTADOS
        cout<<"Nivel "<<nivel<<": ";
        if (izquierdaDerecha) {
            for (int i = 0; i < cantidadElementos; i++) {
                cout<<arr[i]->elemento.numero<<" ";
            }
            cout<<endl;
        }else {
            for (int i = cantidadElementos-1; i>=0; i--) {
                cout<<arr[i]->elemento.numero<<" ";
            }
            cout<<endl;
        }
        izquierdaDerecha = !izquierdaDerecha;
        nivel++;
    }

}