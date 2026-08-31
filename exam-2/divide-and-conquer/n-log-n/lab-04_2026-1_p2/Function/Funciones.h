//
// Created by Ivan Piero Baltazar on 8/07/2026.
//

#ifndef LAB_04_2026_1_P2_FUNCIONES_H
#define LAB_04_2026_1_P2_FUNCIONES_H
#include <iostream>
#include "..\EstructurasAdicionales/Resultado.h"
using namespace std;

void mergesort(Resultado arr[],int inicio,int fin);
void merge(Resultado arr[],int inicio,int mitad,int fin);
void imprimirCiudades(Resultado arr[],int inicio, int fin,int D1,int D2);
int busquedaBinariaInferior(Resultado arr[],int inicio,int fin,int D1);
int busquedaBinariaSuperior(Resultado arr[],int inicio,int fin,int D2);
void imprimirCiudadesAll(Resultado arr[],int size);

#endif //LAB_04_2026_1_P2_FUNCIONES_H
