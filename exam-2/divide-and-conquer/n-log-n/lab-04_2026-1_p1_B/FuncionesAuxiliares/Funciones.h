//
// Created by Ivan Piero Baltazar on 10/07/2026.
//

#ifndef LAB_04_2026_1_P1_B_FUNCIONES_H
#define LAB_04_2026_1_P1_B_FUNCIONES_H
#include <iostream>
#include "..\EstructurasAuxiliares/Datos.h"

using namespace std;

Datos mergesort(char almacen[],int inicio,int fin);
Datos merge(Datos izquierda,Datos derecha);
Conteo encontrarMayor(Datos resultado);


#endif //LAB_04_2026_1_P1_B_FUNCIONES_H
