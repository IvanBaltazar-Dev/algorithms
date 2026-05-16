//
// Created by Ivan Piero Baltazar on 15/05/2026.
//

#include "Funciones.h"

void cargarLista(Lista &lista,const char *nombreArchivo) {
    ifstream arch(nombreArchivo,ios::in);
    if (!arch.is_open()) {
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }

    ElementoLista elemento{};
    while (true) {
        arch >> elemento.calidad;
        if (arch.eof()) break;
        arch >> elemento.peso;
        insertarAlInicio(lista,elemento);
    }
    arch.close();
}

void solucion(Lista &lista, Pila &pila_principal) {
    // Definición de las 3 pilas auxiliares requeridas por la empresa
    Pila aux1{};
    Pila aux2{};
    Pila aux3{};

    // Dos variables de tipo entero que representan la capacidad/carga de los brazos mecánicos
    int brazo_receptor_peso = 0;
    int brazo_asistente_peso = 0;

    NodoLista *ultimo_nodo = nullptr;
    ElementoPila elemento_pila{};

    while (!esListaVacia(lista)) {
        // 1. El primer brazo recibe el producto desde el final de la faja transportadora
        ultimo_nodo = obtenerUltimoNodo(lista);
        elemento_pila.calidad = ultimo_nodo->elemento.calidad;
        elemento_pila.peso = ultimo_nodo->elemento.peso;

        brazo_receptor_peso = elemento_pila.peso; // Monitoreo del peso en el brazo de recepción
        eliminarUltimoNodo(lista);

        // Contador de elementos temporalmente desplazados
        int elementos_movidos = 0;

        // 2. Desocupar la pila principal empleando Hanói para no violar la fragilidad
        while (!esPilaVacia(pila_principal) && !cumpleFragilidad(elemento_pila, cima(pila_principal))) {
            // El segundo brazo asiste registrando el peso del elemento que estorba en la cima
            brazo_asistente_peso = cima(pila_principal).peso;

            // Desplazamos los elementos ordenados acumulados en aux1 hacia aux2 usando aux3
            mover_hanoi(elementos_movidos, aux1, aux2, aux3);

            // Retiramos el elemento limitante de la pila principal y lo guardamos en aux1
            ElementoPila temp = desapilar(pila_principal);
            apilar(aux1, temp);

            // Regresamos el bloque guardado en aux2 de vuelta a aux1 usando aux3
            mover_hanoi(elementos_movidos, aux2, aux1, aux3);

            elementos_movidos++;
        }

        // 3. El brazo receptor deposita el producto de forma segura en la pila principal
        apilar(pila_principal, elemento_pila);
        brazo_receptor_peso = 0; // Brazo liberado

        // 4. Regresar todos los elementos almacenados en aux1 a la pila principal mediante Hanói
        mover_hanoi(elementos_movidos, aux1, pila_principal, aux2);
    }
}

// Regla de fragilidad: El nuevo elemento solo puede ir encima si es de MENOR peso.
// Si el peso es idéntico, se emplea la calidad como criterio de desempate (menor calidad arriba).
bool cumpleFragilidad(const ElementoPila &nuevo, const ElementoPila &cimaPila) {
    if (nuevo.peso < cimaPila.peso) return true;
    if (nuevo.peso == cimaPila.peso && nuevo.calidad < cimaPila.calidad) return true;
    return false;
}

// Mueve 'n' elementos de una pila origen a una destino usando una auxiliar, respetando la fragilidad
void mover_hanoi(int n, Pila &origen, Pila &destino, Pila &auxiliar) {
    if (n == 0) return;
    mover_hanoi(n - 1, origen, auxiliar, destino);
    ElementoPila e = desapilar(origen);
    apilar(destino, e);
    mover_hanoi(n - 1, auxiliar, destino, origen);
}

void eliminarUltimoNodo(Lista &lista) {
    if (lista.inicio == nullptr) return;
    if (lista.inicio->siguiente == nullptr) {
        delete lista.inicio;
        lista.inicio = nullptr;
        return;
    }
    NodoLista* aux = lista.inicio;
    while (aux->siguiente->siguiente != nullptr) {
        aux = aux->siguiente;
    }
    delete aux->siguiente;
    aux->siguiente = nullptr;
}