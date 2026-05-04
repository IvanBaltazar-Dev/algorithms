//
// Created by Ivan Piero Baltazar on 1/05/2026.
//

#ifndef INC_2025_1_LAB_02_P1_FUNCIONES_H
#define INC_2025_1_LAB_02_P1_FUNCIONES_H
#include <iostream>
#include <fstream>
#include <iomanip>

#include "BibliotecaLista/funcionesLista.h"
#include "BibliotecaLista/Lista.h"

using namespace std;

void cargarDatos(Lista &l1, const char * nombreArchivo);
void reordenaLista(Lista &l1, char tipoOrden[][10],int cantTipos);
void imprimirLista(NodoLista* inicioLista);

#endif //INC_2025_1_LAB_02_P1_FUNCIONES_H
