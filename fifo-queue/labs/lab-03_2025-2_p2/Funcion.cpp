//
// Created by Ivan Piero Baltazar on 15/05/2026.
//

#include "Funcion.h"

void iniciar_datos(Cola &cola, const char *nombreArch) {
    ifstream archivo(nombreArch,ios::in);
    if (!archivo.is_open()) {
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }

    ElementoCola elementoCola{};

    while (true) {
        archivo >> elementoCola.codigo;
        if (archivo.eof()) break;
        encolar(cola, elementoCola);
    }
    archivo.close();
}

bool reordena_datos(Cola &cola) {
    Pila pila{};
    construir(pila);

    int esperado = 1;
    ElementoPila elementoPila{};
    ElementoCola elementoCola{};
    while (!esColaVacia(cola)) {
        //VALIDAR VALORES DE LA PILA
        while (!esPilaVacia(pila) && pila.inicio->elemento.numero == esperado) {
            elementoPila = desapilar(pila);
            esperado++;
        }

        elementoCola = desencolar(cola);

        if (elementoCola.codigo == esperado) {
            esperado++;
        }else {
            if (!esPilaVacia(pila)) {
                if (pila.inicio->elemento.numero <= elementoCola.codigo) {
                    return false;
                }
            }
            elementoPila.numero = elementoCola.codigo;
            apilar(pila, elementoPila);
        }

    }

    while (!esPilaVacia(pila) && pila.inicio->elemento.numero == esperado) {
        elementoPila = desapilar(pila);
        esperado++;
    }

    if (esPilaVacia(pila)) {
        destruir(pila);
        return true;
    }
    destruir(pila);
    return false;
}

