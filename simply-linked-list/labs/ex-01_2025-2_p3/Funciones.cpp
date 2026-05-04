//
// Created by Ivan Piero Baltazar on 1/05/2026.
//

#include "Funciones.h"

void cargarDatos(Lista &l1, const char *nombreArchivo) {
    ifstream arch(nombreArchivo, ios::in);
    if (!arch.is_open()) {
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
    ElementoLista elemento{};

    while (true) {
        arch >> elemento.codigo;
        if (arch.eof()) break;

        arch.ignore(10,',');
        arch >> elemento.tipo;

        arch.ignore(10,'\n');

        insertarAlFinal(l1,elemento);
    }
    arch.close();
}

void reordenaLista(Lista &l1, const char *ArrTipo, int cant_tipos) {
    NodoLista* inicioLista;
    NodoLista* finalLista;
    int i = 0;
    while (l1.inicio != nullptr) {
        NodoLista* anterior = nullptr;
        NodoLista* curr = l1.inicio;
        bool encuentra = false;
        // imprimir(l1);
        while (curr != nullptr) {
            NodoLista* siguiente = curr->siguiente;

            if (curr->elemento.tipo == ArrTipo[i]) {
                //Elemento encontrado
                encuentra = true;
                if (anterior == nullptr) {
                    l1.inicio = curr->siguiente;
                }else {
                    anterior->siguiente = curr->siguiente;
                }
                //Aislar
                curr->siguiente = nullptr;
                //Insersión
                if (inicioLista == nullptr) {
                    inicioLista = curr;
                    finalLista = curr;
                }else {
                    finalLista->siguiente = curr;
                    finalLista = curr;
                }
                i = (i+1) % cant_tipos;
                // imprimirLista(inicioLista);
                break;
            }else { //SI NO SE MUEVE
                anterior = curr;
            }
            curr = siguiente;
        }
        if (!encuentra) {
            i = (i+1) % cant_tipos;
        }
    }
    if (inicioLista != nullptr) {
        l1.inicio = inicioLista;
    }else {
        cout<<"La lista no se pudo reordenar"<<endl;
    }
    // imprimir(l1);
}

void imprimirLista(NodoLista* inicioLista) {
    if (inicioLista == nullptr) {
        cout << "La lista esta vacia no se puede mostrar" << endl;
    } else {
        struct NodoLista * recorrido = inicioLista;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca las comas despuÃ©s de la cabeza*/
            if ( not estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento.codigo;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}