//
// Created by Ivan Piero Baltazar on 6/07/2026.
//

#ifndef LAB_05_2026_1_P1_FUNCIONES_H
#define LAB_05_2026_1_P1_FUNCIONES_H
#include <iostream>
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaCola/funcionesCola.h"
#include "BibliotecaCola/Cola.h"
#define N 8
using namespace std;

void cargarDatos(ArbolBinarioBusqueda &ABB, const int *arr,int size);
void zigZagOrder(const ArbolBinarioBusqueda ABB);

#endif //LAB_05_2026_1_P1_FUNCIONES_H
