//
// Created by Ivan Piero Baltazar on 15/05/2026.
//

#ifndef LAB_02_2024_1_P2_FUNCIONES_H
#define LAB_02_2024_1_P2_FUNCIONES_H
#include <iostream>
#include <fstream>
#include <iomanip>

#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
using namespace std;

void cargarLista(Lista &lista,const char *nombreArchivo);

bool cumpleFragilidad(const ElementoPila &nuevo, const ElementoPila &cimaPila);
void mover_hanoi(int n, Pila &origen, Pila &destino, Pila &auxiliar);
void solucion(Lista &lista, Pila &pila_principal);
void eliminarUltimoNodo(Lista &lista);
#endif //LAB_02_2024_1_P2_FUNCIONES_H
