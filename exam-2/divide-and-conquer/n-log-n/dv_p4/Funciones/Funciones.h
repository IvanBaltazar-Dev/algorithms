//
// Created by Ivan Piero Baltazar on 8/07/2026.
//

#ifndef DV_P4_FUNCIONES_H
#define DV_P4_FUNCIONES_H
#include <iostream>
#include "..\EstructurasAdicionales/Resultado.h"
using namespace std;

Resultado mergeSort(int arr[], int inicio,int fin);
Resultado merge(int arr[],int inicio,int mitad,int fin);
Resultado maximo(Resultado a, Resultado b, Resultado c);

#endif //DV_P4_FUNCIONES_H
