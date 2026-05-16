//
// Created by Ivan Piero Baltazar on 15/05/2026.
//

#ifndef EX_01_2025_2_P5_FUNCIONES_H
#define EX_01_2025_2_P5_FUNCIONES_H

#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"

#include <iostream>
#include <fstream>
#include <iostream>

using namespace std;

void solucion(Cola &cola,const char* nombre);
void encolar(Cola& cola, ElementoCola elemento, NodoCola* last);
void imprimir(const struct Cola & colaTAD, int prioridad,ofstream &archRep);
void imprimir(const struct Cola & colaTAD, int prioridad);

void operacionAtencion(Cola &cola, NodoCola* &last1, ofstream &archRep, int cant_atencion);
void operacionLlegada(Cola & cola, ElementoCola elemento, NodoCola * &last1);
void operacionImprime(const Cola cola,ofstream &archRep);

#endif //EX_01_2025_2_P5_FUNCIONES_H
