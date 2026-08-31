// Lab 4 (2024-2) - Pregunta 2 "Vitivinicola"
// ABB de lotes de vino ordenado por año (clave = numero). Dato = cantidad.
// a) ingresa_lote: inserta un año nuevo o acumula si el año ya existe.
// b) reporteDescendente: reporte de stock de mayor a menor año, ITERATIVO,
//    usando solo una Pila auxiliar que guarda datos (no nodos).

#include <iostream>
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"

using namespace std;

// Estrategia: busca el nodo cuya clave (numero = año) es igual a "anio",
// aprovechando el orden del ABB. Devuelve el PUNTERO (no bool) para poder
// modificar el nodo. Retorna nullptr si el año no existe en el arbol.
NodoArbolBinarioBusqueda* buscarNodo(NodoArbolBinarioBusqueda *nodo, int anio) {
    if (esNodoVacio(nodo)) return nullptr;
    if (nodo->elemento.numero == anio) return nodo;
    if (anio < nodo->elemento.numero)
        return buscarNodo(nodo->izquierda, anio);
    else
        return buscarNodo(nodo->derecha, anio);
}

// Estrategia (parte a): si el año ya existe, solo acumulo su cantidad
// (actualizo el lote). Si no existe, uso insertar de la libreria, que lo
// coloca ordenado por año. Asi un mismo año nunca se duplica en dos nodos.
void ingresa_lote(ArbolBinarioBusqueda &arbol, int anio, int cantidad) {
    NodoArbolBinarioBusqueda *nodo = buscarNodo(arbol.raiz, anio);
    if (nodo != nullptr)
        nodo->elemento.cantidad += cantidad;   // año existente: acumulo stock
    else
        insertar(arbol, {anio, cantidad});     // año nuevo: inserto un nodo
}

// Estrategia (parte b): reporte en orden DESCENDENTE por año, iterativo.
// El recorrido en orden inverso (derecha, nodo, izquierda) de un ABB entrega
// las claves de mayor a menor. Uso una Pila para recordar el camino: bajo por
// la DERECHA apilando; cuando ya no puedo bajar, desapilo (el mayor pendiente),
// lo muestro y sigo por la IZQUIERDA. La pila guarda solo el año (dato), no el
// nodo, por eso re-ubico el nodo real con buscarNodo antes de mostrarlo.
void reporteDescendente(const ArbolBinarioBusqueda &arbol) {
    Pila pila;
    construir(pila);
    NodoArbolBinarioBusqueda *actual = arbol.raiz;

    while (actual != nullptr || !esPilaVacia(pila)) {
        // 1) Bajo por la DERECHA apilando solo la clave (año)
        while (actual != nullptr) {
            ElementoPila dato;
            dato.numero = actual->elemento.numero;
            apilar(pila, dato);
            actual = actual->derecha;
        }
        // 2) Saco el año del tope y re-ubico su nodo desde la raiz
        int anio = desapilar(pila).numero;
        actual = buscarNodo(arbol.raiz, anio);
        // 3) Muestro el lote: año-cantidad
        cout << actual->elemento.numero << "-" << actual->elemento.cantidad << "  ";
        // 4) Continuo por la IZQUIERDA
        actual = actual->izquierda;
    }
    cout << endl;
}

int main() {
    ArbolBinarioBusqueda arbol;
    construir(arbol);

    // Ingreso de los 8 lotes (año, cantidad) -> reproduce el arbol del ejemplo
    ingresa_lote(arbol, 2018, 100);
    ingresa_lote(arbol, 2011, 150);
    ingresa_lote(arbol, 2022, 50);
    ingresa_lote(arbol, 2010, 175);
    ingresa_lote(arbol, 2017, 25);
    ingresa_lote(arbol, 2019, 125);
    ingresa_lote(arbol, 2023, 200);
    ingresa_lote(arbol, 2020, 75);

    cout << "Reporte de stock (orden descendente por año):" << endl;
    reporteDescendente(arbol);

    // Demostracion de la parte a) con los ejemplos del enunciado:
    cout << "\nIngresando 2013-90 (año nuevo) y 2018-100 (año existente)..." << endl;
    ingresa_lote(arbol, 2013, 90);    // 2013 no existe -> se AÑADE un nuevo lote
    ingresa_lote(arbol, 2018, 100);   // 2018 ya existe (100) -> se ACTUALIZA a 200

    cout << "\nReporte de stock actualizado:" << endl;
    reporteDescendente(arbol);

    return 0;
}
