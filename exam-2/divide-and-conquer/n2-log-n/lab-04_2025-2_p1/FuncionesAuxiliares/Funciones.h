//
// Created by Ivan Piero Baltazar on 9/07/2026.
//

#ifndef LAB_04_2025_2_P1_FUNCIONES_H
#define LAB_04_2025_2_P1_FUNCIONES_H
#include <iostream>
#include "..\EstructurasAuxiliares/Conteo.h"
#include "..\EstructurasAuxiliares/Resultado.h"
#define N 6
using namespace std;

Resultado mergesort(string mutaciones[],int inicio,int fin);
Resultado merge(Resultado izquierda,Resultado derecha);

string encontrarFaltante(string fila[],int size);

#endif //LAB_04_2025_2_P1_FUNCIONES_H
