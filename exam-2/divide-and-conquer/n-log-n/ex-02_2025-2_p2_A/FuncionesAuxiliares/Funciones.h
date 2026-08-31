//
// Created by Ivan Piero Baltazar on 10/07/2026.
//

#ifndef EX_02_2025_2_P2_A_FUNCIONES_H
#define EX_02_2025_2_P2_A_FUNCIONES_H
#include <iostream>

#include "..\EstructurasAuxiliares/Resultado.h"

using namespace std;

int resolverRotacion(Resultado datos[],int inicio,int fin);
void mergesort(Resultado datos[],int inicio,int fin);
void merge(Resultado datos[],int inicio,int mitad,int fin);
int conteo(Resultado datos[],int inicio,int fin);
int conteoCruzado(Resultado datos[],int inicio,int mitad, int fin);


#endif //EX_02_2025_2_P2_A_FUNCIONES_H
