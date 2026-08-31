//
// Created by Ivan Piero Baltazar on 10/07/2026.
//

#include "Funciones.h"

#include <fstream>


#include "Funciones.h"

// Crea un nodo hoja con el valor recibido.
void crearHoja(ArbolBinarioBusqueda &arbol, string valor) {
    ArbolBinarioBusqueda izq, der;
    construir(izq);
    construir(der);

    ElementoArbolBinarioBusqueda elemento;
    elemento.valor = valor;

    plantarArbolBinario(arbol, izq, elemento, der);
}

// Crea un nodo padre con hijo izquierdo y derecho.
void crearNodo(ArbolBinarioBusqueda &arbol,
               ArbolBinarioBusqueda &izq,
               string valor,
               ArbolBinarioBusqueda &der) {
    ElementoArbolBinarioBusqueda elemento;
    elemento.valor = valor;

    plantarArbolBinario(arbol, izq, elemento, der);
}

// Lee la consulta desde un archivo o desde teclado y arma el AST.
void crearArbolSQL(ArbolBinarioBusqueda &arbol, istream &entrada) {
    string palabra;
    string columna = "";
    string tabla = "";
    string condicion = "";

    // Lee SELECT.
    entrada >> palabra;

    // Lee lo que viene despues de SELECT.
    if (entrada >> palabra) {
        if (palabra == "FROM") {
            columna = "";
        } else {
            columna = palabra;
            entrada >> palabra;
        }
    }

    // Si encontro FROM, intenta leer la tabla.
    if (palabra == "FROM") {
        if (entrada >> palabra) {
            if (palabra == "WHERE") {
                tabla = "";
            } else {
                tabla = palabra;
                entrada >> palabra;
            }
        }
    }

    // Si encontro WHERE, lee toda la condicion hasta terminar.
    if (palabra == "WHERE") {
        while (entrada >> palabra) {
            condicion += palabra;
        }
    }

    construir(arbol);

    ArbolBinarioBusqueda vacio;
    construir(vacio);

    // COLUMNA -> valor de columna
    ArbolBinarioBusqueda valorColumna, nodoColumna;
    crearHoja(valorColumna, columna);
    crearNodo(nodoColumna, valorColumna, "COLUMNA", vacio);

    // TABLA -> valor de tabla
    ArbolBinarioBusqueda valorTabla, nodoTabla;
    crearHoja(valorTabla, tabla);
    crearNodo(nodoTabla, valorTabla, "TABLA", vacio);

    // CONDICION -> valor de condicion
    ArbolBinarioBusqueda valorCondicion, nodoCondicion;
    crearHoja(valorCondicion, condicion);
    crearNodo(nodoCondicion, valorCondicion, "CONDICION", vacio);

    // WHERE -> CONDICION
    ArbolBinarioBusqueda nodoWhere;
    crearNodo(nodoWhere, nodoCondicion, "WHERE", vacio);

    // FROM -> TABLA y WHERE
    ArbolBinarioBusqueda nodoFrom;
    crearNodo(nodoFrom, nodoTabla, "FROM", nodoWhere);

    // SELECT -> COLUMNA y FROM
    crearNodo(arbol, nodoColumna, "SELECT", nodoFrom);
}

// Valida solo los casos del enunciado.
bool verificaArbolSQL(const ArbolBinarioBusqueda &arbol) {
    NodoArbolBinarioBusqueda *select = arbol.raiz;
    NodoArbolBinarioBusqueda *columna = select->izquierda;
    NodoArbolBinarioBusqueda *from = select->derecha;
    NodoArbolBinarioBusqueda *tabla = from->izquierda;
    NodoArbolBinarioBusqueda *where = from->derecha;
    NodoArbolBinarioBusqueda *condicion = where->izquierda;

    if (columna->izquierda->elemento.valor == "") {
        cout << "Error: Falta la columna" << endl;
        cout << "Consulta invalida." << endl;
        return false;
    }

    if (tabla->izquierda->elemento.valor == "") {
        cout << "Error: Falta clausula FROM." << endl;
        cout << "Consulta invalida." << endl;
        return false;
    }

    if (condicion->izquierda->elemento.valor == "") {
        cout << "Error: WHERE debe tener una condicion." << endl;
        cout << "Consulta invalida." << endl;
        return false;
    }

    cout << "Consulta valida: Estructura SELECT correcta." << endl;
    return true;
}

// Imprime el arbol en preorden.
void imprimirNodoSQL(NodoArbolBinarioBusqueda *nodo) {
    if (nodo == nullptr) return;

    cout << nodo->elemento.valor << endl;
    imprimirNodoSQL(nodo->izquierda);
    imprimirNodoSQL(nodo->derecha);
}

void imprimirArbolSQL(const ArbolBinarioBusqueda &arbol) {
    imprimirNodoSQL(arbol.raiz);
}