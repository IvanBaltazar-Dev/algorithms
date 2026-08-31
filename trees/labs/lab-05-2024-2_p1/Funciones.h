//
// Created by Ivan Piero Baltazar on 1/07/2026.
//

#ifndef LAB_05_2024_2_P1_FUNCIONES_H
#define LAB_05_2024_2_P1_FUNCIONES_H
#include <iostream>

#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/ElementoArbolBinarioBusqueda.h"
using namespace std;

void insertadiaturno(ArbolBinarioBusqueda &ABB, int cantidades[7][4]);
void insertarMitad(ArbolBinarioBusqueda& ABB,ElementoArbolBinarioBusqueda *lista, int inicio, int fin);

void insertaCantidad(ArbolBinarioBusqueda &ABB, int cantidades[7][4]);
void mergeSort(ElementoArbolBinarioBusqueda* lista,int inicio, int fin);
void merge(ElementoArbolBinarioBusqueda* lista,int inicio,int mitad,int fin);
bool esMenor(ElementoArbolBinarioBusqueda a,ElementoArbolBinarioBusqueda b);
#endif //LAB_05_2024_2_P1_FUNCIONES_H
