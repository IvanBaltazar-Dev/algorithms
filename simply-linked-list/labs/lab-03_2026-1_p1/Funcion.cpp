//
// Created by aml on 16/05/2026.
//

#include "Funcion.h"

void cargarDatos(Lista &lista, const char *nombre) {

    ifstream archivo(nombre, ios::in);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    char c;
    ElementoLista elemento{};
    while (true) {
        archivo >> c;
        archivo >> elemento.codigo;
        if (archivo.eof()) break;
        insertarAlFinal(lista, elemento);
    }
    archivo.close();
}

void evaluacionSospechosos(Lista &lista,Lista &listaSospechosos) {
    NodoLista *curr = lista.inicio;

    while (curr != nullptr) {
        int num_ocurrencias = contarOcurrencias(lista,curr);
        NodoLista *usuario_registrado{};
        if (num_ocurrencias >= 3) {
            usuario_registrado = verificaUsuario(listaSospechosos,curr);
        }
        if (usuario_registrado == nullptr && num_ocurrencias >= 3) {
            ElementoLista elemento{};
            elemento.codigo = curr->elemento.codigo;
            insertarAlFinal(listaSospechosos,elemento);
        }
        // cout << "El usuario " << curr->elemento.codigo <<" tuvo "<< num_ocurrencias <<" intentos fallidos." << endl;
        curr = curr->siguiente;
    }
}

int contarOcurrencias(Lista lista,NodoLista *NodoActual) {
    int result = 0;
    NodoLista *curr = lista.inicio;
    while (curr != nullptr) {
        if (curr->elemento.codigo == NodoActual->elemento.codigo) {
            result++;
        }
        curr = curr->siguiente;
    }
    return result;
}

NodoLista* verificaUsuario(Lista listaSospechosos, NodoLista *NodoActual) {
    NodoLista *curr = listaSospechosos.inicio;
    while (curr != nullptr) {
        if (curr->elemento.codigo == NodoActual->elemento.codigo) {
            return curr;
        }
        curr = curr->siguiente;
    }
    return nullptr;
}

void depuracionLista(Lista &lista, Lista listaSospechosos) {
    //DEPURAMOS LOS REPETIDOS PARA LIMPIAR LA LISTA
    if (lista.inicio != nullptr) {
        NodoLista *curr = lista.inicio;
        while (curr != nullptr) {
            NodoLista *busqueda = curr;
            //REVISAMOS LOS NODOS SIGUIENTES
            while (busqueda->siguiente != nullptr) {
                if (curr->elemento.codigo == busqueda->siguiente->elemento.codigo) {
                    NodoLista *duplicado = busqueda->siguiente;
                    //CONEXIONES
                    busqueda->siguiente = duplicado->siguiente;
                    //ACTUALIZACION (LIBERAR MEMORIA)
                    delete duplicado;
                } else {
                    busqueda = busqueda->siguiente;
                }
            }
            curr = curr->siguiente;
        }
    }

    // PASO 2: Eliminar sospechosos
    NodoLista *sospechoso = listaSospechosos.inicio;
    while (sospechoso != nullptr) {
        NodoLista *usuario_registrado = verificaUsuario(lista, sospechoso);
        if (usuario_registrado != nullptr) {
            eliminaNodo(lista, usuario_registrado->elemento);
        }
        sospechoso = sospechoso->siguiente;
    }
}
