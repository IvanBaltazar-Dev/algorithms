//
// Created by Ivan Piero Baltazar on 9/07/2026.
//

#include "Funciones.h"

#include <iostream>
#include <ostream>

NodoArbolBinarioBusqueda *crearNodo(int numero) {
    ElementoArbolBinarioBusqueda elemento{};
    elemento.numero = numero;

    NodoArbolBinarioBusqueda *nuevo = new NodoArbolBinarioBusqueda{};
    nuevo->elemento = elemento;
    nuevo->derecha = nullptr;
    nuevo->izquierda = nullptr;
    nuevo->padre = nullptr;

    return nuevo;
}

void insertarMiniHeap(ArbolBinarioBusqueda &arbol, Cola &cola, int numero) {
    NodoArbolBinarioBusqueda *nuevo = crearNodo(numero);

    if (arbol.raiz == nullptr) {
        arbol.raiz = nuevo;
        //ENCOLAR SOLO LOS NODOS AUN PUEDEN TENER HIJOS
        ElementoCola elementoCola{};
        elementoCola.nodo = nuevo;
        encolar(cola, elementoCola);
        return;
    }

    NodoArbolBinarioBusqueda *padre = cola.inicio->elemento.nodo;
    nuevo->padre = padre;

    if (padre->izquierda == nullptr) {
        padre->izquierda = nuevo;
    }else {
        padre->derecha = nuevo;
        desencolar(cola);
    }

    ElementoCola elemento{};
    elemento.nodo = nuevo;
    encolar(cola, elemento);

    flotar(nuevo);
}

void flotar(NodoArbolBinarioBusqueda *nuevo) {
    while (nuevo->padre != nullptr && nuevo->padre->elemento.numero > nuevo->elemento.numero) {
        int aux = nuevo->padre->elemento.numero;
        nuevo->padre->elemento.numero = nuevo->elemento.numero;
        nuevo->elemento.numero = aux;
        nuevo = nuevo->padre;
    }
}

void imprimirPorNivel(ArbolBinarioBusqueda arbol) {
    if (esArbolVacio(arbol)) return;
    Cola cola{};
    construir(cola);

    ElementoCola elementoCola {};
    elementoCola.nodo = arbol.raiz;
    encolar(cola, elementoCola);

    int nivel = 1;

    while (!esColaVacia(cola)) {
        int cantidad = longitud(cola);

        cout<<"Nivel "<<nivel<<": ";

        for (int i = 0; i < cantidad; i++) {
            ElementoCola elementoActual = desencolar(cola);
            NodoArbolBinarioBusqueda *nodoActual = elementoActual.nodo;

            cout<<nodoActual->elemento.numero<<" ";

            if (nodoActual->izquierda != nullptr) {
                ElementoCola hijoIzquierdo{};
                hijoIzquierdo.nodo = nodoActual->izquierda;
                encolar(cola, hijoIzquierdo);
            }
            if (nodoActual->derecha != nullptr) {
                ElementoCola hijoDerecha{};
                hijoDerecha.nodo = nodoActual->derecha;
                encolar(cola, hijoDerecha);
            }
        }
        cout<<endl;

        nivel++;
    }
}