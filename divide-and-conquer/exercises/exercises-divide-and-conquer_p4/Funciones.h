//
// Created by Administrador on 20/06/2026.
//

#ifndef EXERCISES_DIVIDE_AND_CONQUER_P4_FUNCIONES_H
#define EXERCISES_DIVIDE_AND_CONQUER_P4_FUNCIONES_H
#include <iostream>
#include <iomanip>
#define N 8
using namespace std;

int sumaMaxima(int *arr,int inicio,int fin,int &iniMax, int &finMax);
int sumaCruzada(int *arr,int inicio,int mitad,int fin,int &iniMax,int &finMax);
int mayorTres(int a, int b, int c);
int mayor(int a, int b);

#endif //EXERCISES_DIVIDE_AND_CONQUER_P4_FUNCIONES_H
