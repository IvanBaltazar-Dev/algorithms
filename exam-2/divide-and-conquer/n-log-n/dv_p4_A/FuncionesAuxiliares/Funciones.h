//
// Created by Ivan Piero Baltazar on 8/07/2026.
//

#ifndef DV_P4_A_FUNCIONES_H
#define DV_P4_A_FUNCIONES_H
#include <iostream>
#include "../EstructurasAuxiliares/Resultado.h"
using namespace std;

Resultado mergesort(int arr[],int inicio,int fin);
Resultado merge(int arr[],int inicio,int mitad,int fin);
Resultado mayor(Resultado izquierda,Resultado derecha,Resultado cruzado);


#endif //DV_P4_A_FUNCIONES_H
