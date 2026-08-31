//
// Created by Ivan Piero Baltazar on 9/07/2026.
//

#ifndef LAB_05_2026_1_P1_A_FUNCIONES_H
#define LAB_05_2026_1_P1_A_FUNCIONES_H
#include <iostream>
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
#include "BibliotecaCola/funcionesCola.h"
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaCola/Cola.h"

using namespace std;

void cargarDatos(ArbolBinarioBusqueda &ABB, int arr[],int  size);
void imprimirPorNiveles(ArbolBinarioBusqueda ABB);

#endif //LAB_05_2026_1_P1_A_FUNCIONES_H
