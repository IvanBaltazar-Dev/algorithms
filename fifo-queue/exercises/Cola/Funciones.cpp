//
// Created by Ivan Piero Baltazar on 11/05/2026.
//

#include "Funciones.h"


void reordenarRec(Cola &cola) {
    if (esColaVacia(cola)) {
        return;
    }

    ElementoCola elemento = desencolar(cola);

    if (esColaVacia(cola)) {
        encolar(cola, elemento);
        return;
    }

    ElementoCola frente = desencolar(cola);

    if (elemento.codigo < frente.codigo) {
        encolar(cola, elemento);
        encolar(cola, frente);
    } else {
        encolar(cola, frente);
        insertarOrdenado(cola, elemento);
    }

}



