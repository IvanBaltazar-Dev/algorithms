//
// Created by Administrador on 20/06/2026.
//

#ifndef EX_02_2025_2_P2_FUNCIONES_H
#define EX_02_2025_2_P2_FUNCIONES_H
#include <iostream>
#include <iomanip>
#define N 9

using namespace std;

int resolverRotacion(int matrix[N][2],int inicioFila, int finFila);
int transformacionIndice(int indice,int posInicio, int total);
int resuelveAcumulacion(int matrix[N][2], int inicioFila, int finFila, int &minIndex,int &maxIndex);
int sumaCruzada(int matrix[8][2], int inicioFila,int mitad,int finFila,int &inicioCruzado,int &finCruzado);
int mayor(int a, int b);
int mayorTres(int a,int b,int c);
#endif //EX_02_2025_2_P2_FUNCIONES_H
