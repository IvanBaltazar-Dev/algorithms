//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal

#include <iostream>
#include <iomanip>
#include <fstream>
#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolBinarioBusqueda.h"

using namespace std;

/*FUNCIONES DE ARBOL BINARIO
 *QUE TAMBIEN USA UN
 *ARBOL BINARIO DE BUSQUEDA*/

void construir(struct ArbolBinarioBusqueda &arbol) {
    arbol.raiz = nullptr;
}

bool esArbolVacio(const struct ArbolBinarioBusqueda &nodo) {
    return nodo.raiz == nullptr;
}

bool esNodoVacio(const struct NodoArbolBinarioBusqueda *nodo) {
    return nodo == nullptr;
}

void plantarArbolBinario(struct ArbolBinarioBusqueda &arbol, const struct ArbolBinarioBusqueda &izquierda,
               const struct ElementoArbolBinarioBusqueda &elemento, const struct ArbolBinarioBusqueda &derecha) {

    plantarNodoArbolBinario(arbol.raiz, izquierda.raiz, elemento, derecha.raiz);
}

void plantarNodoArbolBinario(struct NodoArbolBinarioBusqueda *&nodo, struct NodoArbolBinarioBusqueda *izquierda,
    const struct ElementoArbolBinarioBusqueda &elemento, struct NodoArbolBinarioBusqueda *derecha) {
    struct NodoArbolBinarioBusqueda *nuevo = new struct NodoArbolBinarioBusqueda;
    nuevo->derecha = derecha;
    nuevo->izquierda = izquierda;
    nuevo->elemento = elemento;
    nodo = nuevo;
}

void imprimirNodo(struct NodoArbolBinarioBusqueda *raiz) {
    cout << setw(10) << raiz->elemento.valor << "-"<<raiz->elemento.valor << "  ";
}

void recorrerPreOrden(const struct ArbolBinarioBusqueda &arbol) {
    recorrerPreOrdenRecursivo(arbol.raiz);
}

void recorrerPreOrdenRecursivo(struct NodoArbolBinarioBusqueda *nodo) {
    if (not esNodoVacio(nodo)) {
        imprimirNodo(nodo);
        recorrerPreOrdenRecursivo(nodo->izquierda);
        recorrerPreOrdenRecursivo(nodo->derecha);
    }
}

void recorrerEnOrden(const struct ArbolBinarioBusqueda &arbol) {
    recorrerEnOrdenRecursivo(arbol.raiz);
}

/*Va mostrar el Ã¡rbol en orden */
void recorrerEnOrdenRecursivo(struct NodoArbolBinarioBusqueda *nodo) {
    if (not esNodoVacio(nodo)) {
        recorrerEnOrdenRecursivo(nodo->izquierda);
        imprimirNodo(nodo);
        recorrerEnOrdenRecursivo(nodo->derecha);
    }
}

void recorrerPostOrden(const struct ArbolBinarioBusqueda &arbol) {
    recorrerPostOrdenRecursivo(arbol.raiz);
}

void recorrerPostOrdenRecursivo(struct NodoArbolBinarioBusqueda *nodo) {
    if (not esNodoVacio(nodo)) {
        recorrerPostOrdenRecursivo(nodo->izquierda);
        recorrerPostOrdenRecursivo(nodo->derecha);
        imprimirNodo(nodo);
    }
}

int numeroHojas(const struct ArbolBinarioBusqueda &arbol) {
    return numeroHojasRecursivo(arbol.raiz);
}

int numeroHojasRecursivo(struct NodoArbolBinarioBusqueda *nodo) {
    if (esNodoVacio(nodo))
        return 0;
    else if (esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha))
        return 1;
    else
        return numeroHojasRecursivo(nodo->izquierda) + numeroHojasRecursivo(nodo->derecha);
}


int numeroNodos(const struct ArbolBinarioBusqueda &arbol) {
    return numeroNodosRecursivo(arbol.raiz);
}

int numeroNodosRecursivo(struct NodoArbolBinarioBusqueda *nodo) {
    if (esNodoVacio(nodo))
        return 0;
    else
        return 1 + numeroNodosRecursivo(nodo->izquierda) + numeroNodosRecursivo(nodo->derecha);
}

int altura(const struct ArbolBinarioBusqueda & arbol){
       return alturaRecursivo(arbol.raiz);
}

int alturaRecursivo(struct NodoArbolBinarioBusqueda * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else if(esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha))
        return 1;
    else
        return 1 + maximo(alturaRecursivo(nodo->izquierda), alturaRecursivo(nodo->derecha));
}

int maximo(int a, int b){
    return a >= b ? a : b;
}

bool esEquilibrado(const struct ArbolBinarioBusqueda & arbol){
    return esEquilibradoRecursivo(arbol.raiz);
}

bool esEquilibradoRecursivo(struct NodoArbolBinarioBusqueda * nodo){
    if(esNodoVacio(nodo))
        return true;
    else{
        int alturaHijoIzquierdo = alturaRecursivo(nodo->izquierda);
        int alturaHijoDerecho = alturaRecursivo(nodo->derecha);
        int diferencia = abs(alturaHijoIzquierdo - alturaHijoDerecho);
        return diferencia <=1 and esEquilibradoRecursivo(nodo->izquierda) and
                esEquilibradoRecursivo(nodo->derecha);
    }
}

void destruirArbolBinario(struct ArbolBinarioBusqueda & arbol){
    destruirRecursivo(arbol.raiz);
    arbol.raiz = nullptr;
}

void destruirRecursivo(struct NodoArbolBinarioBusqueda * nodo){
    if(not (esNodoVacio(nodo))){
        destruirRecursivo(nodo->izquierda);
        destruirRecursivo(nodo->derecha);
        delete nodo;
    }
}