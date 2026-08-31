//
// Created by Administrador on 19/06/2026.
//

#ifndef LAB_03_2022_1_P2_FUNCIONES_H
#define LAB_03_2022_1_P2_FUNCIONES_H
#include <iostream>
#include <iomanip>
#include <fstream>
#define N 7
#define M 10
using namespace std;

int resuelvePotencia(int matrix[M][N], int fila, int columna,int &colImpacto);
int resuelvePotenciaColumna(int matrix[M][N], int inicioFila,int finFila, int columna,int &colImpacto);
int buscarPicoColumna(int matrix[M][N],int inicioFila,int inicio,int fin);
int resuelveFila(int matrix[M][N], int inicioFila, int finFila,int colImpacto);
void imprimirMatriz(int matrix[M][N],int inicioFila, int finFila, int columnas);
void imprimeFila(int matrix[M][N],int inicioFila, int inicioColumna, int finColumna);
#endif //LAB_03_2022_1_P2_FUNCIONES_H
