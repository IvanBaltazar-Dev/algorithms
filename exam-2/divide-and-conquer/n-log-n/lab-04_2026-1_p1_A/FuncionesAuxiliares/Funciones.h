//
// Created by Ivan Piero Baltazar on 8/07/2026.
//

#ifndef LAB_04_2026_1_P1_A_FUNCIONES_H
#define LAB_04_2026_1_P1_A_FUNCIONES_H
#include <iostream>
#include "..\EstructurasAuxiliares/Resultado.h"

using namespace std;

Resultado mergesort(char almacen[],int inicio, int fin);
Resultado merge(Resultado izquierda, Resultado derecha);

Conteo mayor(Resultado conteos);


#endif //LAB_04_2026_1_P1_A_FUNCIONES_H
