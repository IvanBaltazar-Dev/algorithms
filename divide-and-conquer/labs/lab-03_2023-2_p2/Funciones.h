//
// Created by Administrador on 19/06/2026.
//

#ifndef LAB_03_2023_2_P2_FUNCIONES_H
#define LAB_03_2023_2_P2_FUNCIONES_H
#include <iostream>
#include <iomanip>

using namespace std;

#define M 8
#define N 11

#define P 5
void resuelveLetras(char arr[M][N], int filas, int columnas);
void resuelveColumnas(char arr[M][N], int inicioFilas,int finFilas, int columnas);
void buscaLetra(char arr[M][N], int inicioFila,int inicioColumna, int finColumna);
void resuelveAsientos(int matrix[M][P], int filas, int columnas);
void resuelveColumnas(int matrix[M][P], int inicioFila, int finFila, int columnas);
int resuelvePico(int matrix[M][P],int fila,int inicioColumna,int finColumna);
#endif //LAB_03_2023_2_P2_FUNCIONES_H
