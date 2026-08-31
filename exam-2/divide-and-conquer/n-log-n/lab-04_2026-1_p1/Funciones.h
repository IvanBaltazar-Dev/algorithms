//
// Created by Ivan Piero Baltazar on 7/07/2026.
//

#ifndef LAB_04_2026_1_P1_FUNCIONES_H
#define LAB_04_2026_1_P1_FUNCIONES_H
#include <iostream>

#include "EstructurasAdicionales/Resultado.h"
#include "EstructurasAdicionales/Conteo.h"
#define N 8
using namespace std;

Resultado resolver(char *arr,int inicio, int fin);
Resultado combinar(Resultado izq, Resultado der);

void imprimirConteos(Resultado resultado);
Conteo conteoMayor(Resultado resultado);


#endif //LAB_04_2026_1_P1_FUNCIONES_H
