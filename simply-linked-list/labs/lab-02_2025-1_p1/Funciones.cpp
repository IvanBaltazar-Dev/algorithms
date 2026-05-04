//
// Created by Ivan Piero Baltazar on 1/05/2026.
//

#include "Funciones.h"

#include <cstring>

void cargarDatos(Lista &l1, const char * nombreArchivo) {
    ifstream arch(nombreArchivo, ios::in);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    ElementoLista elemento{};

    while (true) {
        arch >> elemento.codigo;
        if (arch.eof()) break;
        arch.ignore(10,' ');
        arch.getline(elemento.nombre, 20,' ');
        arch.getline(elemento.equipo, 20,'\n');
        insertarAlFinal(l1,elemento);
    }
    arch.close();
}

void reordenaLista(Lista &l1, char tipoOrden[][10], int cantTipos) {
    NodoLista *inicioLista{};
    NodoLista *finalLista{};

    for (int i = 0; i < cantTipos; i++) {
        NodoLista *anterior = nullptr;
        NodoLista *curr = l1.inicio;
        int tipo = -1;
        if (strcmp(tipoOrden[i], "Par") == 0) {
            tipo = 2;
        } else if (strcmp(tipoOrden[i], "Impar") == 0) {
            tipo = 1;
        }
        while (curr != nullptr) {
            NodoLista *siguiente = curr->siguiente;

            //Busca los pares
            if (curr->elemento.codigo % tipo == 0) {
                //Es par
                //CONEXIONES
                if (anterior == nullptr) {
                    //esta inicio
                    l1.inicio = siguiente;
                } else {
                    anterior->siguiente = curr->siguiente;
                }
                //AISLAR
                curr->siguiente = nullptr;
                //INSERTAR
                if (inicioLista == nullptr) {
                    inicioLista = curr;
                    finalLista = curr;
                } else {
                    finalLista->siguiente = curr;
                    finalLista = curr;
                }
            } else {
                //Si no es par avanza el anterior
                anterior = curr;
            }
            //Siempre avanzamos
            curr = siguiente;
        }
    }
    if (inicioLista != nullptr) {
        l1.inicio = inicioLista;
    }else {
        cout << "Error al reordenar lista" << endl;
    }
}