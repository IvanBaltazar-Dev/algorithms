//
// Created by Ivan Piero Baltazar on 8/07/2026.
//

#ifndef EX_02_2025_2_P2_FUNCIONES_H
#define EX_02_2025_2_P2_FUNCIONES_H
#include <iostream>
#include "../EstructurasAdicionales/Resultado.h"
#include "../EstructurasAdicionales/Acumulacion.h"

using namespace std;

void mergesort(Resultado datos[],int inicio,int fin);
void merge(Resultado datos[],int inicio,int mitad,int fin);

int resolver(Resultado datos[],int inicio,int fin);
Acumulacion mayor(Acumulacion izquierda,Acumulacion derecha,Acumulacion cruzado);
Acumulacion maximoRiesgo(Resultado datos[],int inicio,int fin);
Acumulacion maximoRiesgoMerge(Resultado datos[],int inicio,int mitad,int fin);

#endif //EX_02_2025_2_P2_FUNCIONES_H
