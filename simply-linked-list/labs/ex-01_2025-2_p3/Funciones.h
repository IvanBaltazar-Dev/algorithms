//
// Created by Ivan Piero Baltazar on 1/05/2026.
//

#ifndef INC_2025_2_EX1_P3_FUNCIONES_H
#define INC_2025_2_EX1_P3_FUNCIONES_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include "BibliotecaLista/funcionesLista.h"
#include "BibliotecaLista/Lista.h"

using namespace std;

void cargarDatos(Lista &l1,const char* nombreArchivo);
void reordenaLista(Lista &l1, const char *ArrTipo, int cant_tipos);
void imprimirLista(NodoLista* inicioLista);


#endif //INC_2025_2_EX1_P3_FUNCIONES_H
