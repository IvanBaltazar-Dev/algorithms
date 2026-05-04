//
// Created by Ivan Piero Baltazar on 27/04/2026.
//
#include "Funciones.h"

#include <cstring>

#include "fstream"

using namespace std;

void cargarLista(const char *nombre_arch, Lista &l1) {
    ifstream archivo(nombre_arch,ios::in);
    if (!archivo.is_open()) {
        cout<<"Error al abrir el archivo"<<endl;
        return;
    }
        ElementoLista elemento{};

    while (true) {

        archivo.ignore(10,'(');

        archivo >> elemento.codigo;
        if (archivo.eof()) break;

        archivo.ignore(10, '"');
        archivo.getline(elemento.nombre, 20, '"');

        archivo.ignore(10, '"');
        archivo.getline(elemento.posicion, 20, '"');

        archivo.ignore(10, '\n');

        insertarAlFinal(l1, elemento);

    }
    archivo.close();
}

void reordenaFormacion(Lista& l1, char formacion[][15], int cantPosiciones) {
    NodoLista* inicioLista = nullptr;
    NodoLista* finalLista = nullptr;

    for (int i = 0; i < cantPosiciones; i++) {
        NodoLista* anterior = nullptr;
        NodoLista* curr = l1.inicio;

        while (curr != nullptr) {
            NodoLista *siguiente = curr->siguiente;

            if (strcmp(curr->elemento.posicion, formacion[i]) == 0) {
                //PRIMERO CONEXIONES
                if (anterior == nullptr) {
                    l1.inicio = curr->siguiente;
                }else {
                    anterior->siguiente = curr->siguiente;
                }
                //DESCONECTA EL CURR
                curr->siguiente = nullptr;

                if (inicioLista == nullptr) {
                    inicioLista = curr;
                    finalLista = curr;
                }else {
                    finalLista->siguiente = curr;
                    finalLista = curr;
                }
                // OJO:
                // anterior NO avanza porque curr ya no esta en la lista pendiente

            }else { //Si el curr no se mueve anterior avanza
                // anterior solo avanza si curr se queda en la lista pendiente
                anterior = curr;
            }
            //AVANZA
            curr = siguiente;
        }
    }
    if (inicioLista != nullptr) {
        l1.inicio = inicioLista;
    }
    imprimirNodos(inicioLista);
}