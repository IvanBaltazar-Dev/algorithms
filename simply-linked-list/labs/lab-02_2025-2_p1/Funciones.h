//
// Created by Ivan Piero Baltazar on 27/04/2026.
//

#ifndef LISTASIMPLEMENTEENLAZADA_FUNCIONES_H
#define LISTASIMPLEMENTEENLAZADA_FUNCIONES_H

#include <iostream>
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"

void cargarLista(const char* nombre_arch,Lista &l1);
void reordenaFormacion(Lista& l1, char formacion[][15], int cantPosiciones);
#endif //LISTASIMPLEMENTEENLAZADA_FUNCIONES_H