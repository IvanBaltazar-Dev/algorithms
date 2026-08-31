//
// Created by Ivan Piero Baltazar on 10/07/2026.
//

#ifndef EX_02_2025_1_P3_FUNCIONES_H
#define EX_02_2025_1_P3_FUNCIONES_H
#include <iostream>
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"

using namespace std;

void crearArbolSQL(ArbolBinarioBusqueda &arbol, istream &entrada);
bool verificaArbolSQL(const ArbolBinarioBusqueda &arbol);
void imprimirArbolSQL(const ArbolBinarioBusqueda &arbol);

#endif //EX_02_2025_1_P3_FUNCIONES_H
