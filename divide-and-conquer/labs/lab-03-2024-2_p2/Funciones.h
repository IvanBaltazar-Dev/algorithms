//
// Created by Administrador on 19/06/2026.
//

#ifndef LAB_03_2024_2_P2_FUNCIONES_H
#define LAB_03_2024_2_P2_FUNCIONES_H
#include <iostream>
#include <iomanip>
#define N 10
using namespace std;

int resuelveMatrix(int matrix[N][N], int filas, int columnas, int &colMax,int &filMax);
int resuelve_columna(int matrix[N][N], int inicioFila, int finFila,int columnas,  int &colMax, int &filaMax);
int resuelvePico(int matrix[N][N],int fila,int inicioColumna,int finColumna, int &colMax);


int resuelveMayorEstrato(int matrix[N][N], int inicioFila, int finFila, int columnas);
int conteoEstrato(int matrix[N][N],int fila,int inicioColumna,int finColumna);
void imprimeEstratosMaximos(int matrix[N][N],int inicioFila,int finFila,int columnas,int mayorEstrato);
#endif //LAB_03_2024_2_P2_FUNCIONES_H
