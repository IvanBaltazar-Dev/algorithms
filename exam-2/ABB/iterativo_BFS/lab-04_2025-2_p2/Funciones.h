//
// Created by Ivan Piero Baltazar on 9/07/2026.
//

#ifndef LAB_04_2025_2_P2_FUNCIONES_H
#define LAB_04_2025_2_P2_FUNCIONES_H
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"

using namespace std;

NodoArbolBinarioBusqueda *crearNodo(int numero);
void insertarMiniHeap(ArbolBinarioBusqueda &arbol, Cola &cola, int numero);
void flotar(NodoArbolBinarioBusqueda *nuevo);
void imprimirPorNivel(ArbolBinarioBusqueda arbol);



#endif //LAB_04_2025_2_P2_FUNCIONES_H
