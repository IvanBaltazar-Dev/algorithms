//
// Created by aml on 16/05/2026.
//

#ifndef INC_20196388_LAB3_P1_FUNCION_H
#define INC_20196388_LAB3_P1_FUNCION_H
#include <iostream>
#include <iomanip>
#include <fstream>

#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"
using namespace std;

void cargarDatos(Lista &lista,const char *nombre);
void evaluacionSospechosos(Lista &lista,Lista &listaSospechosos);
//FUNCIONES REQUERIDAS
int contarOcurrencias(Lista lista,NodoLista *curr);
NodoLista*  verificaUsuario(Lista listaSospechosos, NodoLista *NodoActual);
void depuracionLista(Lista &lista,Lista listaSospechosos);
#endif //INC_20196388_LAB3_P1_FUNCION_H