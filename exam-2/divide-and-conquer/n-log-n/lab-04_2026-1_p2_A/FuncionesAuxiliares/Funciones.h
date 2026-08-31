//
// Created by Ivan Piero Baltazar on 8/07/2026.
//

#ifndef LAB_04_2026_1_P2_A_FUNCIONES_H
#define LAB_04_2026_1_P2_A_FUNCIONES_H
#include <iostream>
#include "..\EstructurasAdicionales/Resultado.h"
using namespace std;

void imprimirCuidadesAll(Resultado cuidades[],int size);
void mergesort(Resultado cuidades[],int inicio,int fin);
void merge(Resultado cuidades[],int inicio,int mitad,int fin);


#endif //LAB_04_2026_1_P2_A_FUNCIONES_H
